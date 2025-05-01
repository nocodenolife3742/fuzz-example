#ifndef HTMLELEMENT_H
#define HTMLELEMENT_H

#include <string>
#include <vector>
#include "HTMLAttribute.h"

class HTMLElement {
public:
    std::string tagName;
    std::vector<HTMLAttribute*> attributes;
    std::vector<HTMLElement*> children;
    std::string innerText;
    bool selfClosing;

    HTMLElement(const std::string& tag, bool selfClose = false);

    ~HTMLElement();

    void addAttribute(const std::string& key, const std::string& value);

    void addChild(HTMLElement* child);
};

#endif  // HTMLELEMENT_H
