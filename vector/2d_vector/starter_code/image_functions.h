#ifndef IMAGE_FUNCTIONS_H_
#define IMAGE_FUNCTIONS_H_

#include <string>
#include <vector>

struct Pixel {
  unsigned int r = 0;  // red
  unsigned int g = 0;  // green
  unsigned int b = 0;  // blue
};

void ProcessImage(char choice, std::vector<std::vector<Pixel> >& image);

bool LoadImage(const std::string filename,
  std::vector<std::vector<Pixel> >& image);

bool OutputImage(const std::string filename,
  const std::vector<std::vector<Pixel> >& image);

void GrayscaleImage(std::vector<std::vector<Pixel> >& image);

void SepiaImage(std::vector<std::vector<Pixel> >& image);

void InvertImage(std::vector<std::vector<Pixel> >& image);

#endif  // IMAGE_FUNCTIONS_H_
