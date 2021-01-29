#ifndef SCENAABSTRACT_H
#define SCENAABSTRACT_H
#include "caseabstract.h"

class ScenaAbstract
{
public:
    virtual void rysuj() = 0;
    virtual void loop() = 0;
    virtual CaseAbstract *create(int level) = 0;
};

#endif // SCENAABSTRACT_H
