#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "unit.h"
#include <vector>

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };

    virtual ~MethodUnit(){};

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body->push_back( unit );
    }

protected:
    std::string * m_name;
    std::string * m_returnType;
    Flags * m_flags;
    std::vector< std::shared_ptr< Unit > > * m_body;
};

#endif // METHODUNIT_H
