

#include "CGeneratorSegment.h"
#include "CRingTextItem.h"
#include "CRingBuffer.h"
#include "CExperiment.h"


CGeneratorSegment::CGeneratorSegment(size_t bufsize, CExperiment& exp)
  : m_bufSize(bufsize),
  m_nEvents(0),
  m_buffer(),
  m_exp(exp)
{
}

void CGeneratorSegment::initialize()
{
  m_nEvents = 0;

  m_buffer.resize(m_bufSize+4);

  int i=0;
  while (i<m_bufSize) {
    m_buffer[i+4] = i;
    ++i;
  }

}

void CGeneratorSegment::clear()
{
}

void CGeneratorSegment::disable()
{
}


size_t CGeneratorSegment::read(void* pBuffer, size_t maxwords)
{

  uint16_t* buffer = reinterpret_cast<uint16_t*>(pBuffer);

  ++m_nEvents;

  setTimestamp(m_nEvents);

  if (maxwords<4) {
    return 0;
  } else {
    m_buffer[0] = m_nEvents &  0x000000000000ffff; 
    m_buffer[1] = (m_nEvents & 0x00000000ffff0000)>>16; 
    m_buffer[2] = (m_nEvents & 0x0000ffff00000000)>>32; 
    m_buffer[3] = (m_nEvents & 0xffff000000000000)>>48; 
  }

  std::vector<uint16_t>::iterator itend = std::min(m_buffer.end(), m_buffer.begin()+maxwords);
  std::copy(m_buffer.begin(), itend, buffer);

  return std::distance(m_buffer.begin(),itend);

}

