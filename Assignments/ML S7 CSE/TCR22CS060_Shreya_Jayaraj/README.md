# Model Training - Dataset Description

This project trains a simple model using predefined input–output datasets based on a linear equation.

---

## Input Dataset
    
The dataset used for training is defined in the source code as:

```cpp
std::list<Dataset> datasets = {
    {{1, 2, 3}, {5, 7, 9}},    // y = 2*x + 3
    {{4, 5, 6}, {11, 13, 15}}, // y = 2*x + 3
    {{7, 8, 9}, {17, 19, 21}}  // y = 2*x + 3
};

---
## 📐 Equation Used

**y = 2x + 3**

Each dataset follows the same equation pattern for training consistency.

---

## 💾 Output

The trained model’s output and results are saved in the file:

**`shreya_output.txt`**

This file contains the model’s predictions and/or training logs generated after running the program.
