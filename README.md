# BinaryImage

In short, BinaryImage is a little C++ class that serializes an OpenCV Mat object containing a binary image (Black/White).
OpenCV binary image pixels are actually still byte sized (i.e. each value is 11111111 or 00000000), so this class uses a single bit for each pixel instead (i.e. 1 or 0), theoretically reducing the size by 8.

## Reason

I was working on my Masters thesis, and I needed to do some work on HUGE binary images (encryption, bit operations, communications and data sending), so I thought of serializing it into this format

## What Now?

I don't know if this is something that is useful or something that is absolutely not needed. It is just my first OSS idea that I wanted to implement.

# Usage

### NOTE: This class has dependency on OpenCV

 1. Download the files and include them in your project
 2. Create a BinaryImage object and provide the Mat object of the binary image
```cpp
cv::Mat binaryMat = /* ... */
BinaryImage binaryImage(binaryMat);
```
 3. Use the BinaryImage object
 4. Reconstruct the Mat object from the BinaryImage object
```c++
cv::Mat reconstructedBinaryMat = binaryImage.matFromBytes();
```


# Future

In the future, I would like to add more functionality to this class, like accessing/manipulating specific bits/pixels, etc.

# License

MIT License! :)
