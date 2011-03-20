#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

namespace CGE
{
    class Exception
    {
        public:
            Exception(const std::string& inHeader,
                const std::string& inMessage);
            Exception(const Exception& inException);
            virtual ~Exception();

            const std::string header;
            const std::string message;
    };
}

#endif
