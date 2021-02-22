#ifndef METHODUNITJAVA_H
#define METHODUNITJAVA_H

#include <Products/methodunit.h>

class MethodUnitJava: public MethodUnit
{
public:
    MethodUnitJava( const std::string& name, const std::string& returnType, Flags flags ){
        m_name = new std::string(name);
        m_returnType = new std::string(returnType);
        m_flags = new Flags(flags);
        m_body = new std::vector<std::shared_ptr<Unit>>;
    }

    ~MethodUnitJava(){
        delete m_name;
        delete m_returnType;
        delete m_flags;
        delete m_body;
    }

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        if( *m_flags & STATIC ) {
            result += "static ";
            if( *m_flags & FINAL ) {
                result += "final ";
            }
        } else if( *m_flags & FINAL ) {
            result += "final ";
        } else if( *m_flags & ABSTRACT ) {
            result += "abstract ";
        }

            /*
             * STATIC
             * ABSTRACT
             * FINAL
             * STATIC FINAL
             * */

        result += *m_returnType + " ";
        result += *m_name + "()";
        result += " {\n";
        for( const auto& b : *m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
};

#endif // METHODUNITJAVA_H
