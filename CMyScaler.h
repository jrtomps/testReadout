

#ifndef CMYSCALER_H
#define CMYSCALER_H

#include <stdint.h>
#include <vector>
#include <CScaler.h>

class CMyScaler : public CScaler
{
  private:
    uint32_t m_nChans;
    uint32_t m_readCount;

  public:
  CMyScaler(uint32_t nchannels) : m_nChans(nchannels), m_readCount(0) {}
  
  virtual void clear() { }

//  virtual void clear() { m_readCount=0; }
  virtual std::vector<uint32_t> read();

};

#endif
