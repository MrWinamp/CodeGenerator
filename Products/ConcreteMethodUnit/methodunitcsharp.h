#ifndef METHODUNITCSHARP_H
#define METHODUNITCSHARP_H

#include <Products/methodunit.h>

class MethodUnitCSharp: public MethodUnit
{
public:
    MethodUnitCSharp( const std::string& name, const std::string& returnType, Flags flags ){
        m_name = new std::string(name);
        m_returnType = new std::string(returnType);
        m_flags = new Flags(flags);
        m_body = new std::vector<std::shared_ptr<Unit>>;
    }

    ~MethodUnitCSharp(){
        delete m_name;
        delete m_returnType;
        delete m_flags;
        delete m_body;
    }
};

#endif // METHODUNITCSHARP_H
