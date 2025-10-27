#ifndef __DATA_SET_H__
#define __DATA_SET_H__

#include <list> 
#include <vector>
#include <cstdlib> 
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

struct Dataset {
    std::list<double> input;
    std::list<double> label;
};

class data_set
{
private:
    std::mt19937 rng;
    
    // Helper function to generate random double in range
    double random_double(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }
    
    // Helper function to generate random integer in range
    int random_int(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

public:
    data_set() {
        rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    }

    double get_val(const unsigned int seed, const double lower_bound, const double upper_bound, const long max_rand) {    	
        std::srand(seed);
        return lower_bound + (upper_bound - lower_bound) * (random() % max_rand) / max_rand;
    }

    std::list<double> get_list(const unsigned int size, const double lower_bound, const double upper_bound, const long max_rand) {
        std::list<double> _list;
        
        auto start = std::chrono::high_resolution_clock::now();
        
        for (unsigned int index = 0; index < size; index++) {
            auto finish = std::chrono::high_resolution_clock::now();
            _list.push_back(get_val(std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count(), 
                                   lower_bound, upper_bound, max_rand));	
        }
        
        return _list;
    }

    // Generate multiple progression data
    // Input: sequence like (3,4,5), Output: sequence multiplied by random factor
    Dataset generate_multiple_progression(int sequence_length = 3, 
                                          double min_val = 1.0, 
                                          double max_val = 20.0) {
        Dataset ds;
        double multiplier = random_double(2.0, 10.0); // Random multiplier between 2 and 10
        
        for (int i = 0; i < sequence_length; i++) {
            double val = random_double(min_val, max_val);
            ds.input.push_back(val);
            ds.label.push_back(val * multiplier);
        }
        
        return ds;
    }

    // Generate arithmetic progression data
    // Input: AP sequence like (10,15,20), Output: next terms in sequence
    Dataset generate_arithmetic_progression(int sequence_length = 3,
                                           double min_start = 5.0,
                                           double max_start = 50.0) {
        Dataset ds;
        double start = random_double(min_start, max_start);
        double diff = random_double(2.0, 10.0);
        
        // Generate input sequence
        for (int i = 0; i < sequence_length; i++) {
            ds.input.push_back(start + i * diff);
        }
        
        // Generate output sequence (next terms)
        for (int i = 0; i < sequence_length; i++) {
            ds.label.push_back(start + (sequence_length + i) * diff);
        }
        
        return ds;
    }

    // Generate power progression data
    // Input: sequence like (3,4,5), Output: values raised to random power
    Dataset generate_power_progression(int sequence_length = 3,
                                      double min_val = 2.0,
                                      double max_val = 10.0) {
        Dataset ds;
        int power = random_int(2, 4); // Random power between 2 and 4
        
        for (int i = 0; i < sequence_length; i++) {
            double val = random_double(min_val, max_val);
            ds.input.push_back(val);
            
            double result = 1.0;
            for (int p = 0; p < power; p++) {
                result *= val;
            }
            ds.label.push_back(result);
        }
        
        return ds;
    }

    // Generate combined dataset with all types in random order
    std::list<Dataset> generate_combined_data_custom(int total_datapoints,
                                           
                                              double gp_ratio = 0.33,
                                              double ap_ratio = 0.33) {
        // Calculate number of each type
        int sequence_length = 3;
        int gp_count = static_cast<int>(total_datapoints * gp_ratio);
        int ap_count = static_cast<int>(total_datapoints * ap_ratio);
        int power_count = total_datapoints - gp_count - ap_count;
        
        // Use vector for efficient shuffling, then convert to list
        std::vector<Dataset> datasets;
        datasets.reserve(total_datapoints);
        
        // Generate multiple progressions
        for (int i = 0; i < gp_count; i++) {
            datasets.push_back(generate_multiple_progression(sequence_length));
        }
        
        // Generate arithmetic progressions
        for (int i = 0; i < ap_count; i++) {
            datasets.push_back(generate_arithmetic_progression(sequence_length));
        }
        
        // Generate power progressions
        for (int i = 0; i < power_count; i++) {
            datasets.push_back(generate_power_progression(sequence_length));
        }
        
        // Shuffle to randomize order
        std::shuffle(datasets.begin(), datasets.end(), rng);
        
        // Convert to list and return
        std::list<Dataset> result;
        for (const auto& ds : datasets) {
            result.push_back(ds);
        }
        
        return result;
    }

    // Overloaded version with equal distribution
    std::list<Dataset> generate_combined_data(int total_datapoints) {
        return generate_combined_data_custom(total_datapoints,0.33, 0.33);
    }
};

#endif