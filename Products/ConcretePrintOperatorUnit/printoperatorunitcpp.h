#ifndef PRINTOPERATORUNITCPP_H
#define PRINTOPERATORUNITCPP_H

#include <Products/printoperatorunit.h>

class PrintOperatorUnitCpp: public PrintOperatorUnit
{
public:
    explicit PrintOperatorUnitCpp( const std::string& text ){
        m_text = new std::string(text);
    }

    ~PrintOperatorUnitCpp(){
        delete m_text;
    }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + *m_text
        + "\" );\n";
    }
};

#endif // PRINTOPERATORUNITCPP_H
