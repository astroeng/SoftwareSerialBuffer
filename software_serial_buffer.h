#ifndef SOFTWARE_SERIAL_BUFFER_H
#define SOFTWARE_SERIAL_BUFFER_H

class SoftwareSerialBuffer
{
public:
  SoftwareSerialBuffer(unsigned int size);
  ~SoftwareSerialBuffer();
  unsigned int hasSpace();
  unsigned int usedSpace();
  void purge(unsigned int bytes);
  unsigned char read();
  void save(unsigned char value);
  void resetBuffer();
  
  unsigned char* buffer;
  
private:

  unsigned int bufferPointer;
  unsigned int bufferNext;
  unsigned int bufferSize;
  
  
};

#endif