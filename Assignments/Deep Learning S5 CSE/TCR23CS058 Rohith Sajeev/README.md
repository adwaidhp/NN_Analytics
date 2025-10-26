# Neural Network Implementation

## Changes

### 1.Adding Activation functions

Redefined activation functions in activation.h and included <cmath> for proper mathematical functions

- Adding Sigmoid Function

```bash
double sigmoid(double x)
		{
    		if (x > 100) x = 100;
    		if (x < -100) x = -100;
    		return 1.0 / (1.0 + std::exp(-x));
		}
```

- Adding Relu Function

```bash
double relu (double x)
		{
			if (x > 0.0)
			{
				return x;
			}
		return 0;
		}
```

- Adding Leaky Relu Function

```bash
double leaky_relu (double x)
		{
			if (x > 0.0)
			{
				return x;
			}
			return (0.01 * x);
		}
```

- This model used leaky relu function.

### 2.DataSet Given

- Dataset given on training neural network is a quadratic equation.

```bash
    // Create a list of datasets for f(x) = x^2 + 3
    std::list<Dataset> datasets = {
        {{1, 2, 3}, {4, 7, 12}},
        {{2, 3, 4}, {7, 12, 19}},
        {{3, 4, 5}, {12, 19, 28}},
        {{4, 5, 6}, {19, 28, 39}},
        {{5, 6, 7}, {28, 39, 52}}
    };
```

### 3.Delta - Error Threshold

- Threshold is changed into 0.1.

### 4.Learing Rate Setting

- Current learning rate is set into 0.001.
