#ifndef __GLOBAL_ENUM_H__
#define __GLOBAL_ENUM_H__

// Renamed tanh to tanh_act to avoid conflict with std::tanh
enum ACT_FUN { sigmoid, tanh_act, relu, leaky_relu };

#endif
