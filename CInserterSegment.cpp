

#include <vector>
#include <string>

#include <CRingTextItem.h>
#include <CRingBuffer.h>
#include <CExperiment.h>

#include "CInserterSegment.h"


using namespace std;

CInserterSegment::CInserterSegment(CExperiment* exp)
  : m_exp(exp), m_first(true)
{}

size_t CInserterSegment::read(void* pBuffer, size_t maxwords)
{
  if (m_first) {
    CRingBuffer* ring = m_exp->getRing();
    vector<std::string> strings; 
    strings.push_back("info0");
    strings.push_back("info1");
    strings.push_back("info2");
    CRingTextItem item(FIRST_USER_ITEM_CODE, strings);
    item.commitToRing(*ring);

    m_first = false;
  }
  return 0;
}

