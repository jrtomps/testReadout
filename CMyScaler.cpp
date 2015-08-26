
#include "CMyScaler.h"


std::vector<uint32_t> CMyScaler::read()
{
  ++m_readCount;

  std::vector<uint32_t> sclrs(m_nChans);
  for (unsigned int chan=0; chan<m_nChans; ++chan) {
    sclrs[chan] = (m_readCount*m_nChans)+chan;
  }

  return sclrs;

}


