#include "Exception.h"

namespace CGE
{
    Exception::Exception(const std::string& inHeader,
        const std::string& inMessage) : header(inHeader), message(inMessage)
    {
    }

    Exception::Exception(const Exception& inException)
        : header(inException.header), message(inException.message)
    {
    }

    Exception::~Exception()
    {
    }
}
