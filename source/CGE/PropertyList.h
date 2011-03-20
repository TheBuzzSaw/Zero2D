#ifndef PROPERTYLIST_H
#define PROPERTYLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>

namespace CGE
{
    typedef std::map<std::string, std::string> StringMap;

    class PropertyList
    {
        public:
            PropertyList();
            ~PropertyList();

            void unset(const std::string& inKey);
            void set(const std::string& inKey, const std::string& inValue);
            const std::string& getRaw(const std::string& inKey,
                const std::string& inDefault = std::string());

            template<class T>
            T get(const std::string& inKey, T inDefault)
            {
                T outValue;

                std::stringstream ss;
                ss << inDefault;
                std::string s(ss.str());

                ss.str(std::string());
                ss.clear();

                ss << getRaw(inKey, s);
                if(ss.str().length() > 0) ss >> outValue;
                return outValue;
            }

            friend std::istream& operator>>(std::istream& inStream,
                PropertyList& inList);
            friend std::ostream& operator<<(std::ostream& inStream,
                const PropertyList& inList);

        private:
            StringMap mProperties;
    };

    void trim(std::string& inString);
}

#endif
