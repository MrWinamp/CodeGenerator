#include "codegenerator.h"

CodeGenerator::CodeGenerator(shared_ptr<UnitFactory> factory)
{
    if(factory)
        m_factory = factory;
    else
    {
        shared_ptr<UnitFactory> tmp(new UnitCpp);
        m_factory = tmp;
    }
}

string CodeGenerator::generateProgram()
{
    std::shared_ptr<ClassUnit> myClass = m_factory->createClassUnit("MyClass");

    myClass->add( m_factory->createMethodUnit( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);

    myClass->add( m_factory->createMethodUnit( "testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);

    myClass->add( m_factory->createMethodUnit( "testFunc3", "void",
                                                 MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

    auto method =  m_factory->createMethodUnit( "testFunc4",
    "void", MethodUnit::STATIC );

    method->add(m_factory->createPrintOperatorUnit(R"(Hello world!\n)"));

    myClass->add(method, ClassUnit::PROTECTED);

    myClass->add( m_factory->createMethodUnit( "testFunc5", "void", MethodUnit::STATIC), ClassUnit::PROTECTED_INTERNAL);

    myClass->add( m_factory->createMethodUnit( "testFunc6", "void", MethodUnit::VIRTUAL), ClassUnit::PRIVATE_PROTECTED);

    myClass->add( m_factory->createMethodUnit( "testFunc7", "shared_ptr<Unit> &", MethodUnit::VIRTUAL), ClassUnit::INTERNAL);

    myClass->add( m_factory->createMethodUnit( "testFunc8", "void",
                                                 MethodUnit::STATIC | MethodUnit::FINAL), ClassUnit::PUBLIC);

    myClass->add( m_factory->createMethodUnit( "testFunc9", "void", MethodUnit::ABSTRACT), ClassUnit::PRIVATE);

    return myClass->compile();
}
