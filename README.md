# BinaryMat

In short, BinaryMat is a little C++ class that serializes an OpenCV Mat object containing a binary image (Black/White) into a format where each pixel is represented by a signle bit.
OpenCV binary image pixels are in fact byte sized (i.e. each value is 11111111 or 00000000), which is counter intuitive to using a single bit for each pixel, so this class uses a single bit for each pixel instead (i.e. 1 or 0), theoretically reducing the size by around 8 times.

## Motivation

I was working on my Masters thesis, and I needed to do some work on HUGE binary images (encryption, bit operations, and communications), so I thought of serializing it into this format

# Usage

### NOTE: This class has dependency on OpenCV

 1. Download the files and include them in your project
 2. Create a BinaryMat object and provide the Mat object of the binary image
```cpp
cv::Mat binaryImage = /* ... */
BinaryMat binaryMat(binaryImage);
```
 3. Use the BinaryMat object
 4. Reconstruct the binary image Mat object from the BinaryMat object
```cpp
cv::Mat reconstructedBinaryMat = binaryMat.matFromBytes();
```


# Future

I don't know if this is something that is useful or something that is absolutely not needed. It is just my first OSS idea that I wanted to implement.

In the future, I would like to add more functionality to this class, like accessing/manipulating specific bits/pixels, etc.

# License

MIT License! :)
