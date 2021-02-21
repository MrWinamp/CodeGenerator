#include <QCoreApplication>
#include <codegenerator.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    shared_ptr<UnitFactory> factory(new UnitCpp);
    CodeGenerator generator(factory);

    cout << generator.generateProgram();

    return a.exec();
}
