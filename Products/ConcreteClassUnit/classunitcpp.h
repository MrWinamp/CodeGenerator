#ifndef CLASSUNITCPP_H
#define CLASSUNITCPP_H

#include <Products/classunit.h>

class ClassUnitCpp: public ClassUnit
{
public:
    explicit ClassUnitCpp( const std::string& name ){
        m_name = new std::string(name);
        m_fields = new std::vector<Fields>;
        m_fields->resize(3);
    }

    ~ClassUnitCpp(){
        delete  m_name;
        delete  m_fields;
    }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level ) + "class " + *m_name + " {\n";
        for( size_t i = 0; i < m_fields->size(); ++i ) {
            if( (*m_fields)[ i ].empty() ) {
                continue;
            }
            result += ACCESS_MODIFIER[ i ] + ":\n";
            for( const auto& f : (*m_fields)[ i ] ) {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
};

#endif // CLASSUNITCPP_H
