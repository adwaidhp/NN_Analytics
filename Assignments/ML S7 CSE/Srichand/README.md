# Neural Network Project - ML S7 CSE

## ⚙️ Configuration / Updates

The following changes have been made to the network configuration:

- **Dataset values**: Updated dataset values are being used for training.
- **Input**:  `(x1, x2, x3)`
- **Output**: `[s, s², s³]` where `s = (x1 + x2 + x3)/100`
- **Network architecture**:
  - Layer 0: 3 neurons (Input Layer)
  - Layer 1: 3 neurons (Hidden Layer)
  - Layer 2: 3 neurons (Output Layer)
- **Activation functions**:
  - All layers: `leaky_relu`
- **Weights**: Random small weights in range [-0.1, 0.1]
- **Epochs**: 10 (can be increased)
- **Learning rate**: 0.01
- **Error threshold**: 0.001
- **Changes in code**:
  - `model.h`: fixed `_nn.add(...)` calls by using named variables instead of temporaries.
  - `main.cpp`: added dataset creation, normalization, and training loop with progress prints.
