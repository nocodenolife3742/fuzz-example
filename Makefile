CXX ?= g++
CXXFLAGS ?= -Wall -Wextra
SOURCES := main.cpp parser/HTMLParser.cpp tree/HTMLElement.cpp tree/HTMLAttribute.cpp
TARGET := html_parser

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -std=c++17 $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean