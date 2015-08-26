

#ifndef CINSERTERSEGMENT_H
#define CINSERTERSEGMENT_H

#include <CEventSegment.h>

class CExperiment;

class CInserterSegment : public CEventSegment
{
  private:
    CExperiment *m_exp;
    bool  m_first;

  public:
    CInserterSegment(CExperiment* exp);
    size_t read(void* pBuffer, size_t maxwords);
};

#endif
