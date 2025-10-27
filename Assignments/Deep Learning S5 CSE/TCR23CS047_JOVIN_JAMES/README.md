
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
- The model used in training is on Leaky Relu Activation function,

```bash
        {{ACT_FUN::leaky_relu, 0.0}, {ACT_FUN::leaky_relu, 0.0}, {ACT_FUN::leaky_relu, 0.0}},

        {{ACT_FUN::leaky_relu, 0.0}, {ACT_FUN::leaky_relu, 0.0}, {ACT_FUN::leaky_relu, 0.0}},

        {{ACT_FUN::leaky_relu, 0.0}, {ACT_FUN::leaky_relu, 0.0}, {ACT_FUN::leaky_relu, 0.0}};

```


### 2.DataSet Given

- Dataset given on training neural network is a quadratic equation.

```bash
    
    {{1, 2, 3}, {2, 4, 6}}, //f(x) = 2x
    {{4, 5, 6}, {8, 10, 12}},
    {{7, 8, 9}, {14, 16, 18}},
    {{10, 12, 14}, {20, 24, 28}}


```

### 3.Delta - Error Threshold

- Threshold is changed into 0.1.

### 4.Learing Rate Setting

- Current learning rate is set into 0.001.
