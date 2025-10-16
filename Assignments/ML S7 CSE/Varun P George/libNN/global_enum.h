#ifndef __GLOBAL_ENUM_H__
#define __GLOBAL_ENUM_H__

// Added LINEAR and renamed TANH_ACT to avoid conflict with std::tanh
enum class ACT_FUN { LINEAR, SIGMOID, RELU, TANH_ACT, LEAKY_RELU };

#endif
