#include <iostream>
#include <fstream>
#include "parser/HTMLParser.h"

void printElement(HTMLElement *elem, int depth = 0) {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "<" << elem->tagName;

    for (auto attr: elem->attributes) {
        std::cout << " " << attr->key << "=\"" << attr->value << "\"";
    }

    if (elem->selfClosing) {
        std::cout << " />\n";
        return;
    }

    std::cout << ">\n";

    if (!elem->innerText.empty()) {
        std::cout << indent << "  " << elem->innerText << "\n";
    }

    for (auto child: elem->children) {
        printElement(child, depth + 1);
    }

    std::cout << indent << "</" << elem->tagName << ">\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <html_file>" << std::endl;
        return 1;
    }

    HTMLParser parser;
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    const std::string html((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    HTMLElement *root = parser.parse(html);
    printElement(root);
    delete root;

    return 0;
}
