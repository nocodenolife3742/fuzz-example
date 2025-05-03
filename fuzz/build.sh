$CXX $CXXFLAGS -std=c++17 -g \
    main.cpp \
    parser/HTMLParser.cpp \
    tree/HTMLElement.cpp \
    tree/HTMLAttribute.cpp \
    -o html_parser \

cp -r html_parser $OUT