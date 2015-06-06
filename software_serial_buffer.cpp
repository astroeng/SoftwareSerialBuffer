#include <software_serial_buffer.h>
#include <Arduino.h>

SoftwareSerialBuffer::SoftwareSerialBuffer(unsigned int size)
{
  buffer        = new unsigned char[size];
  bufferPointer = 0;
  bufferNext    = 0;
  bufferSize    = size;

  memset(buffer,0,sizeof(unsigned char)*bufferSize);
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

/* Ideally this function would purge the number of bytes passed.
 * Eventually the Serial Buffer will be a ring buffer.
 */
void SoftwareSerialBuffer::purge(unsigned int bytes)
{
  memset(buffer,0,sizeof(unsigned char)*bufferSize);
  
  bufferPointer = 0;
  bufferNext    = 0;
}

/* This will return the current byte of the buffer and advance
 * the pointer to the next byte.
 * Eventually this will need to implement ring buffer logic.
 */
unsigned char SoftwareSerialBuffer::read()
{
  if (bufferPointer < bufferSize)
  {
    bufferPointer++;
    return buffer[bufferPointer-1];
  }
  return 0;
}

/* This will save a single value to the buffer.
 * Eventually this will need to implement ring buffer logic.
 */
void SoftwareSerialBuffer::save(unsigned char value)
{
  if (bufferNext < bufferSize)
  {
    buffer[bufferNext] = value;
    bufferNext++;
  }
}

/* Reset the buffer. 
 */
void SoftwareSerialBuffer::resetBuffer()
{
  memset(buffer,0,sizeof(unsigned char)*bufferSize);
  
  bufferPointer = 0;
  bufferNext    = 0;
}
