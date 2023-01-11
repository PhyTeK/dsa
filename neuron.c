//  NeuralNetwork
//
//  Created by Santiago Becerra on 9/15/19.
//  Copyright © 2019 Santiago Becerra. All rights reserved.
//
//
/*
#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>
*/
#include <Arduino.h>
#include <math.h>

// Simple network that can learn XOR
// Feartures : sigmoid activation function, stochastic gradient descent, and mean square error fuction

// Potential improvements :
// Different activation functions
// Batch training
// Different error funnctions
// Arbitrary number of hidden layers
// Read training end test data from a file
// Add visualization of training
// Add recurrence? (maybe that should be a separate project)

double sigmoid(double x) { return 1 / (1 + exp(-x)); }
double dSigmoid(double x) { return x * (1 - x); }
double init_weight() { return ((double)rand())/((double)RAND_MAX); }
void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void setup(){
    Serial.begin(115200);

    static const int numInputs = 2;
    static const int numHiddenNodes = 2;
    static const int numOutputs = 1;
    
    const double lr = 0.1f;
    
    double hiddenLayer[numHiddenNodes];
    double outputLayer[numOutputs];
    
    double hiddenLayerBias[numHiddenNodes];
    double outputLayerBias[numOutputs];

    double hiddenWeights[numInputs][numHiddenNodes];
    double outputWeights[numHiddenNodes][numOutputs];
    
    static const int numTrainingSets = 4;
    double training_inputs[numTrainingSets][numInputs] = { {0.0f,0.0f},{1.0f,0.0f},{0.0f,1.0f},{1.0f,1.0f} };
    double training_outputs[numTrainingSets][numOutputs] = { {0.0f},{1.0f},{1.0f},{0.0f} };
    
    for (int i=0; i<numInputs; i++) {
        for (int j=0; j<numHiddenNodes; j++) {
            hiddenWeights[i][j] = init_weight();
        }
    }
    for (int i=0; i<numHiddenNodes; i++) {
        hiddenLayerBias[i] = init_weight();
        for (int j=0; j<numOutputs; j++) {
            outputWeights[i][j] = init_weight();
        }
    }
    for (int i=0; i<numOutputs; i++) {
        outputLayerBias[i] = init_weight();
    }
    
    int trainingSetOrder[] = {0,1,2,3};
    
    for (int n=0; n < 5000; n++) {
        shuffle(trainingSetOrder,numTrainingSets);
        for (int x=0; x<numTrainingSets; x++) {
            
            int i = trainingSetOrder[x];
            
            // Forward pass
            
            for (int j=0; j<numHiddenNodes; j++) {
                double activation=hiddenLayerBias[j];
                 for (int k=0; k<numInputs; k++) {
                    activation+=training_inputs[i][k]*hiddenWeights[k][j];
                }
                hiddenLayer[j] = sigmoid(activation);
            }
            
            for (int j=0; j<numOutputs; j++) {
                double activation=outputLayerBias[j];
                for (int k=0; k<numHiddenNodes; k++) {
                    activation+=hiddenLayer[k]*outputWeights[k][j];
                }
                outputLayer[j] = sigmoid(activation);
            }

	    
            //std::cout << "Input:" << training_inputs[i][0] << " " << training_inputs[i][1] << "    Output:" << outputLayer[0] << "    Expected Output: " << training_outputs[i][0] << "\n";

	    Serial.print("Input: ");
	    Serial.print(training_inputs[i][0],0);
	    Serial.print(" ");
	    Serial.print(training_inputs[i][1],0);
	    Serial.print("   Output: ");
	    Serial.print(outputLayer[0],5);
	    Serial.print("   Expected Output: ");
	    Serial.println(training_outputs[i][0],0);

	    // Backprop
            
            double deltaOutput[numOutputs];
            for (int j=0; j<numOutputs; j++) {
                double errorOutput = (training_outputs[i][j]-outputLayer[j]);
                deltaOutput[j] = errorOutput*dSigmoid(outputLayer[j]);
            }
            
            double deltaHidden[numHiddenNodes];
            for (int j=0; j<numHiddenNodes; j++) {
                double errorHidden = 0.0f;
                for(int k=0; k<numOutputs; k++) {
                    errorHidden+=deltaOutput[k]*outputWeights[j][k];
                }
                deltaHidden[j] = errorHidden*dSigmoid(hiddenLayer[j]);
            }
            
            for (int j=0; j<numOutputs; j++) {
                outputLayerBias[j] += deltaOutput[j]*lr;
                for (int k=0; k<numHiddenNodes; k++) {
                    outputWeights[k][j]+=hiddenLayer[k]*deltaOutput[j]*lr;
                }
            }
            
            for (int j=0; j<numHiddenNodes; j++) {
                hiddenLayerBias[j] += deltaHidden[j]*lr;
                for(int k=0; k<numInputs; k++) {
                    hiddenWeights[k][j]+=training_inputs[i][k]*deltaHidden[j]*lr;
                }
            }
        }
    }
    
    // Print weights
    //std::cout << "Final Hidden Weights\n[ ";
    Serial.print("Final Hidden Weights\n[ ");
    for (int j=0; j<numHiddenNodes; j++) {
      //std::cout << "[ ";
      Serial.print("[ ");
        for(int k=0; k<numInputs; k++) {
	  //std::cout << hiddenWeights[k][j] << " ";
	  Serial.print(hiddenWeights[k][j]);
	  Serial.print(" ");
        }
        //std::cout << "] ";
	Serial.print("] ");
    }
    //std::cout << "]\n";
    Serial.println("]");
    
    //std::cout << "Final Hidden Biases\n[ ";
    Serial.println("Final Hidden Biases");
    Serial.print("[ ");
    for (int j=0; j<numHiddenNodes; j++) {
      //std::cout << hiddenLayerBias[j] << " ";
      Serial.print(hiddenLayerBias[j]);
      Serial.print(" ");

    }
    //std::cout << "]\n";
    //std::cout << "Final Output Weights";
    Serial.println("]");
    Serial.print("Final Output Weights");
    for (int j=0; j<numOutputs; j++) {
      //std::cout << "[ ";
      Serial.print("[ ");
      for (int k=0; k<numHiddenNodes; k++) {
	//std::cout << outputWeights[k][j] << " ";
	Serial.print(outputWeights[k][j]);
	Serial.print(" ");
      }
      //std::cout << "]\n";
      Serial.println("]");
    }
    //std::cout << "Final Output Biases\n[ ";
    Serial.println("Final Output Biases");
    Serial.print("[ ");
    for (int j=0; j<numOutputs; j++) {
      //std::cout << outputLayerBias[j] << " ";
      Serial.print(outputLayerBias[j]);
      Serial.print(" ");
    }
    //std::cout << "]\n";
    Serial.println("]");

}

void loop(){}
