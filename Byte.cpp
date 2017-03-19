#include "Byte.h"

#define B10000000 128
#define B01000000 64
#define B00100000 32
#define B00010000 16
#define B00001000 8
#define B00000100 4
#define B00000010 2
#define B00000001 1

#define B01111111 127
#define B10111111 191
#define B11011111 223
#define B11101111 239
#define B11110111 247
#define B11111011 251
#define B11111101 253
#define B11111110 254

#define B11111111 255
#define B00000000 0

const unsigned char whiteMasks[8] = {B10000000, B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001};
const unsigned char blackMasks[8] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

#define WHITE B11111111
#define BLACK B00000000

namespace aa
{

Byte::Byte(unsigned char c):byte(c){}

void Byte::set(int index, unsigned char value)
{
  if (value != WHITE && value != BLACK)
  {
    return;
  }

  byte = value == WHITE? byte | whiteMasks[index] : byte & blackMasks[index];
}

void Byte::set(int index, int value)
{
  if (value != 1 && value != 0)
  {
    return;
  }

  byte = value == 1 ? byte | whiteMasks[index] : byte & blackMasks[index];
}

unsigned char Byte::get(int index)
{
  return (byte & whiteMasks[index]) == whiteMasks[index] ? WHITE : BLACK;
}

unsigned char Byte::getByte()
{
  return byte;
}

}