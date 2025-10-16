# Model Training - Dataset Description

This project trains a simple model using predefined input–output datasets based on a linear equation.

---

## Input Dataset
    
The dataset used for training is defined in the source code as:

```cpp
std::list<Dataset> datasets = {
        {{1, 2, 3}, {4, 7, 10}},    // y = 3*x + 1
        {{4, 5, 6}, {13, 16, 19}},  // y = 3*x + 1
        {{7, 8, 9}, {22, 25, 28}}   // y = 3*x + 1
    };
---
## 📐 Equation Used

**y = 3x + 1**

Each dataset follows the same equation pattern for training consistency.

---

## 💾 Output

The trained model’s output and results are saved in the file:

**`jenita_output.txt`**

This file contains the model’s predictions and/or training logs generated after running the program.
