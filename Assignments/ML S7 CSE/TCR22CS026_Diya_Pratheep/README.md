# Model Training - Dataset Description

This project trains a simple model using predefined input–output datasets based on a linear equation.

---

## Input Dataset
    
The dataset used for training is defined in the source code as:

```cpp
std::list<Dataset> datasets = {
        {{1, 2, 3}, {5, 8, 11}},    // y = 3*x + 2
        {{4, 5, 6}, {14, 17, 20}},  // y = 3*x + 2
        {{7, 8, 9}, {23, 26, 29}}   // y = 3*x + 2
    };

---
## 📐 Equation Used

**y = 2x + 3**

Each dataset follows the same equation pattern for training consistency.

---

## 💾 Output

The trained model’s output and results are saved in the file:

**`diya_output.txt`**

This file contains the model’s predictions and/or training logs generated after running the program.
