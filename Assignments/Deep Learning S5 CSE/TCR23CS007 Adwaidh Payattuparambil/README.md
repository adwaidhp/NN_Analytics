## Work Done

- Fixed tanh, Sigmoid, reLu and leaky relu implementation in derivative.h and activation.h (Replaced placeholder functions)
- Fixed error in global_enum.h (name conflict issues with cmath module)
- Changed dataset to test linear and quadratic equations.
- Increased total number of layers to 4, (2 hidden).

## ⚙️ Configuration / Updates

The following changes have been made to the network configuration:

- **Dataset values**: Updated dataset values are being used for training.
- **Number of neurons in hidden layer**: 3
- **Activation functions**:

  - Layer 1: `tanh`
  - Layer 2: `Sigmoid`
  - Layer 3: `ReLU`
  - Layer 4: `leaky_relu`

- **Initial weights**: Custom initialization for all layers.
- **Learning rate**: 0.00001
- **Error threshold**: 0.1
