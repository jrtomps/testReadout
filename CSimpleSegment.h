

#ifndef CSIMPLESEGMENT_H
#define CSIMPLESEGMENT_H

#include <CEventSegment.h>
#include <stdint.h>


class CSimpleSegment : public CEventSegment
{
  public:
  size_t read(void* pBuffer, size_t maxwords) {
    uint16_t* buffer = reinterpret_cast<uint16_t*>(pBuffer);
    *buffer = 10;
    return 1;
  }
};

#endif
