#ifndef UNITCSHARP_H
#define UNITCSHARP_H

#include <Factory/unitfactory.h>
#include <Products/ConcreteClassUnit/classunitcsharp.h>
#include <Products/ConcretePrintOperatorUnit/printoperatorunitcsharp.h>
#include <Products/ConcreteMethodUnit/methodunitcsharp.h>

class UnitCSharp: public UnitFactory
{
public:
    UnitCSharp(){};
    ~UnitCSharp(){};

    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name)
    {
        std::shared_ptr<ClassUnit> class_unit(new ClassUnitCSharp(name));
        return class_unit;
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text)
    {
        std::shared_ptr<PrintOperatorUnit> print_operator_unit(new PrintOperatorUnitCSharp(text));
        return print_operator_unit;
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        std::shared_ptr<MethodUnit> method_unit(new MethodUnitCSharp(name, returnType, flags));
        return method_unit;
    }
};

#endif // UNITCSHARP_H
