#include "PropertyList.h"

namespace CGE
{
    using namespace std;

    void trim(string& inString)
    {
        size_t startPos = inString.find_first_not_of(" \t");
        size_t endPos = inString.find_last_not_of(" \t");

        if (startPos == string::npos || endPos == string::npos)
            inString = "";
        else
            inString = inString.substr(startPos, endPos - startPos + 1);
    }

    PropertyList::PropertyList()
    {
    }

    PropertyList::~PropertyList()
    {
    }

    void PropertyList::unset(const string& inKey)
    {
        mProperties.erase(inKey);
    }

    void PropertyList::set(const string& inKey, const string& inValue)
    {
        mProperties[inKey] = inValue;
    }

    const string& PropertyList::getRaw(const string& inKey, const string& inDefault)
    {
        StringMap::iterator i = mProperties.find(inKey);

        if (i == mProperties.end())
        {
            mProperties[inKey] = inDefault;
            return inDefault;
        }

        return i->second;
    }

    istream& operator>>(istream& inStream, PropertyList& inList)
    {
        string s;
        while (getline(inStream, s))
        {
            size_t eq = s.find_first_of('=');
            if (s.length() < 2 || s[0] == '`' || eq == string::npos) continue;

            string key = s.substr(0, eq);
            string value = s.substr(eq + 1);
            trim(key);
            trim(value);

            if (key.length() < 2 || value.length() < 1) continue;

            inList.mProperties[key] = value;
        }

        return inStream;
    }

    ostream& operator<<(ostream& inStream, const PropertyList& inList)
    {
        bool first = true;
        for (StringMap::const_iterator i = inList.mProperties.begin();
                i != inList.mProperties.end(); ++i)
        {
            if (first)
                first = false;
            else
                inStream << '\n';

            inStream << i->first << " = " << i->second;
        }

        return inStream;
    }

}
