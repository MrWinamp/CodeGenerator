#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "unit.h"
#include <vector>

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

    virtual ~MethodUnit(){};

protected:
    std::string * m_name;
    std::string * m_returnType;
    Flags * m_flags;
    std::vector< std::shared_ptr< Unit > > * m_body;
};

#endif // METHODUNIT_H
