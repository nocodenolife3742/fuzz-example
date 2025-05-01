#include "HTMLParser.h"
#include <cctype>

void HTMLParser::skipWhitespace(const std::string& html) {
    while (pos < html.size() && isspace(html[pos]))
        pos++;
}

std::string HTMLParser::parseTagName(const std::string& html) {
    skipWhitespace(html);
    size_t start = pos;
    while (pos < html.size() && (isalnum(html[pos]) || html[pos] == '-'))
        pos++;
    return html.substr(start, pos - start);
}

std::string HTMLParser::parseAttributeValue(const std::string& html) {
    skipWhitespace(html);
    if (html[pos] == '"' || html[pos] == '\'') {
        char quote = html[pos++];
        size_t start = pos;
        while (pos < html.size() && html[pos] != quote)
            pos++;
        std::string value = html.substr(start, pos - start);
        pos++;  // skip closing quote
        return value;
    }
    return "";
}

void HTMLParser::parseAttributes(const std::string& html, HTMLElement* elem) {
    while (pos < html.size() && html[pos] != '>' && html[pos] != '/') {
        skipWhitespace(html);
        size_t keyStart = pos;
        while (pos < html.size() && html[pos] != '=' && html[pos] != '>' &&
               html[pos] != '/')
            pos++;
        std::string key = html.substr(keyStart, pos - keyStart);
        std::string value = "";

        if (html[pos] == '=') {
            pos++;
            value = parseAttributeValue(html);
        }

        elem->addAttribute(key, value);
        skipWhitespace(html);
    }
}

HTMLElement* HTMLParser::parseElement(const std::string& html) {
    if (html[pos] != '<')
        return nullptr;
    pos++;  // skip '<'

    std::string tagName = parseTagName(html);
    HTMLElement* elem = new HTMLElement(tagName);

    parseAttributes(html, elem);

    if (html[pos] == '/') {
        elem->selfClosing = true;
        pos += 2;  // skip "/>"
        return elem;
    }

    pos++;  // skip '>'

    // Inner content or children
    std::string text;
    while (pos < html.size() && html[pos] != '<') {
        text += html[pos++];
    }
    if (!text.empty())
        elem->innerText = text;

    while (pos < html.size() && html[pos] == '<' && html[pos + 1] != '/') {
        HTMLElement* child = parseElement(html);
        if (child)
            elem->addChild(child);
    }

    if (pos < html.size() && html[pos] == '<' && html[pos + 1] == '/') {
        pos += 2;
        parseTagName(html);
        pos++;  // skip '>'
    }

    return elem;
}

HTMLElement* HTMLParser::parse(const std::string& html) {
    pos = 0;
    return parseElement(html);
}
