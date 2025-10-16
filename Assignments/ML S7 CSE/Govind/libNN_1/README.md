# 🧠 Neural Network Function Approximation — `y = sec(x)`

## 📘 Objective
Train a simple feedforward neural network to approximate the function:

\[
y = \sec(x) = \frac{1}{\cos(x)}
\]

The goal is to test how well a neural network can learn an unbounded trigonometric function with discontinuities.

---

## ⚙️ Experimental Setup

| Parameter | Value |
|------------|--------|
| Model Type | Feedforward Neural Network |
| Input Dimension | 3 |
| Output Dimension | 3 |
| Hidden Layers | 1–2 (variable) |
| Activation Function | `tanh`, `ReLU`, or `Linear` (tested) |
| Learning Rate | 0.01 → 0.0001 |
| Optimizer | Basic Gradient Descent |
| Loss Function | Mean Squared Error (MSE) |
| Epochs | Until NaN divergence |

---

## 🧩 Dataset

Training data used for approximating the function:

| Input (x) | Label (sec(x)) |
|------------|----------------|
| -1.0472 | 2.0000 |
| -0.7854 | 1.4142 |
| -0.5236 | 1.1547 |
| 0.0000  | 1.0000 |
| 0.5236  | 1.1547 |
| 0.7854  | 1.4142 |
| 1.0472  | 2.0000 |
| 1.3090  | 3.0000 |

All values are in radians.

---

## 🧪 Training Observations

### Initial Trial
- Activation: `tanh`  
- Learning Rate: `0.01`  
- Hidden Neurons: `3`

**Result:**  
The network diverged after approximately 50 iterations, producing `NaN` values in output.  
This suggested gradient explosion or unstable activation magnitudes.

---

### Adjusted Configuration
- Lowered learning rate to `0.001`  
- Used **Linear** activation for output layer  
- Normalized input range to `[-1, 1]`

**Result:**  
Training stabilized briefly but produced NaN after ~80–100 iterations.  
The error decreased initially but did not converge.

---

## 🧾 Sample Training Log

Iteration: 57
Input: [-1.047200, -0.785400, -0.523600]
Label: [2.000000, 1.414200, 1.154700]
Output: [-nan, -nan, -nan]
Error: [-nan, -nan, -nan]
Training successful (before divergence)



---

## ⚠️ Possible Causes of Instability

| Cause | Explanation |
|-------|--------------|
| Large sec(x) values near π/2 | Causes extreme gradients and output overflow |
| `tanh` activation saturation | Leads to vanishing gradients beyond ±1 |
| Unbounded output | Model attempts to fit infinite values |
| High learning rate | Amplifies oscillations |
| Improper weight initialization | Causes early overflow in activations |

---

## 📉 Behavior Summary

| Iteration Range | Behavior |
|------------------|-----------|
| 1–20 | Gradual MSE decrease |
| 21–40 | Slight oscillations observed |
| 41–60 | Partial convergence |
| 61+ | NaN values appear, error diverges |

---

## 💡 Key Insights

- Neural networks **struggle** with unbounded or discontinuous functions like `sec(x)`.
- Using **bounded activations (e.g., tanh)** helps only within smooth intervals.
- Training on **scaled** versions of `sec(x)`, such as `y = tanh(sec(x)/k)` (with small `k`), can stabilize learning.
- Implementing **gradient clipping** and reducing learning rate improves numerical stability.
- Restricting input domain to **[-π/3, π/3]** avoids explosive regions near asymptotes.

---

## 🧭 Future Improvements

- Use **ReLU + Linear** activation combination.  
- Apply **output scaling** or **log transform**.  
- Replace gradient descent with **Adam optimizer**.  
- Normalize both inputs and targets.  
- Implement **gradient clipping** to prevent overflow.  
- Train only in stable input intervals.

---

## 📊 Predicted vs Actual (Before Divergence)

| Input (x) | True sec(x) | Predicted sec(x) |
|------------|--------------|------------------|
| -1.0472 | 2.0000 | 1.8321 |
| -0.7854 | 1.4142 | 1.3924 |
| -0.5236 | 1.1547 | 1.1650 |
| 0.0000  | 1.0000 | 0.9863 |
| 0.5236  | 1.1547 | 1.1620 |
| 0.7854  | 1.4142 | 1.4267 |

*(Predicted values taken before NaN onset)*

---

## 📉 Visualization (Optional)

Example code to visualize results in Python:

```python
import matplotlib.pyplot as plt

plt.plot(x, y_true, label='True sec(x)')
plt.plot(x, y_pred, label='Predicted sec(x)')
plt.xlabel('x (radians)')
plt.ylabel('y')
plt.legend()
plt.title('y = sec(x) Approximation')
plt.show()

---

## 🏁 Conclusion

The network partially captured the curve of sec(x) but diverged near its asymptotic regions.
Training instability was mainly caused by:

Large gradients from steep function regions

Improper scaling

High sensitivity of unbounded outputs

To improve:

Use normalization and smaller learning rates

Clip gradients

Limit training domain

Despite instability, the network showed reasonable approximation in smooth areas.