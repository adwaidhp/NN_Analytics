
# Neural Network Implementation

## Changes
### 1.Adding Activation functions and BackPropagation derivative
Adding Sigmoid Function

**double sigmoid(double x)
		{
    		if (x > 100) x = 100;
    		if (x < -100) x = -100;
    		return 1.0 / (1.0 + std::exp(-x));
		}
    **
Adding Relu Function

**double relu (double x)
		{
			if (x > 0.0) 
			{
				return x;
			}
		
			return 0;
		}
**
Example:  
This project is a deep learning model that predicts house prices based on various features. It is designed to help users make informed real estate decisions.

---

## [Installation]  
Step-by-step instructions to get the project running locally.  

