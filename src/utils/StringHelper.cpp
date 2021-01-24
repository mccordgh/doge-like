#include "StringHelper.h"

string StringHelper::getSubStringBeforeCharacter(string const& fullString, const char& searchChar)
{
    std::string::size_type pos = fullString.find(searchChar);

    if (pos != std::string::npos)
    {
        return fullString.substr(0, pos);
    }
    else
    {
        return fullString;
    }
}