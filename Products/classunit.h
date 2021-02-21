#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <string>
#include <memory>
#include "unit.h"
#include <vector>

class ClassUnit : public Unit
{
public:
    virtual ~ClassUnit(){};

    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

    static const std::vector< std::string > ACCESS_MODIFIER;

    void add( const std::shared_ptr< Unit >& unit, Flags flags = PRIVATE ) {
        int accessModifier = PRIVATE;
        if(flags < m_fields->size()) {
            accessModifier = flags;
        }
        else
            return;
        (*m_fields)[ accessModifier ].push_back( unit );
    }

protected:
    std::string * m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > * m_fields;
};

#endif // CLASSUNIT_H
