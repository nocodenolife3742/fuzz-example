#include "HTMLElement.h"
#include <cstdlib>

HTMLElement::HTMLElement(const std::string& tag, bool selfClose)
    : tagName(tag), selfClosing(selfClose) {}

HTMLElement::~HTMLElement() {
    for (auto attr : attributes)
        delete attr;
    for (auto child : children)
        delete child;
}

void HTMLElement::addAttribute(const std::string& key,
                               const std::string& value) {
    HTMLAttribute* attr = new HTMLAttribute(key, value);
    attributes.push_back(attr);
}

void HTMLElement::addChild(HTMLElement* child) {
    children.push_back(child);
}
