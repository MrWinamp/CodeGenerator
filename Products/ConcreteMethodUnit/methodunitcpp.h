#ifndef METHODUNITCPP_H
#define METHODUNITCPP_H

#include <Products/methodunit.h>

class MethodUnitCpp: public MethodUnit
{
public:
    MethodUnitCpp( const std::string& name, const std::string& returnType, Flags flags ){
        m_name = new std::string(name);
        m_returnType = new std::string(returnType);
        m_flags = new Flags(flags);
        m_body = new std::vector<std::shared_ptr<Unit>>;
    }

    ~MethodUnitCpp(){
        delete m_name;
        delete m_returnType;
        delete m_flags;
        delete m_body;
    }
};

#endif // METHODUNITCPP_H
