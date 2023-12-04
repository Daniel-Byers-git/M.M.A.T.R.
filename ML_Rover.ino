// ---------------------------------------------------------
// Includes
  #include "diff_control.h"   // Header for driving Rover
  #include <HCSR04.h>         // Header for Ultrasonic Sensors
  #include <SoftwareSerial.h> // Header for non Com port Serial
// ---------------------------------------------------------

// ---------------------------------------------------------
// Module ML Models
  #include "nomodule.h"
  #include "lightfollow.h"
  #include "tiltstop.h"
// ---------------------------------------------------------


// ---------------------------------------------------------
// Input Array to Machine Learning Model
  float Sensor_Data_Arr[9]{};
// ---------------------------------------------------------

// ---------------------------------------------------------
// Rover Variables
  HCSR04 US(8, new int[5]{52, 50, 48, 46, 44}, 5); // Setup Ultrasonic sensors
  diff_con RoverDD(24, 25, 26, 27, 28);            // Setup Differential Drive for rover                
  bool Module_Present{};
  bool Module_Unknown{}; 
  bool Training{};
// ---------------------------------------------------------

// ---------------------------------------------------------
// Check if a module is Connected
  bool Module_Connected()
  {
    for(int i = 34; i < 38 ; i++)
    {
      unsigned long pulse_time = pulseIn(i,LOW,4000);
      if(pulse_time > 0)
      {
        return true;
      }
    }
    return false;
  }
// ---------------------------------------------------------

// ---------------------------------------------------------
// Get Module Name
  String Module_Name = "nomodule";
  void Get_Module_Name()
  {
    Module_Name = "";
    Serial2.flush();
    Serial2.print('N');
    while(!(Serial2.available() > 0)){delay(20);}
    Module_Name = Serial2.readString();
  }
// ---------------------------------------------------------

// ---------------------------------------------------------
// Manual Mode? (Is bluetooth connected?)
  const int HC05_STATE_PIN = 12;
  bool Manual_Mode()
  {
    return digitalRead(HC05_STATE_PIN);
  }
// ---------------------------------------------------------

// ---------------------------------------------------------
// Function to populate Ultrasonic Sensor Distances into "Sensor_Data_Arr"
  void Get_US_Dists()
  {
    for(int i = 0; i < 5; i++)
    {
      Sensor_Data_Arr[i] = int(US.dist(i));
      delay(30);
    }
  }
// ---------------------------------------------------------

// ---------------------------------------------------------
// Function to populate Module Data into "Sensor_Data_Arr"
  void Get_Module_Data()
  {
    int x = 34;
    for(int i = 5; i < 9 ; i++)
    {
      Sensor_Data_Arr[i] = pulseIn(x,LOW,4000);
      if(Module_Name == "heatescape" && x > 34)
      {
        break;
      }
      x++;
    }
  }
// ---------------------------------------------------------

// ---------------------------------------------------------
// Receive Command from Python
  String Command{};
  int Comm_bytes{};
  void Receive_Command()
  {
    String temp{};
    temp = Serial1.readString();
    Command = temp[temp.length() - 1]; // Filter command spamming to only receive the last command in buffer
  }
// ---------------------------------------------------------

// ---------------------------------------------------------
// Send Data to Python
  void Send_Data()
  {
    String Data{};
    for(int i = 0; i < 9; i++)
    {
      Data += Sensor_Data_Arr[i];
      if(i<8)
      {
        Data += ',';
      }
    }
    Data += ':';
    Data += Command;
    Serial1.println(Data); // Send Data string to PC
  }
// ---------------------------------------------------------


void setup()
{
  Serial.begin(9600);                     // To Computer for monitoring
  Serial1.begin(9600);                    // To Bluetooth
  Serial2.begin(9600);                    // To Module

  // Setup Pins for input from Modules
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);

  // Set variables
  Module_Present = false;
  Module_Unknown = true;
  Training = false;
  Command = '3';
}

void loop() 
{
  // Check for a module connection. if a new module is connected, get the name of the module.
  // If no module is connected, set the module name to "nomodule".
  Module_Present = Module_Connected();
  if(Module_Present && Module_Unknown)
  {
    Get_Module_Name();
    Module_Unknown = false;  // We now know what module is connected
  }
  else if(!(Module_Present))
  {
    Module_Name = "nomodule";
    Module_Unknown = true;
  }

  // Check if a PC is connected: Yes == Manual Mode, No == Auto mode
  if(Manual_Mode())
  {
    // Manual Mode
    while(!(Serial1.available() > 0)){delay(10);} // Wait for a command
    Receive_Command();
    // Execute Command
    if(Command == "0" || Command == "1" || Command == "2" || Command == "3" || Command == "4")
    { 
      if(Training)
      {   
        Get_US_Dists();
        Get_Module_Data();
        Send_Data();
      }
      RoverDD.set_dir_manual(Command);
      //Sensor_Data_Arr[9] = RoverDD.last_dir;
    }
    else if(Command == "5")
    {
      Training = !Training;
    }
    else if(Command == "7")
    {
      delay(50);
      Serial1.println(Module_Name);
      RoverDD.stop();
    }
  }
  else
  {
    // Auto Mode
    Get_US_Dists();
    Get_Module_Data();
    // *** DRIVE AUTO ***
    if(Module_Name == "nomodule")
    {
      RoverDD.set_dir_auto(nomodule.predict(Sensor_Data_Arr));
    }
    else if(Module_Name == "lightfollow")
    {
      RoverDD.set_dir_auto(lightfollow.predict(Sensor_Data_Arr));
    }
    else if(Module_Name == "tiltstop")
    {
      RoverDD.set_dir_auto(tiltstop.predict(Sensor_Data_Arr));
    }
    //Sensor_Data_Arr[9] = RoverDD.last_dir;
  }
  delay(10);
}