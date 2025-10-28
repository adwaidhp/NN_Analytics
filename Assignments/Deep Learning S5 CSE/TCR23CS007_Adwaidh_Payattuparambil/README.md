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
- **Epochs**: 60
- **Error threshold**: 0.1

## Code Changes

- In `activation.h`


``` cpp []
#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include "global_enum.h"
#include <cmath> 

class activation 
{
	public:
	
		activation ()
		{
		
		}
	
		double function (ACT_FUN id, double x) 
		{
			switch (id)
			{
				case ACT_FUN::sigmoid:
				
					return  sigmoid (x);
				
				case ACT_FUN::relu:
				
					return  relu (x);
				
				case ACT_FUN::tanh_act:
				
					return  tanh_activation(x);
				
				case ACT_FUN::leaky_relu:
				
					return  leaky_relu (x);
					
				default:
				
					return x;
			}		
		}
	
		double sigmoid (double x)
		{
			return 1.0 / (1.0 + std::exp(-x));
		}

		double relu (double x)
		{
			if (x > 0.0) 
			{
				return x;
			}
		
			return 0;
		}

		double leaky_relu (double x)
		{
			return (x > 0.0) ? x : 0.01 * x; //allowing a small, non-zero gradient for negative inputs
		}
		
		double tanh_activation(double x)
		{
			return std::tanh(x);
		}
};

#endif

```

- In `derivative.h`


``` cpp []
#ifndef __DERIVATIVE_H__
#define __DERIVATIVE_H__

#include "global_enum.h"

class derivative 
{
	public:
	
		derivative ()
		{
		
		}
	
		double loss (ACT_FUN id, double x) 
		{
			switch (id)
			{
				case ACT_FUN::sigmoid:
				
					return  sigmoid (x);
				
				case ACT_FUN::relu:
				
					return  relu (x);
				
				case ACT_FUN::tanh_act:
				
					return  tanh_derivative(x);
				
				case ACT_FUN::leaky_relu:
				
					return  leaky_relu (x);
					
				default:
				
					return x;
			}		
		}
	
		double sigmoid (double x)
		{
			return (x * (1-x));
		}

		double relu (double x)
		{
			if (x > 0.0) 
			{
				return 1.0;
			}
		
			return 0;
		}

		double leaky_relu (double x)
		{
			if (x > 0.0) 
			{
				return 1.0;
			}
		
			return (0.01 * x);
		}
		
		double tanh_derivative(double x)
		{
			return 1.0 - x * x;
		}
};

#endif

```

- In `global_enum.h`

``` cpp []
#ifndef __GLOBAL_ENUM_H__
#define __GLOBAL_ENUM_H__

enum ACT_FUN {sigmoid, tanh_act, relu, leaky_relu};

#endif
```

- In `model.h`

``` cpp []

#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"

                                              class model
{
public:
    network _nn = network();

    model()
    {
    }
    // Better weight initialization
double random_weight() {
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0;  // Range: [-1, 1]
} 
    void set()
    {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // This defines a 4-layer network:
        // Layer 0: 3 neurons (Input Layer)
        // Layer 1: 3 neurons (Hidden Layer)
        // Layer 2: 3 neurons (Hidden Layer)
        // Layer 3: 3 neurons (Output Layer)
        node_list = {
            {{ACT_FUN::tanh_act, 4}, {ACT_FUN::tanh_act, 5}, {ACT_FUN::tanh_act, 6}},

            {{ACT_FUN::sigmoid, 8}, {ACT_FUN::sigmoid, 4}, {ACT_FUN::sigmoid, 4}},
            {{ACT_FUN::relu, 7.0}, {ACT_FUN::relu, 6.0}, {ACT_FUN::relu, 9.0}},

            {{ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}}};

        _nn.initialize(node_list);

        // A higher learning rate for a linear problem
        _nn.set_learning_rate(0.00001);

        // Connects 3 inputs to the 3 neurons of the first layer (Layer 0)
        ip_to_nn i1 = {0, 0, 0, 1.0, false};
        ip_to_nn i2 = {0, 1, 0, -1.0, false};
        ip_to_nn i3 = {0, 2, 0, -1.0, false};

        _nn.add(i1);
        _nn.add(i2);
        _nn.add(i3);

        // Connects all neurons in Layer 0 to all neurons in Layer 1 (Fully Connected)
        nn_to_nn n0n10 = {0, 0, 0, 1, 0, 0, 1.0, true};
        nn_to_nn n0n11 = {0, 0, 0, 1, 1, 0, 1.0, true};
        nn_to_nn n0n12 = {0, 0, 0, 1, 2, 0, 1.0, true};

        nn_to_nn n0n20 = {0, 1, 0, 1, 0, 0, 1.0, true};
        nn_to_nn n0n21 = {0, 1, 0, 1, 1, 0, 1.0, true};
        nn_to_nn n0n22 = {0, 1, 0, 1, 2, 0, 1.0, true};

        nn_to_nn n0n30 = {0, 2, 0, 1, 0, 0, 1.0, true};
        nn_to_nn n0n31 = {0, 2, 0, 1, 1, 0, 1.0, true};
        nn_to_nn n0n32 = {0, 2, 0, 1, 2, 0, 1.0, true};

        _nn.add(n0n10);
        _nn.add(n0n11);
        _nn.add(n0n12);
        _nn.add(n0n20);
        _nn.add(n0n21);
        _nn.add(n0n22);
        _nn.add(n0n30);
        _nn.add(n0n31);
        _nn.add(n0n32);

        // Connects all neurons in Layer 1 to all neurons in Layer 2 (Fully Connected)
        nn_to_nn n1n20 = {1, 0, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n21 = {1, 0, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n22 = {1, 0, 0, 2, 2, 0, 1.0, true};

        nn_to_nn n1n23 = {1, 1, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n24 = {1, 1, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n25 = {1, 1, 0, 2, 2, 0, 1.0, true};

        nn_to_nn n1n26 = {1, 2, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n27 = {1, 2, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n28 = {1, 2, 0, 2, 2, 0, 1.0, true};

        _nn.add(n1n20);
        _nn.add(n1n21);
        _nn.add(n1n22);
        _nn.add(n1n23);
        _nn.add(n1n24);
        _nn.add(n1n25);
        _nn.add(n1n26);
        _nn.add(n1n27);
        _nn.add(n1n28);

        for (int from_node = 0; from_node < 3; from_node++) {
        for (int to_node = 0; to_node < 3; to_node++) {
            nn_to_nn conn = {2, from_node, 0, 3, to_node, 0, 1.0, true};
            _nn.add(conn);
        }
    }

    //Connect Layer 3 to output
    nn_to_op o1 = {3, 0, 0, 1.0, false};  // Layer 3
    nn_to_op o2 = {3, 1, 0, 1.0, false};  // Layer 3  
    nn_to_op o3 = {3, 2, 0, 1.0, false};  // Layer 3

    _nn.add(o1);
    _nn.add(o2);
    _nn.add(o3);
    }
};

#endif
```

- In `unit_test.cpp`

```
std::list<Dataset> datasets = {
        //linear
        {{1, 2, 3}, {2, 4, 6}},
        {{2, 4, 6}, {5, 9, 13}}, //y=2x+1
        //quadratic
        {{1, 2, 3}, {1, 4, 9}}, 
        {{3, 5, 7}, {10, 26, 50}},//y=(x^2)+1
        
        // Add more datasets as needed
    };
```
