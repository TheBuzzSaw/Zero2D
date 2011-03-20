#ifndef CGE_PLATFORMS
#define CGE_PLATFORMS

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#   define CGE_PLATFORM_STRING "Windows"
#   define CGE_PLATFORM_WINDOWS
#else
#   define CGE_PLATFORM_UNIX
#   define CGE_UNIX_HOME getenv("HOME")
#   if defined(__APPLE__) || defined(__APPLE_CC__)
#       define CGE_PLATFORM_STRING "OSX"
#       define CGE_PLATFORM_OSX
#   else
#       define CGE_PLATFORM_STRING "Linux"
#       define CGE_PLATFORM_LINUX
#   endif
#endif

#include <cstdlib>

#endif
