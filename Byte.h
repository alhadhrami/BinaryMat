#ifndef BYTE_H
#define BYTE_H

namespace aa
{

class Byte
{
public:
  Byte(unsigned char c = 0);
  void set(int index, unsigned char value);
  void set(int index, int value);
  unsigned char get(int index);
  unsigned char getByte();

private:
  unsigned char byte;
};

}

#endif