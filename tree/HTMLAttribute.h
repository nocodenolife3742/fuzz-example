#ifndef HTMLATTRIBUTE_H
#define HTMLATTRIBUTE_H

#include <string>

class HTMLAttribute {
public:
    std::string key;
    std::string value;

    HTMLAttribute(const std::string& k, const std::string& v);
};

#endif  // HTMLATTRIBUTE_H
