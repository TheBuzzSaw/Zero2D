#include <iostream>
#ifdef NDEBUG
#define LDB
#else
#define LDB std::cout << __FILE__ << " : " << __LINE__ << std::endl
#endif
