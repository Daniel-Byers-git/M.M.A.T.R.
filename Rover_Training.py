# Control Rover over bluetooth
# More focus on the Arduino being very effecient and having minimal Python code in control loop

import serial
import time
from pytimedinput import timedKey
import customtkinter as ctk
import random
from pprint import pprint
from sklearn.model_selection import train_test_split
import os
try:
    from everywhereml.sklearn.ensemble import RandomForestClassifier
except Exception as e:
    print("Failed to import everywhereml")
    print(e)
    exit()

# ------------------- Filter --------------------------
def remove_empty_strings(string):
    return string != ""
# ------------------- End Filter ----------------------

# ------------------- Command Format ------------------
def formatted_command_for_ml(command):
    switcher = {
        'w': '0',
        'a': '1',
        'd': '2',
        's': '3',
        'x': '4',
        't': '5',
        'y': '6'
    }
    return switcher.get(command, '3')
# ------------------- End Command Format --------------

# ------------------- ML Model Files ------------------
def create_ml_model_files():
    global filtered_arduino_data
    global module_name
    global pad_val
    global ml_prompt
    global begin_ml_training
    global cancel_ml_training
    global noise_injection_prompt
    global noise_injection_label
    global retrain_or_add_data
    global retrain_or_add_data_res

    retrain_res = retrain_or_add_data_res.get("0.0", "end").strip().lower()

    # open data file for module      
    past_data = []
    X_past = []
    y_past = []
    past_data_file_path = "c:/Users/getdo/Desktop/Fall Semester 2023/Senior Project ML LIDAR Rover/ML_Rover_Final/ML_Rover/" + module_name + "_data.txt"
    if os.path.exists(past_data_file_path) and retrain_res == 'a':
        training_data_file_read = open(module_name + "_data.txt", "r")
        # Get user response for retrain or add data 
        past_data = training_data_file_read.readlines()
        training_data_file_read.close() 
        for line in past_data:
            if line.strip() != '':
                X_past.append(line.strip().split(':')[0].split(','))
                y_past.append(line.strip().split(':')[1])

    # Get X and y from Data
    X = []
    y = []
    for i in range(len(filtered_arduino_data)):
        X_y = filtered_arduino_data[i].strip().split(':')
        X.append(X_y[0].split(','))
        y.append(X_y[1])

    # Get noise injection indicies from user
    noise_injection_indicies = [0,1,2,3,4]
    module_indicies = noise_injection_prompt.get("0.0", "end").strip().split(',')
    if module_indicies != ['']:
        noise_injection_indicies.append(int(i-1) for i in module_indicies)

    # Extend and Inject noise into Data
    ni_mult = 4 # Number of times to extend Data (new_size = len(Data)*(2^ni_mult))
    for i in range(ni_mult):
        X.extend(X)
        y.extend(y)

    # Inject noise into X
    X_noise_arr = []
    X_noise_line = []
    val = 0
    app_val = 0
    for row in range(len(X)):
        for column in range(len(X[row])):
            val = float(X[row][column])
            app_val = val + val*random.uniform(-.1,.1) if column in noise_injection_indicies else val
            X_noise_line.append(str(int(app_val)))
        X_noise_arr.append(X_noise_line)
        X_noise_line = []


    # Add back in past data for training if user chose to add data
    if retrain_res == 'a':
        X_noise_arr.extend(X_past)
        y.extend(y_past)

    # Save the total training data to a text file to then train ML model on
    training_data_file_write = open(module_name + "_data.txt", "w")
    if retrain_res == 'a':
        filtered_arduino_data.extend(past_data)
    for line in filtered_arduino_data:
        training_data_file_write.write(line + "\n")
    training_data_file_write.close()

    # Split data into a training set and a testing set
    X_train, X_test, y_train, y_test = train_test_split(X_noise_arr, y, test_size=0.2, random_state=42)
    dummy_data_x = ['0,0,0,0,0,0,0,0,0',
                    '0,0,0,0,0,0,0,0,0',
                    '0,0,0,0,0,0,0,0,0',
                    '0,0,0,0,0,0,0,0,0',
                    '0,0,0,0,0,0,0,0,0']
    dummy_data_y = ['0','1','2','3','4']
    for line in dummy_data_x:
        X_train.append(line.split(','))
        X_test.append(line.split(','))
    for line in dummy_data_y:
        y_train.append(line)
        y_test.append(line)
    
    # Create a Random Forest Classifier
    clf = RandomForestClassifier(n_estimators=25)


    # Fit the ML Model
    clf.fit(X_train, y_train)

    # Test the ML Model
    ml_score = clf.score(X_test, y_test)

    # Create and then change lines in Classifier file to include nodule name to avoid redefining class name in Arduino code
    default_Rand_For_Class = clf.to_arduino(instance_name=module_name)
    indicies_for_change = [i for i in range(len(default_Rand_For_Class)) if default_Rand_For_Class.startswith("RandomForestClassifier", i)]
    module_Rand_For_Class = default_Rand_For_Class[:indicies_for_change[2]] + module_name + default_Rand_For_Class[indicies_for_change[2]:indicies_for_change[3]] + module_name + default_Rand_For_Class[indicies_for_change[3]:]
    Module_ML = open(module_name + ".h","w")
    Module_ML.write(module_Rand_For_Class)
    Module_ML.close()

    # Setup UI to show results of ML model training
    ml_prompt.destroy()
    begin_ml_training.destroy()
    cancel_ml_training.destroy()
    noise_injection_prompt.destroy()
    noise_injection_label.destroy()
    retrain_or_add_data.destroy()
    retrain_or_add_data_res.destroy()

    training_complete = ctk.CTkLabel(UI, text="Training Complete", font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80)
    training_complete.grid(row=1, column=0, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

    ml_score_message = "Model Test Score: " + str(ml_score)
    model_test_score = ctk.CTkLabel(UI, text=ml_score_message, font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80)
    model_test_score.grid(row=1, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

    next_steps = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=380, height=180)
    next_steps.grid(row=2, column=0, columnspan=2, rowspan=2, pady=pad_val, padx = pad_val, sticky = "nsew")
    next_steps.insert("0.0","Next Steps for new Modules:\n1. Open Arduino IDE\n2. Copy and Paste \" #include \"" + module_name + ".h\"\" to the top of ML_Rover.ino\n3. Under \"// *** DRIVE AUTO ***\" at the bottom of ML_Rover.ino, copy and paste the follwing,\nelse if(Module_Name == \"" + module_name + "\")\n{RoverDD.set_dir_Auto(" + module_name + ".predict(Sensor_Data_Arr));}")

    exit_button = ctk.CTkButton(UI, text="Exit Rover Trainer", font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80, command=UI.destroy)
    exit_button.grid(row=3, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")
# ------------------- End ML Model Files --------------

# ------------------- Control Loop --------------------
def control_loop():
    global arduino
    global filtered_arduino_data
    global module_name
    global pad_val
    global ml_prompt
    global begin_ml_training
    global cancel_ml_training
    global noise_injection_prompt
    global noise_injection_label
    global retrain_or_add_data
    global retrain_or_add_data_res

    # Displays total number of data collections during training session
    data_collected = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=380, height=80)
    data_collected.grid(row=1, column=2, columnspan=2, rowspan=1, pady=pad_val, padx =pad_val, sticky = "nsew")
    data_collected.insert("0.0", "Data Collected: 0")

    # Displays last data string collected from Arduino
    last_data_collected = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=380, height=80)
    last_data_collected.grid(row=2, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")
    last_data_collected.insert("0.0", "Data: ")

    arduino_data = []
    start_training_session.destroy()
    controls.delete("0.0", "end")
    controls.insert("0.0", "Controls:\nW - Forward\nA - Left\nD - Right\nS - Stop\nX - Reverse\nT - Pause/Resume Training\nY - Stop Training Session\n\nEnter rover commands\ninto python terminal")
    spacer = ctk.CTkLabel(UI, text="", corner_radius=10, fg_color="transparent", width=380, height=80)
    spacer.grid(row=3, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")
    UI.update()
    # Setup COM port to communicate with HC05
    try:
        arduino = serial.Serial(port = 'COM3', baudrate = 9600, 
                                bytesize = 8, timeout = 1, 
                                stopbits = serial.STOPBITS_ONE)
    except Exception as e:
        print("Failed to connect to Arduino")
        print(e)
        exit()
    else:
        # Flush input buffer from Arduino
        bluetooth_status.delete("0.0", "end")
        bluetooth_status.insert("0.0", "Connected to\nRover")
        UI.update()
        arduino.flushInput();

    # Begin Command Loop
    training = False

    while(True):
        #if(arduino.isOpen() == False):
        #    bluetooth_status.delete("0.0", "end")
        #    bluetooth_status.insert("0.0", "Not\nConnected")
        #    UI.update()
        #    time.sleep(5)
        #    exit

        # Get user command
        command, timed_out = timedKey(prompt = 'Command: ', timeout = -1, allowCharacters="wasdtyx")
        command = formatted_command_for_ml(command)

        # Execute command
        if(command in ['0', '1', '2', '3', '4']):
            # Send command to Arduino
            arduino.flushOutput()
            arduino.write(bytes(command, 'UTF-8'))
            if(training):    
                # Get data from Arduino and append to list
                ard_data = arduino.readline().decode().strip()
                arduino_data.append(ard_data)
                data_collected.delete("0.0", "end")
                data_collected.insert("0.0", "Data Collected Total: " + str(len(arduino_data)))
                last_data_collected.delete("0.0", "end")
                last_data_collected.insert("0.0", "Data:\n" + ard_data)
            arduino.flushInput()
        elif(command == '5'):
            # Send Pause/Resume command to Arduino
            arduino.flushOutput()
            arduino.write(bytes(command, 'UTF-8'))
            # Start/Stop collecting data for ML model
            if(training):
                training = False
                training_state.delete("0.0", "end")
                training_state.insert("0.0", "Not\nTraining")
            else:
                training = True
                training_state.delete("0.0", "end")
                training_state.insert("0.0", "Training")
            arduino.flushInput()
        elif(command == '6'):
            # Send Stop command to Arduino
            time.sleep(.5)
            arduino.flushOutput()
            arduino.flushInput()
            arduino.write(bytes('7', 'UTF-8'))
            while(not arduino.in_waiting > 0):
                time.sleep(.05)
            module_name = arduino.readline().decode().strip()
            arduino.close()
            break
        UI.update()

    # Remove blanks in data due to spamming of commands
    filtered_arduino_data = list(filter(remove_empty_strings, arduino_data))

    # Setup UI for ML Model Training
    training_state.destroy()
    bluetooth_status.destroy()
    data_collected.destroy()
    last_data_collected.destroy()
    spacer.destroy()
    controls.destroy()

    # Show name of module being trained for
    module_name_label = ctk.CTkLabel(UI, text="Module Name:\n" + module_name, font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80)
    module_name_label.grid(row=0, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

    # ML Model Training Prompt
    ml_prompt = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=380, height=280)
    ml_prompt.grid(row=1, column=0, columnspan=2, rowspan=2, pady=pad_val, padx = pad_val, sticky = "nsew")
    ml_prompt.insert("0.0", "Begin Training Model:\nCreates two files in directory.\n1. A txt file named " + module_name + "_data.txt\n2. A C++ header file named " + module_name + ".h\n\nCancel Training Model:\nCloses program and does not create any files.")

    # Noise Injection Label
    noise_injection_label = ctk.CTkLabel(UI, text="Module Noise Injection\n Indices (CSV format)", font=("Arial", 15), corner_radius=10, fg_color="green", width=180, height=80)
    noise_injection_label.grid(row=1, column=2, columnspan=1, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

    # Noise Injection Indicies Textbox
    noise_injection_prompt = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=180, height=80)
    noise_injection_prompt.grid(row=1, column=3, columnspan=1, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

    # Retrain or Add Data for training
    retrain_or_add_data = ctk.CTkLabel(UI, text="R = Retrain Model(default)\nA = Add Data for Model", font=("Arial", 15), corner_radius=10, fg_color="green", width=180, height=80)
    retrain_or_add_data.grid(row=2, column=2, columnspan=1, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

    # Retrain or Add Data response
    retrain_or_add_data_res = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=180, height=80)
    retrain_or_add_data_res.grid(row=2, column=3, columnspan=1, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")


    # Cancel training button
    cancel_ml_training = ctk.CTkButton(UI, text="Cancel Training Model", font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80, command=UI.destroy)
    cancel_ml_training.grid(row=3, column=0, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")
   
    # Begin training button
    begin_ml_training = ctk.CTkButton(UI, text="Begin Training Model", font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80, command=create_ml_model_files)
    begin_ml_training.grid(row=3, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

# ------------------- End Control Loop ----------------

# ------------------- User Interface ------------------
# Initialize tkinter window for User Interface
# Window theme settings
ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("green")

# UI Frame
UI = ctk.CTk()
UI.geometry("780x380")
UI.title("Rover Trainer")
UI.grid_columnconfigure(4,weight=1)
UI.grid_rowconfigure(4,weight=1)
pad_val = 5

# UI Title
title = ctk.CTkLabel(UI, text="Rover Training", font=("Arial", 30), corner_radius=10, fg_color="green", width=380, height=80)
title.grid(row=0, column=0, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

# Displays Training State
training_state = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=180, height=80)
training_state.grid(row=0, column=2, columnspan=1, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")
training_state.insert("0.0", "Not\nTraining")

# Bluetooth Connection Status
bluetooth_status = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=180, height=80)
bluetooth_status.grid(row=0, column=3, columnspan=1, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")
bluetooth_status.insert("0.0", "Not\nConnected")

# Show controls
controls = ctk.CTkTextbox(UI,font=("Arial", 15), corner_radius=10, fg_color="green", activate_scrollbars=False, width=380, height=180)
controls.grid(row=1, column=0, columnspan=2, rowspan=3, pady=pad_val, padx =pad_val, sticky = "nsew")
controls.insert("0.0", "Controls:\nW - Forward\nA - Left\nD - Right\nS - Stop\nX - Reverse\nT - Pause/Resume Training")

# Begin training session button
start_training_session = ctk.CTkButton(UI, text="Begin Training", font=("Arial", 25), corner_radius=10, fg_color="green", width=380, height=80, command=control_loop)
start_training_session.grid(row=2, column=2, columnspan=2, rowspan=1, pady=pad_val, padx = pad_val, sticky = "nsew")

# Run UI
UI.mainloop()
# ------------------- End User Interface --------------