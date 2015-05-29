#include <software_serial_buffer.h>


SoftwareSerialBuffer::SoftwareSerialBuffer(unsigned int size)
{
  buffer        = new unsigned char[size];
  bufferPointer = 0;
  bufferNext    = 0;
  int i = 0;
  
  for (i = 0; i < bufferSize; i++)
  {
    buffer[i] = 0;
  }
}

SoftwareSerialBuffer::~SoftwareSerialBuffer()
{
  delete[] buffer;
}

unsigned int SoftwareSerialBuffer::usedSpace()
{
  return bufferNext;
}

unsigned int SoftwareSerialBuffer::hasSpace()
{
  return bufferSize - bufferNext;
}

void SoftwareSerialBuffer::purge(unsigned int bytes)
{
  bufferPointer+=bytes;
}

unsigned char SoftwareSerialBuffer::read()
{
  if (bufferPointer < bufferSize)
  {
    bufferPointer++;
    return buffer[bufferPointer-1];
  }
  return 0;
}


void SoftwareSerialBuffer::save(unsigned char value)
{
  if (bufferNext < bufferSize)
  {
    buffer[bufferNext] = value;
    bufferNext++;
  }
}

void SoftwareSerialBuffer::resetBuffer()
{
  bufferPointer = 0;
  bufferNext    = 0;
}