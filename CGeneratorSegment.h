

#ifndef CGENERATORSEGMENT_H
#define CGENERATORSEGMENT_H

#include <CEventSegment.h>
#include <stdint.h>
#include <vector>

class CExperiment;

class CGeneratorSegment : public CEventSegment
{
  private:
  size_t m_bufSize;
  uint64_t m_nEvents;
  std::vector<uint16_t> m_buffer;
  CExperiment& m_exp;

  public:
  CGeneratorSegment(size_t bufsize, CExperiment& exp);
  void initialize();
  void clear();
  void disable();
  size_t read(void* pBuffer, size_t maxwords);
};

#endif
