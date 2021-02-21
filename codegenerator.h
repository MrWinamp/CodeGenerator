#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <memory>
#include <Factory/ConcreteUnitFactory/unitcpp.h>

using namespace std;

class CodeGenerator
{
public:
    CodeGenerator(shared_ptr<UnitFactory> factory);
    string generateProgram();
private:
    shared_ptr<UnitFactory> m_factory;
};

#endif // CODEGENERATOR_H
