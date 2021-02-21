#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include <memory>
#include <iostream>
#include <Products/classunit.h>
#include <Products/printoperatorunit.h>
#include <Products/methodunit.h>

class UnitFactory
{
public:
    virtual ~UnitFactory() = default;

    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
};

#endif // UNITFACTORY_H
