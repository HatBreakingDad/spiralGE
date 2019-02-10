#pragma once
#include <iostream>
#ifdef SGE_DEBUG
#define LOG(msg) std::cout << msg << std::endl
#else
#define LOG(msg)
#endif
