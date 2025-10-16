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
	
	// Test data for y = 3x + 2
	std::list<std::pair<double, double>> test_cases = {
		{0.0, 2.0},    // 3*0 + 2 = 2
		{1.0, 5.0},    // 3*1 + 2 = 5  
		{2.0, 8.0},    // 3*2 + 2 = 8
		{3.0, 11.0},   // 3*3 + 2 = 11
		{-1.0, -1.0},  // 3*(-1) + 2 = -1
		{10.0, 32.0}   // 3*10 + 2 = 32
	};
	
	double delta = 0.1; // Tolerance
	
	std::cout << "Training neural network to learn y = 3x + 2" << std::endl;
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
		double expected = 3*x + 2;
		
		mdl._nn.set_input(input);
		mdl._nn.predict();
		auto output = mdl._nn.get_out_put();
		
		std::cout << "x = " << x << " -> predicted: " << output.front() 
				  << ", expected: " << expected 
				  << ", error: " << fabs(output.front() - expected) << std::endl;
	}

	return 0;
}
