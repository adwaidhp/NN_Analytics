#include <chrono>
#include <unistd.h>
#include <iostream>
#include <list>

#include "data_set.h"
#include "training.h"
#include "model.h"

int main ()
{		
	model mdl = model ();
	mdl.set ();	
		
	training obj = training ();
	
	// Test data for y = 2x + 1
	std::list<std::pair<double, double>> test_cases = {
		{0.0, 1.0},    // 2*0 + 1 = 1
		{1.0, 3.0},    // 2*1 + 1 = 3  
		{2.0, 5.0},    // 2*2 + 1 = 5
		{3.0, 7.0},    // 2*3 + 1 = 7
		{-1.0, -1.0},  // 2*(-1) + 1 = -1
		{10.0, 21.0}   // 2*10 + 1 = 21
	};
	
	double delta = 0.1; // Tolerance
	
	std::cout << "Training neural network to learn y = 2x + 1" << std::endl;
	std::cout << "===========================================" << std::endl;
	
	for (const auto& test_case : test_cases) {
		std::list<double> input = {test_case.first};
		std::list<double> label = {test_case.second};
		
		std::cout << "\nTraining with: x = " << test_case.first << ", expected y = " << test_case.second << std::endl;
		
		bool result = obj.train_single (mdl._nn, input, label, delta); 
		
		if (result) {
			std::cout << "✓ Training successful for this case" << std::endl;
		} else {
			std::cout << "✗ Training failed for this case" << std::endl;
		}
	}
	
	std::cout << "\nFinal Model Test:" << std::endl;
	std::cout << "=================" << std::endl;
	
	// Test final model
	for (double x = -2.0; x <= 4.0; x += 1.0) {
		std::list<double> input = {x};
		double expected = 2*x + 1;
		
		mdl._nn.set_input(input);
		mdl._nn.predict();
		auto output = mdl._nn.get_out_put();
		
		std::cout << "x = " << x << " -> predicted: " << output.front() 
				  << ", expected: " << expected 
				  << ", error: " << fabs(output.front() - expected) << std::endl;
	}

	return 0;
}
