-In 'model.h' changed the learning rate from 0.000001 to 0.0001 for faster convergence.
       _nn.set_learning_rate(0.0001);
-In 'unit_test.cpp' increased the number of epochs from 60 to 100 for more stable and accurate model training.
        for(int i=0;i<100;i++)
In 'network.h' Randomized bias initialization for better learning diversity.
        temp_node.b = ((rand() % 200) - 100) / 1000.0;
### Dataset Changes
- Replaced random input generation in `data_set.h` with fixed XOR input patterns.
- Each input pair (A, B) trains the model to output A XOR B.
- Outputs defined in `label.h` match the XOR truth table.

Project Modifications Summary

 ### 1. Model Adjustments

 `model.h`

  * Change: Increased the learning rate from 0.000001 to 0.0001 for faster convergence during training.
  * Code Snippet:

    ```cpp
    _nn.set_learning_rate(0.0001);
    ```

* `unit_test.cpp`

  * Change: Increased the number of training epochs from 60 to 100 to achieve more stable and accurate model performance.
  * Code Snippet:

    ```cpp
    for (int i = 0; i < 100; i++)
    ```



### 2. Network Modifications

* `network.h`

  * Change: Randomized bias initialization to improve learning diversity and prevent uniform weight updates.
  * Code Snippet:

    ```cpp
    temp_node.b = ((rand() % 200) - 100) / 1000.0;
    ```


### 3. Dataset Modifications

* `data_set.h`

  * Change: Replaced random input generation with fixed XOR input patterns for consistent and reproducible training.
  * Description:
    Each input pair `(A, B)` trains the model to output the logical XOR of the two inputs.

*  `label.h`

  * Change: Defined output labels corresponding to the XOR truth table.
  * Example:

    | Input (A, B) | Output |
    | ------------ | ------ |
    | 0, 0         | 0      |
    | 0, 1         | 1      |
    | 1, 0         | 1      |
    | 1, 1         | 0      |


### Overall Objective

The modifications were made to:

* Enhance training speed and convergence through optimized learning rate.
* Improve network generalization via randomized bias initialization.
* Use a well-known, interpretable XOR dataset for verifying model performance.



