#include "BinaryImage.h"

namespace aa
{

BinaryMat::BinaryMat(const cv::Mat* mat)
{
  setMat(mat);
}

BinaryMat::~BinaryMat()
{
  delete bytes;
}

void BinaryMat::setMat(const cv::Mat* mat)
{    
  setVariables(mat->rows, mat->cols);
  bytesFromMat(mat);
}

bool BinaryMat::matFromBytes(cv::Mat* mat)
{
  if (mat->rows != r || mat->cols != c)
  {
    return false;
  }

  int bitIndex = 0;
  int byteIndex = 0;

  for(int i = 0; i < r; i++)
  {
    uchar* rowData = (uchar*)mat->ptr(i); // points to the beginning of the i'th row
    for(int j = 0; j < c; j++)
    {
      uchar pixel = bytes[byteIndex].get(bitIndex);
      rowData[j] = bytes[byteIndex].get(bitIndex);
      bitIndex = (bitIndex + 1) % BYTE_SIZE;
      byteIndex = bitIndex == 0 ? byteIndex + 1 : byteIndex;
    }
  }
  return true;
}

int BinaryMat::rows()
{
  return r;
}

int BinaryMat::cols()
{
  return c;
}
void BinaryMat::setVariables(int rows, int cols)
{
  r = rows;
  c = cols;
  bytes = new Byte[getBytesSize()];
}

int BinaryMat::getBytesSize()
{
  return (int)(ceil(1.0 * r * c / BYTE_SIZE));
}

void BinaryMat::bytesFromMat(const cv::Mat* mat)
{
  int bitIndex = 0;
  int byteIndex = 0;

  for(int i = 0; i < mat->rows; i++)
  {
    uchar* rowData = (uchar*)mat->ptr(i); // points to the beginning of the i'th row
    for(int j = 0; j < mat->cols; j++)
    {
      uchar pixel = rowData[j];
      bytes[byteIndex].set(bitIndex, rowData[j]);
      bitIndex = (bitIndex + 1) % BYTE_SIZE;
      byteIndex = bitIndex == 0 ? byteIndex + 1 : byteIndex;
    }
  }
}

}
