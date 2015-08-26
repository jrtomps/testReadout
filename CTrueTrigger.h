

#ifndef CTRUETRIGGER_H
#define CTRUETRIGGER_H

#include <CEventTrigger.h>

class CTrueTrigger : public CEventTrigger
{
    public:
    bool operator()() { return true;} 
};

#endif
