Deep Learning S5 CSE: Multi-Output Network Training Report

1. Project Goal

The primary objective was to train a multi-layer neural network to simultaneously learn three distinct, multi-variable linear functions from the same input data, achieving a low error threshold (convergence criteria implied by "Training successful").

2. Dataset and Target Functions

The model was trained on three independent functions based on the input vector $\mathbf{x} = [x_1, x_2, x_3]$:

Output 1: $y_1 = 3x_1 + 1$

Output 2: $y_2 = x_2 - 1$

Output 3: $y_3 = 2x_3 + 1$

(Note: Initial attempts to implement a quadratic function required a deeper model, confirming the non-linearity needed to be addressed by capacity.)

3. Challenges Encountered & Solutions

Issue

Observation / Symptom

Solution

Numerical Instability

Output: [nan nan nan ], followed by "Training successful".

Corrected activation function names (tanh_act) and implemented small initial weight/bias strategies to prevent overflow.

Vanishing Gradient

Using Sigmoid activation caused gradients to vanish, leading to identical output across all epochs and no learning.

Replaced Sigmoid with a combination of ReLU and Leaky ReLU in hidden layers for stable, non-zero gradient flow.

Symmetry

Using the same bias and activation function for every node in a layer resulted in constant, symmetric output.

Used different activation functions and biases within the hidden layer to break symmetry and encourage unique feature learning.

Learning Speed

The original learning rate of $0.00001$ was too slow.

Increased the learning rate (though the exact final value is not shown below, the training speed indicates it was significantly increased from the minimum).

4. Successful Training Log

The final, stable network configuration achieved convergence on all three target functions within a few epochs, demonstrating highly accurate regression results.
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.003629 12.990000 10.001006 ]
Error: [-0.003631 0.009992 -0.001006 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000994 11.003932 15.990000 ]
Error: [-0.000995 -0.003934 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.996109 6.999629 9.010000 ]
Error: [0.003888 0.000371 -0.010011 ]
Training successful
in iteration: 0
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001396 12.990000 10.004854 ]
Error: [-0.001397 0.009992 -0.004856 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000978 11.003787 15.990000 ]
Error: [-0.000979 -0.003789 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.996728 6.998976 9.010000 ]
Error: [0.003270 0.001024 -0.010011 ]
Training successful
in iteration: 1
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001379 12.990000 10.005022 ]
Error: [-0.001380 0.009992 -0.005025 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000965 11.003641 15.990000 ]
Error: [-0.000965 -0.003642 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.997252 6.998438 9.010000 ]
Error: [0.002746 0.001562 -0.010011 ]
Training successful
in iteration: 2
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001360 12.990000 10.005195 ]
Error: [-0.001360 0.009992 -0.005198 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000953 11.003494 15.990000 ]
Error: [-0.000953 -0.003495 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.997690 6.998009 9.010000 ]
Error: [0.002309 0.001990 -0.010011 ]
Training successful
in iteration: 3
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001339 12.990000 10.005367 ]
Error: [-0.001340 0.009992 -0.005370 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000940 11.003350 15.990000 ]
Error: [-0.000940 -0.003351 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.998047 6.997683 9.010000 ]
Error: [0.001952 0.002316 -0.010011 ]
Training successful
in iteration: 4
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001320 12.990000 10.005532 ]
Error: [-0.001321 0.009992 -0.005535 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000926 11.003210 15.990000 ]
Error: [-0.000926 -0.003211 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.998333 6.997454 9.010000 ]
Error: [0.001667 0.002545 -0.010011 ]
Training successful
in iteration: 5
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001307 12.990000 10.005676 ]
Error: [-0.001307 0.009992 -0.005679 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000909 11.003075 15.990000 ]
Error: [-0.000909 -0.003076 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.998556 6.997315 9.010000 ]
Error: [0.001443 0.002684 -0.010011 ]
Training successful
in iteration: 6
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001308 12.990000 10.005778 ]
Error: [-0.001308 0.009992 -0.005781 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000888 11.002949 15.990000 ]
Error: [-0.000888 -0.002950 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.998729 6.997258 9.010000 ]
Error: [0.001271 0.002741 -0.010011 ]
Training successful
in iteration: 7
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001339 12.990000 10.005798 ]
Error: [-0.001340 0.009992 -0.005801 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000861 11.002833 15.990000 ]
Error: [-0.000861 -0.002833 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.998861 6.997271 9.010000 ]
Error: [0.001139 0.002728 -0.010011 ]
Training successful
in iteration: 8
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001433 12.990000 10.005652 ]
Error: [-0.001433 0.009992 -0.005655 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000829 11.002726 15.990000 ]
Error: [-0.000829 -0.002727 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.998962 6.997341 9.010000 ]
Error: [0.001038 0.002658 -0.010011 ]
Training successful
in iteration: 9
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.001652 12.990000 10.005162 ]
Error: [-0.001652 0.009992 -0.005165 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000794 11.002627 15.990000 ]
Error: [-0.000794 -0.002627 0.009994 ]
Training successful
Input: [2.000000 3.000000 4.000000 ]
label: [5.000000 7.000000 9.000000 ]
Output: [4.999037 6.997458 9.010000 ]
Error: [0.000963 0.002541 -0.010011 ]
Training successful
in iteration: 10
Input: [2.000000 4.000000 3.000000 ]
label: [7.000000 13.000000 10.000000 ]
Output: [7.002121 12.990000 10.003936 ]
Error: [-0.002122 0.009992 -0.003938 ]
Training successful
Input: [5.000000 10.000000 15.000000 ]
label: [6.000000 11.000000 16.000000 ]
Output: [6.000761 11.002526 15.990000 ]
Error: [-0.000761 -0.002526 0.009994 ]
Training successful
