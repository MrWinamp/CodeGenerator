#ifndef PRINTOPERATORUNITJAVA_H
#define PRINTOPERATORUNITJAVA_H

#include <Products/printoperatorunit.h>

class PrintOperatorUnitJava: public PrintOperatorUnit
{
public:
    explicit PrintOperatorUnitJava( const std::string& text ){
        m_text = new std::string(text);
    }

    ~PrintOperatorUnitJava(){
        delete m_text;
    }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "System.out.println( \"" + *m_text
        + "\" );\n";
    }
};

#endif // PRINTOPERATORUNITJAVA_H
