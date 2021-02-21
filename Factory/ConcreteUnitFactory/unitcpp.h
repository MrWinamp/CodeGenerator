#ifndef UNITCPP_H
#define UNITCPP_H

#include <Factory/unitfactory.h>
#include <Products/ConcreteClassUnit/classunitcpp.h>
#include <Products/ConcretePrintOperatorUnit/printoperatorunitcpp.h>
#include <Products/ConcreteMethodUnit/methodunitcpp.h>

class UnitCpp: public UnitFactory
{
public:
    UnitCpp(){};
    ~UnitCpp(){};

    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name)
    {
        std::shared_ptr<ClassUnit> class_unit(new ClassUnitCpp(name));
        return class_unit;
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text)
    {
        std::shared_ptr<PrintOperatorUnit> print_operator_unit(new PrintOperatorUnitCpp(text));
        return print_operator_unit;
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        std::shared_ptr<MethodUnit> method_unit(new MethodUnitCpp(name, returnType, flags));
        return method_unit;
    }
};

#endif // UNITCPP_H
