Neural Network Project - Square Root Prediction
-----------------------------------------------

Description:
This project is a simple neural network written in C++ that learns to predict
the square roots of a given 3-dimensional input vector.

Example:
Input  -> [4, 9, 16]
Output -> [2, 3, 4]

------------------------------------------------
Changes Made:
1. Renamed enum value "tanh" to "tanh_act" in global_enum.h
   → Fixed name clash with math.h tanh() function.

2. Added NaN/Inf (invalid number) checks in neuron.h and network.h
   → Prevents -1.#IND00 or overflow errors during training.

3. Limited gradient updates (max change = 0.1)
   → Stabilizes training and prevents exploding weights.

4. Reduced learning rate in model initialization to 0.0001
   → Helps smooth convergence for this regression task.

5. Added sample dataset for sqrt prediction in unit_test.cpp
   → Inputs are positive; outputs are their square roots.

------------------------------------------------
How to Run:
1. Compile:
   g++ -std=c++11 unit_test.cpp -o unit_test

2. Run:
   ./unit_test > 1.log

3. Check the output log:
   The results will be saved in file "1.log"

------------------------------------------------
Sample Output (from 1.log):

Input: [4.000000 9.000000 16.000000]
Label: [2.000000 3.000000 4.000000]
Output: [2.031000 2.985000 4.010000]
Error: [0.031000 -0.015000 0.010000]
Training successful

------------------------------------------------
Note:
- The model is small and purely experimental.
- Output slightly varies each run due to random weight initialization.
- Avoid negative inputs since sqrt(x) is undefined for x < 0.
