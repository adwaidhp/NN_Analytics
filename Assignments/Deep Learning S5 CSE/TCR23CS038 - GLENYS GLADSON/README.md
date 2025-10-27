
## 🎯 Goal

To train a multi-layer neural network to accurately predict outputs for the equation **y = 5x + 13**.


## 🧪 Procedure and Methods Summary (The Journey So Far)

The journey involved debugging instability issues and functional flaws before achieving stable convergence using the base training loop.

### 1. Trial: Two-Phase Adaptive Learning

- **Trial Attempted:** Implemented a **Two-Phase Adaptive Learning Strategy** (in an attempted modification of `training.h`).  
  This method was designed to transition the learning rate from a fast value to a very slow one, aiming to quickly leave the error plateau and then fine-tune parameters.
- **Result:** This complex adaptive method did **not** resolve the core instability and was abandoned. The issue was confirmed to be structural, not procedural.


### 2. Stabilization: Taming Exploding Gradients

- **Problem:** Initial training runs resulted in huge errors and immediate **NaN (Not a Number)** values, indicating **Exploding Gradients**.
- **Successful Modification (A):** The network's initial **weights** were changed from ~1.0 (or random large values) to **tiny values** (e.g., `0.01`).
- **Key Learning:**  
  Safe initialization is mandatory. Starting with near-zero weights prevents the massive initial gradients that lead to NaN and system instability.


### 3. Activation Function Correction

- **Problem:** The original function definitions for non-linear activations like `sigmoid`, `leaky_relu`, and `tanh` were mathematically incorrect (all returned the identity `x`).
- **Successful Modification (B):** All activation functions were corrected to their standard mathematical implementations.  
  Crucially, **Leaky ReLU** was implemented correctly to ensure a small gradient flows for negative inputs (`αx`).
- **Key Learning:**  
  The correct mathematical definition of activation functions is essential for both the forward pass and the accuracy of the backpropagation gradient.


### 4. The Final Breakthrough: Bias Adjustment (Simple Fix)

- **Problem:** Despite the preceding fixes, the model still struggled to converge quickly and exhibited oscillation (errors swinging between positive and negative), particularly failing to home in on the large positive intercept (`b = 13`) with the minimal learning rate (`0.000001`).
- **Successful Modification (C):** The final, most impactful change was adjusting the **initial bias** for all neurons in the **first layer** to `1.0`.
- **Key Learning:**  
  Bias initialization is crucial for linear offsets. For a linear function with a significant non-zero intercept, initializing the bias to a reasonable starting value provides a massive head start.  
  This simple structural fix allowed the **base training process (without any adaptive method)** to finally converge successfully.


## ⚙️ Final Successful Implementation Details

The model converged using the following stable configuration:

- **Training Loop:** Base/Standard Gradient Descent (no modifications to `training.h`)  
- **Initial Weights:** `0.01` (tiny values)  
- **Initial Bias (First Layer):** `1.0` (structural offset)  
- **Activation Functions:** All implemented using their correct mathematical forms

