## Changes Done

## Activation functions

- modified tanh function in activation.h

```bash
double tanh_act (double x)
		{
			return std::tanh(x);
		}
```

- modified leaky reLu function in activation.h

```bash
double leaky_relu (double x)
		{
			if (x>0){
				return x;
			}
			return x*.01;
		}
```
## Dataset given

```bash
std::list<Dataset> datasets = {
        {{1, 2, 3}, {3, 5, 9}},    // x^2 - x + 3
        {{2, 3, 4}, {5, 9, 15}}, 
        {{3, 4, 5}, {9, 15, 23}},  
        {{4, 5, 6}, {15, 23, 33}},
        {{5, 6, 7}, {23, 33, 45}}  
    ;
```

## Learning rate

- changed to 0.001
- changed delta to 0.05
