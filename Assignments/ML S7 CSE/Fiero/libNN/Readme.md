#  Quantum Resonant Neural Network (QRNN)

> A next-generation neural network framework with a **Resonant Activation Function** designed to capture **complex, non-linear patterns** in data.

---

##  Overview

The **Quantum Resonant Neural Network (QRNN)** introduces a novel activation function inspired by **resonance** and **wave interference**, unlocking deeper pattern recognition capabilities beyond traditional ReLU or sigmoid functions.

This project demonstrates:
- A **custom resonant activation** function.
- Flexible neural network design.
- Transparent training logs.
- Real-world and synthetic data demos.

---

##  Core Innovation: Resonant Activation Function

\[
f(x) = e^{-0.5x^2} \cdot \sin(5x)
\]

This activation combines **Gaussian damping** with **sinusoidal oscillations**, allowing neurons to **resonate** with specific input frequencies — mimicking quantum-like energy state interactions.

```cpp
inline double resonant_activation(double x) {
    return exp(-0.5 * x * x) * sin(5 * x);
}
```

###  Why it’s powerful:
- Captures both **localized** and **periodic** features.  
- Enables **finer gradient flow** in hidden layers.  
- Ideal for data with **oscillatory** or **multi-modal** patterns.

---

##  Features

 **Custom Resonant Activation:**  
Captures complex input-response relationships that standard activations miss.

 **Flexible Network Architecture:**  
Supports configurable layers — from simple 3–3–3 layouts to deeper multi-layer designs.

 **Forward & Backward Propagation:**  
Implements end-to-end training using backpropagation.

 **Detailed Training Logs:**  
Shows per-sample insights — input, predicted output, expected label, and error.

---

##  Quick Start

###  Compile the demos

```bash
g++ -o working_demo.exe working_demo.cpp
g++ -o test_real_data.exe test_real_data.cpp
```

###  Run the demos

```bash
.\working_demo.exe
.\test_real_data.exe
```

---

##  Example Output

```text
Input:  [4.0 25.0 16.0]
Label:  [2.0 5.0 4.0]
Output: [1.991425 4.902081 3.931862]
Error:  [0.008575 0.097919 0.068138]

Training successful ✅
```

---

##  Project Structure

| File | Description |
|------|--------------|
| **network.h** | Core neural network and training logic |
| **model.h** | Defines architecture (layers, weights, etc.) |
| **resonant_activation.h** | Implements the resonant activation function |
| **working_demo.cpp** | Demo using sample synthetic data |
| **test_real_data.cpp** | Demo using real-world dataset |

---

##  How It Works

1. **Input Layer:** Feeds input features into the network.  
2. **Hidden Layers:** Transforms data using the *resonant activation function*.  
3. **Output Layer:** Produces predictions.  
4. **Training:** Backpropagation minimizes error between predicted and target values.  
5. **Logging:** Displays progress and per-epoch metrics.

---

##  Conceptual Visualization

```
Sensor Data → [Inputs]
      ↓
  Hidden Neurons (Resonant Activation)
      ↓
     [Outputs]
      ↓
Backpropagation → Weight Updates → Learning
```

---

##  Future Enhancements

- 🪐 Extend to multi-frequency resonant activations  
- 💠 Integrate quantum-inspired parameter tuning  
- 🧩 Visualize resonance surfaces in 3D  
- ⚡ GPU acceleration support  

---

##  Contributors

Developed with 💡 by **Fiero Jain** and contributors exploring the frontier of **AI + Quantum-inspired computing**.

---

##  License

MIT License © 2025 — Free to use and modify for research and learning.

---

> “Where classical neurons learn from data, **resonant neurons** *feel* the patterns.”
