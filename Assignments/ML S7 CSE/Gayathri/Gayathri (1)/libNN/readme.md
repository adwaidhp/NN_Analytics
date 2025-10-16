1.// ALL LAYERS: leaky_relu only
node_list = {
    {{ACT_FUN::leaky_relu, 4.0}, {ACT_FUN::leaky_relu, 4.0}, {ACT_FUN::leaky_relu, 4.0}},
    {{ACT_FUN::leaky_relu, 5.0}, {ACT_FUN::leaky_relu, 2.0}, {ACT_FUN::leaky_relu, 4.0}},
    {{ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}}};

                      TO
    // MIXED ACTIVATIONS:
node_list = {
    {{ACT_FUN::sigmoid, 0.1}, {ACT_FUN::sigmoid, -0.2}, {ACT_FUN::sigmoid, 0.3}},      // Layer 0
    {{ACT_FUN::tanh, 0.05}, {ACT_FUN::tanh, -0.15}, {ACT_FUN::tanh, 0.25}},           // Layer 1  
    {{ACT_FUN::linear, 0.01}, {ACT_FUN::linear, -0.01}, {ACT_FUN::linear, 0.02}}};    // Layer 2
    
    
2.Biases:

    Layer 0: 4.0, 4.0, 4.0

    Layer 1: 5.0, 2.0, 4.0

    Layer 2: 3.0, 3.0, 3.0

    Range: 2.0 to 5.0
    
                         TO
                         
                         Biases:

    Layer 0: 0.1, -0.2, 0.3

    Layer 1: 0.05, -0.15, 0.25

    Layer 2: 0.01, -0.01, 0.02

    Range: -0.2 to 0.3 (much smaller)




3.Input Weights:
  ip_to_nn i1 = {0, 0, 0, 1.0, false};
  ip_to_nn i2 = {0, 1, 0, -1.0, false};
  ip_to_nn i3 = {0, 2, 0, -1.0, false};
  
                                TO
  ip_to_nn i1 = {0, 0, 0, 0.5, false};   // Changed from 1.0
  ip_to_nn i2 = {0, 1, 0, -0.3, false};  // Changed from -1.0  
  ip_to_nn i3 = {0, 2, 0, 0.7, false};   // Changed from -1.0
  
4.Learning Rate:
_nn.set_learning_rate(0.000001);
                     TO
_nn.set_learning_rate(0.0001);  


5.// ALL WEIGHTS: 1.0 only
nn_to_nn n0n10 = {0, 0, 0, 1, 0, 0, 1.0, true};
nn_to_nn n0n11 = {0, 0, 0, 1, 1, 0, 1.0, true};
// ... all 9 connections = 1.0

                        TO
// VARIED WEIGHTS: -0.4 to 0.5
nn_to_nn n0n10 = {0, 0, 0, 1, 0, 0, 0.2, true};   // Was 1.0
nn_to_nn n0n11 = {0, 0, 0, 1, 1, 0, -0.4, true};  // Was 1.0
nn_to_nn n0n12 = {0, 0, 0, 1, 2, 0, 0.3, true};   // Was 1.0

nn_to_nn n0n20 = {0, 1, 0, 1, 0, 0, -0.1, true};  // Was 1.0
nn_to_nn n0n21 = {0, 1, 0, 1, 1, 0, 0.5, true};   // Was 1.0
nn_to_nn n0n22 = {0, 1, 0, 1, 2, 0, -0.2, true};  // Was 1.0

nn_to_nn n0n30 = {0, 2, 0, 1, 0, 0, 0.4, true};   // Was 1.0
nn_to_nn n0n31 = {0, 2, 0, 1, 1, 0, -0.3, true};  // Was 1.0  
nn_to_nn n0n32 = {0, 2, 0, 1, 2, 0, 0.1, true};   // Was 1.0






6.Output Weights:


// ALL WEIGHTS: 1.0 only
nn_to_op o1 = {2, 0, 0, 1.0, false};
nn_to_op o2 = {2, 1, 0, 1.0, false};
nn_to_op o3 = {2, 2, 0, 1.0, false};
                             TO

// VARIED WEIGHTS: 0.6 to 0.9
nn_to_op o1 = {2, 0, 0, 0.8, false};  // Was 1.0
nn_to_op o2 = {2, 1, 0, 0.6, false};  // Was 1.0
nn_to_op o3 = {2, 2, 0, 0.9, false};  // Was 1.0
