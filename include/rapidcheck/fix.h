#ifndef RAPIDCHECK_FIX_H
#define RAPIDCHECK_FIX_H

#include <string>
#include <sstream>

namespace std
{
    template <typename T>
    std::string to_string(T Value)
    {
        std::ostringstream TempStream;
        TempStream << Value;
        return TempStream.str();
    }      
}

#endif
