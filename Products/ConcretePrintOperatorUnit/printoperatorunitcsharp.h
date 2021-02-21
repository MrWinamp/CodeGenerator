#ifndef PRINTOPERATORUNITCSHARP_H
#define PRINTOPERATORUNITCSHARP_H

#include <Products/printoperatorunit.h>

class PrintOperatorUnitCSharp: public PrintOperatorUnit
{
public:
    explicit PrintOperatorUnitCSharp( const std::string& text ){
        m_text = new std::string(text);
    }

    ~PrintOperatorUnitCSharp(){
        delete m_text;
    }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "Console.WriteLine( \"" + *m_text
        + "\" );\n";
    }
};

#endif // PRINTOPERATORUNITCSHARP_H
