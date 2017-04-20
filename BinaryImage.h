#ifndef BINARYMAT_H
#define BINARYMAT_H

#include "opencv2\core\core.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <cmath>
#include "Byte.h"

#define BYTE_SIZE 8

namespace aa
{

class BinaryMat
{
public:
  BinaryMat(const cv::Mat* mat);
  ~BinaryMat();
  void setMat(const cv::Mat* mat);
  bool matFromBytes(cv::Mat* mat);
  int rows();
  int cols();

private:
  void setVariables(int rows, int cols);
  int getBytesSize();
  void bytesFromMat(const cv::Mat* mat);

  Byte *bytes;
  int r;
  int c;
};

}
#endif
