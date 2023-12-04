#ifndef UUID2271851904688
#define UUID2271851904688

/**
  * RandomForestClassifier(base_estimator=DecisionTreeClassifier(), bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=None, max_features=auto, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=25, n_jobs=None, num_outputs=5, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class tiltstopRandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[5] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree5(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree6(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree7(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree8(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree9(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree10(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree11(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree12(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree13(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree14(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree15(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree16(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree17(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree18(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree19(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree20(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree21(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree22(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree23(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree24(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 5; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            
            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[5] < 20.5) {
                            
                                
                        if (x[3] < 126.5) {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 133.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 148.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 133.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 148.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 62.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 148.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 133.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 218.0) {
                            
                                
                        if (x[3] < 125.5) {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        if (x[3] < 45.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 119.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 166.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 119.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 166.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 166.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[3] < 126.5) {
                            
                                
                        if (x[2] < 87.5) {
                            
                                
                        if (x[5] < 20.5) {
                            
                                
                        if (x[2] < 70.0) {
                            
                                
                        if (x[3] < 28.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 146.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[4] < 93.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 146.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 146.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 146.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 138.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 74.5) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 141.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 142.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 141.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 56.5) {
                            
                                
                        if (x[4] < 155.5) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[3] < 126.5) {
                            
                                
                        if (x[3] < 105.5) {
                            
                                
                        if (x[2] < 87.5) {
                            
                                
                        if (x[5] < 20.5) {
                            
                                
                        if (x[4] < 116.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[2] < 86.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 53.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 2;
                        *classScore = 1.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 145.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[3] < 126.5) {
                            
                                
                        if (x[2] < 83.5) {
                            
                                
                        if (x[2] < 69.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 139.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 145.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[2] < 87.5) {
                            
                                
                        if (x[4] < 124.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 139.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[4] < 180.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 145.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 139.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 139.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 145.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 53.5) {
                            
                                
                        if (x[2] < 20.0) {
                            
                                
                        *classIdx = 4;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[4] < 218.0) {
                            
                                
                        if (x[2] < 104.5) {
                            
                                
                        if (x[4] < 88.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 131.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 131.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 68.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 131.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 75.0) {
                            
                                
                        if (x[3] < 45.0) {
                            
                                
                        *classIdx = 4;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 150.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 132.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[5] < 20.5) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] < 75.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 124.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 62.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 124.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 220.5) {
                            
                                
                        if (x[3] < 125.5) {
                            
                                
                        if (x[2] < 87.5) {
                            
                                
                        if (x[1] < 82.0) {
                            
                                
                        if (x[2] < 37.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 1.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 146.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 146.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 146.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #10
                 */
                void tree10(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[3] < 126.5) {
                            
                                
                        if (x[4] < 19.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[3] < 89.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 129.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[2] < 85.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] < 74.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 129.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #11
                 */
                void tree11(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 220.5) {
                            
                                
                        if (x[4] < 86.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 4;
                        *classScore = 4.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 122.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 122.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #12
                 */
                void tree12(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 86.0) {
                            
                                
                        if (x[4] < 19.5) {
                            
                                
                        *classIdx = 2;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 127.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 156.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 127.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #13
                 */
                void tree13(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[3] < 126.5) {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        if (x[4] < 70.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 3.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 123.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #14
                 */
                void tree14(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 218.0) {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        if (x[4] < 43.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 126.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 158.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #15
                 */
                void tree15(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 75.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 4;
                        *classScore = 3.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 130.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #16
                 */
                void tree16(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[3] < 125.5) {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 161.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 161.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 122.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 161.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #17
                 */
                void tree17(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 53.0) {
                            
                                
                        if (x[2] < 20.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 151.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 151.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[4] < 86.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 134.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 151.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 134.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #18
                 */
                void tree18(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 75.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 134.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 152.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 134.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #19
                 */
                void tree19(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 221.5) {
                            
                                
                        if (x[3] < 126.5) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[4] < 138.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 146.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 138.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 146.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 138.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #20
                 */
                void tree20(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 75.0) {
                            
                                
                        if (x[4] < 43.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 129.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 155.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 129.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #21
                 */
                void tree21(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 218.0) {
                            
                                
                        if (x[3] < 125.5) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 4;
                        *classScore = 3.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[3] < 105.5) {
                            
                                
                        if (x[1] < 75.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 143.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[5] < 20.5) {
                            
                                
                        if (x[2] < 110.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 143.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 138.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 143.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 143.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #22
                 */
                void tree22(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 215.5) {
                            
                                
                        if (x[4] < 86.0) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 132.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 132.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[5] < 20.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 132.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #23
                 */
                void tree23(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < 215.5) {
                            
                                
                        if (x[2] < 103.5) {
                            
                                
                        if (x[1] < 74.5) {
                            
                                
                        if (x[5] < 10.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 141.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 144.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 141.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[3] < 125.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 141.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 144.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 144.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #24
                 */
                void tree24(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 75.0) {
                            
                                
                        if (x[1] < 18.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 2.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 153.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 130.0;
                        return;

                            
                        }

                }
            
        


            
};



static tiltstopRandomForestClassifier tiltstop;


#endif