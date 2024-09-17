#include "filewriter.hpp"
#include "color.hpp"
#include "vec3.hpp"

#include <iostream>
#include <string>

int main() {
  // Image
  int image_width = 256;
  int image_height = 256;
  int color_max = 255;
  std::string filename = "image.ppm";


  // Output File 
  FileWriter outputFile = FileWriter(filename);
  outputFile.addline("P3");
  outputFile.addline(std::to_string(image_width) + " " +
                     std::to_string(image_height));
  outputFile.addline(std::to_string(color_max));

  // Render
  for (size_t j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;

    for (size_t i = 0; i < image_width; i++) {
      auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
      outputFile.add_color(pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
  outputFile.close();
}
