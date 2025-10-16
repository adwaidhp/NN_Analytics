# Model Training - Dataset Description

This project trains a simple model using predefined input–output datasets based on a linear equation.

---

## Input Dataset
    
The dataset used for training is defined in the source code as:

```cpp
std::list<Dataset> datasets = {
        {{1, 2, 3}, {1, 3, 5}},    // y = 2*x - 1
        {{4, 5, 6}, {7, 9, 11}},    // y = 2*x - 1
        {{7, 8, 9}, {13, 15, 17}}   // y = 2*x - 1
    };

---
## 📐 Equation Used

**y = 2x - 1**

Each dataset follows the same equation pattern for training consistency.

---

## 💾 Output

The trained model’s output and results are saved in the file:

**`niveditha_output.txt`**

This file contains the model’s predictions and/or training logs generated after running the program.
