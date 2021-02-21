#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "unit.h"

class PrintOperatorUnit : public Unit {
public:
    virtual ~PrintOperatorUnit(){};

protected:
    std::string * m_text;
};

#endif // PRINTOPERATORUNIT_H
