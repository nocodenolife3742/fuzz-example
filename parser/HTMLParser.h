#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include "../tree/HTMLElement.h"

class HTMLParser {
public:
    HTMLElement* parse(const std::string& html);

private:
    size_t pos = 0;

    HTMLElement* parseElement(const std::string& html);

    std::string parseTagName(const std::string& html);

    void skipWhitespace(const std::string& html);

    void parseAttributes(const std::string& html, HTMLElement* elem);

    std::string parseAttributeValue(const std::string& html);
};

#endif  // HTMLPARSER_H
