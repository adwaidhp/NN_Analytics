🧠 Work Done

Added a training timer using the C++ <chrono> library to measure and display total training duration after all epochs.

Improved console output formatting for better readability, showing epoch separators and clearer training messages.

Implemented dynamic dataset addition using emplace_back() to easily expand training data without modifying the initialization block.

Introduced epoch-based progress tracking with iteration logs for each dataset during training.

Refactored loop and message structures to make the output more descriptive and consistent.

⚙️ Configuration / Updates

The following enhancements were made to improve usability and monitoring:

Training Loop: Runs for 60 epochs, printing progress after each one.

Dynamic Dataset Support: Additional datasets can now be appended at runtime.

Threshold (delta): 0.1 — used as the error margin for convergence.

Performance Logging: Displays total training time in seconds upon completion.

Output Messages:

"Dataset trained successfully." for successful training.

"Retry training with adjusted parameters." for unsuccessful runs.

"Completed Epoch: <n>" after each iteration.
