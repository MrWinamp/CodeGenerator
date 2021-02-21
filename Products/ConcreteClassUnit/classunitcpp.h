#ifndef CLASSUNITCPP_H
#define CLASSUNITCPP_H

#include <Products/classunit.h>

class ClassUnitCpp: public ClassUnit
{
public:
    explicit ClassUnitCpp( const std::string& name ){
        m_name = new std::string(name);
        m_fields = new std::vector<Fields>;
        m_fields->resize( ACCESS_MODIFIER.size() );
    }

    ~ClassUnitCpp(){
        delete  m_name;
        delete  m_fields;
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIER.size() ) {
            accessModifier = flags;
        }
        (*m_fields)[ accessModifier ].push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level ) + "class " + *m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIER.size(); ++i ) {
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
