#ifndef __LOSS_H__
#define __LOSS_H__

#include <cmath> // For mathematical functions like pow (for squared error)
#include "global_enum.h" // Assuming ACT_FUN might be relevant for loss

class loss
{
public:

    // 1. Calculates the total loss value (e.g., for reporting/monitoring training)
    double calculate_loss(LOSS_FUN id, double predicted, double target)
    {
        switch (id)
        {
            case LOSS_FUN::MSE:
                return mean_squared_error(predicted, target);
            // Add other loss functions here
            default:
                return 0.0;
        }
    }

    // 2. Calculates the derivative of the loss with respect to the prediction (required for backprop)
    double derivative(LOSS_FUN id, double predicted, double target)
    {
        switch (id)
        {
            case LOSS_FUN::MSE:
                return mse_derivative(predicted, target);
            // Add other loss derivatives here
            default:
                return 0.0;
        }
    }

    // Example Loss Function: Mean Squared Error (for a single output)
    double mean_squared_error(double predicted, double target)
    {
        return 0.5 * std::pow(predicted - target, 2);
    }

    // Derivative of MSE: dL/d(predicted)
    double mse_derivative(double predicted, double target)
    {
        return predicted - target;
    }
};

// You would also need to update global_enum.h to include:
// enum LOSS_FUN {MSE, CROSS_ENTROPY};

#endif