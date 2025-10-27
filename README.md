# NN_Analytics
Notes & Changes from Original Version

Activation function conflicts resolved:

Standard tanh renamed to TANH_ACT in the enum to avoid conflicts.

Added std::exp and std::tanh usage for proper scope.

Neural network input/output management improved using std::list.

Error handling added for output layer.

Fully working unit_test.cpp showing inputs, outputs, and errors.

Removed multiple definitions of main() and cleaned cyclic includes.