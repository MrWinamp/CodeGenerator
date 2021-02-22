#ifndef UNITJAVA_H
#define UNITJAVA_H

#include <Factory/unitfactory.h>
#include <Products/ConcreteClassUnit/classunitjava.h>
#include <Products/ConcreteMethodUnit/methodunitjava.h>
#include <Products/ConcretePrintOperatorUnit/printoperatorunitjava.h>

class UnitJava: public UnitFactory
{
public:
    UnitJava(){};
    ~UnitJava(){};

    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name)
    {
        std::shared_ptr<ClassUnit> class_unit(new ClassUnitJava(name));
        return class_unit;
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text)
    {
        std::shared_ptr<PrintOperatorUnit> print_operator_unit(new PrintOperatorUnitJava(text));
        return print_operator_unit;
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        std::shared_ptr<MethodUnit> method_unit(new MethodUnitJava(name, returnType, flags));
        return method_unit;
    }
};

#endif // UNITJAVA_H
