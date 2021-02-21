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
        PRIVATE
    };

    static const std::vector< std::string > ACCESS_MODIFIER;

protected:
    std::string * m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > * m_fields;
};

#endif // CLASSUNIT_H
