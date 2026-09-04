#include <iostream>
#include <fstream>

#include "image_functions.h"


/*  Function ProcessImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none
 */
// Only modify if adding another processing option
void ProcessImage(char choice, std::vector<std::vector<Pixel> >& image) {
  // get filename, width and height from user
  std::string originalImageFilename;
  std::cout << "Image filename: ";
  std::cin >> originalImageFilename;

  // load image
  if (!LoadImage(originalImageFilename, image)) {
    std::cout << "Image did not load, returning." << std::endl;
    return;
  }

  std::string OutputImageFilename;

  // modify image
  switch (toupper(choice)) {
    case 'G':
      GrayscaleImage(image);
      OutputImageFilename = "grey." + originalImageFilename;
      break;
    case 'S':
      SepiaImage(image);
      OutputImageFilename = "sepia." + originalImageFilename;
      break;
    case 'N':
      InvertImage(image);
      OutputImageFilename = "invert." + originalImageFilename;
      break;
    case 'I':
      GrayscaleInvertImage(image);
      OutputImageFilename = "gray.invert." + originalImageFilename;
      break;
  }

  // output image
  OutputImage(OutputImageFilename, image);
}


/*  Function LoadImage
 *  filename: string which is the ppm file to read
 *  image: 2d-vector of Pixels (structs)
 *  return: true if load successful, false otherwise; but image array should be loaded with values from file
 */
// Do not modify
bool LoadImage(const std::string filename,
  std::vector<std::vector<Pixel> >& image) {
  std::cout << "Loading image..." << std::endl;
  std::ifstream ifs(filename);  // input file stream opened with filename

  // check if it's open
  if (!ifs.is_open()) {
    std::cout << "Unable to open file: " + filename << std::endl;
    return false;
  }

  // we were able to open the file

  // read in Image type, for us it must be P3
  std::string type;
  ifs >> type;

  // read in width and height
  unsigned int width = 0, height = 0;
  ifs >> width >> height;

  // initalize image Pixels
  image.clear();
  for (unsigned int row=0; row < height; ++row) {
    image.push_back(std::vector<Pixel>(width, Pixel({0, 0, 0})));
  }

  // read in maximum color value, for us it must be 255
  unsigned int maxColor = 0;
  ifs >> maxColor;

  // read the color values into the 2D vector
  for (unsigned int row=0; row < height; ++row) {
    std::vector<Pixel> column;
    for (unsigned int col=0; col < width; ++col) {
      ifs >> image.at(row).at(col).r;
      ifs >> image.at(row).at(col).g;
      ifs >> image.at(row).at(col).b;
    }
  }

  return true;
}


/*  Function OutputImage
 *  filename: string which is the ppm file to write
 *  image: 2d-vector of Pixels (structs)
 *  Return value: true if output successful, false otherwise; but ppm file should be created
 */
// Do not modify
bool OutputImage(const std::string filename,
  const std::vector<std::vector<Pixel> >& image) {
  std::cout << "Outputting image..." << std::endl;

  // open output file
  std::ofstream ofs(filename);

  if (!ofs.is_open()) {
    std::cout << "Unable to create output file: " + filename << std::endl;
    return false;
  }

  // output image type, P3 for us
  ofs << "P3" << std::endl;

  // output width and height, don't forget to separate by a space
  ofs << image.at(0).size() << " " << image.size() << std::endl;

  // output max color value, for us 255
  ofs << 255 << std::endl;

  // output into row major PPM file
  for (unsigned int row=0; row < image.size(); ++row) {
    for (unsigned int col=0; col < image.at(row).size(); ++col) {
      ofs << image.at(row).at(col).r << " ";
      ofs << image.at(row).at(col).g << " ";
      ofs << image.at(row).at(col).b << " ";
    }
    ofs << std::endl;
  }

  return true;
}


/*  Function grayscale
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be grayscale colors
 * 
 *  Note: computing grayscale as the average of the R,G,B chanels for each pixel
 */
void GrayscaleImage(std::vector<std::vector<Pixel> >& image) {
  std::cout << "Making grayscale image... " << std::endl;

  // iterate through 2d image of Pixels and convert them to grayscale
  // use opposite outer loop than load and output just to be different
  for (unsigned int row=0; row < image.size(); ++row) {
    for (unsigned int col=0; col < image.at(row).size() ; ++col) {
      unsigned int newColor = (
        image.at(row).at(col).r +
        image.at(row).at(col).g +
        image.at(row).at(col).b) / 3;
      image.at(row).at(col) = {newColor, newColor, newColor};
    }
  }
}


/*  Function SepiaImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be sepia colors
 *
 *  Note: compute sepia as follows for each pixel:
 *        new red =   0.393 * red + 0.768 * green + 0.189 * blue
 *        new green = 0.349 * red + 0.686 * green + 0.168 * blue
 *        new blue =  0.272 * red + 0.534 * green + 0.131 * blue
 *        remember that the max color we allow is 255
 */
void SepiaImage(std::vector<std::vector<Pixel> >& image) {
  std::cout << "Making sepia image... " << std::endl;
  for (int row=0; row < image.size(); ++row) {
    for (int col=0; col < image.at(row).size(); col++) {
      Pixel new_color;
      new_color.r = 0.393 * image.at(row).at(col).r +
        0.768 * image.at(row).at(col).g +
        0.189 * image.at(row).at(col).b;
      new_color.g = 0.349 * image.at(row).at(col).r +
        0.686 * image.at(row).at(col).g +
        0.168 * image.at(row).at(col).b;
      new_color.b =  0.272 * image.at(row).at(col).r +
        0.534 * image.at(row).at(col).g +
        0.131 * image.at(row).at(col).b;

      // max value is 255
      if (new_color.r > 255)
        new_color.r = 255;
      if (new_color.g > 255)
        new_color.g = 255;
      if (new_color.b > 255)
        new_color.b = 255;

      image.at(row).at(col) = new_color;
    }
  }
}


/*  Function InvertImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be inverted
 *
 *  Note: compute the inverted image by subtracting each pixel from 255
 *        (the max color we allow is 255)
 */
void InvertImage(std::vector<std::vector<Pixel> >& image) {
  std::cout << "Making invert image... " << std::endl;
  for (int row=0; row < image.size(); ++row) {
    for (int col=0; col < image.at(row).size(); col++) {
      Pixel new_color;
      new_color.r = 255 - image.at(row).at(col).r;
      new_color.g = 255 - image.at(row).at(col).g;
      new_color.b = 255 - image.at(row).at(col).b;
      image.at(row).at(col) = new_color;
    }
  }
}

/*  Function GrayscaleInvertImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be invert grayscale
 *
 *  Note: used existing functions to implement
 */
void GrayscaleInvertImage(std::vector<std::vector<Pixel> >& image) {
  GrayscaleImage(image);
  InvertImage(image);
}

