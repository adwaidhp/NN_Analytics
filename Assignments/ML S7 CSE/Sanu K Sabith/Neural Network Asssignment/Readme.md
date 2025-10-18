Updates:-

1. Fixed Assertion Errors

In input.h and label.h, set_input() and set_label() functions were updated to ensure the size of new inputs/labels matches the original.

Prevented crashes like:

Assertion in.size() == input.size() failed.
2. Added error.h

Created an error class to store and print errors between predictions and labels.

Added set_error() and print() methods.
3. Normalized Input and Labels

Converted large input/output values to a smaller range to avoid huge errors during training.

4. Updated unit_test.cpp Training Logic

Added weight initialization.

Implemented forward pass to compute predictions.

Calculated error between predicted output and label.

Updated weights using gradient descent.

Added print statements for: Input, Label, Error, and final predictions.


5. Multi-output Support (partial/future-ready)

Adjusted label class to handle multiple outputs (e.g., [0.78766, 0.4321]) without breaking assertions.

After updates, unit_test runs without aborts or core dumps.

Predictions are now reasonable and closer to labels.
