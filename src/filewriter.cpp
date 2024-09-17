#include "filewriter.hpp"
#include <iostream>

FileWriter::FileWriter() : FileWriter("image.ppm") {}

FileWriter::FileWriter(const std::string& name) {
  this->name = name;
  this->outfile.open(this->name, std::ios::out);
}

FileWriter::~FileWriter() { this->close(); };

const std::string FileWriter::get_Name() { return this->name; }

void FileWriter::set_Name(const std::string& Name) { this->name = Name; }

void FileWriter::addline(const std::string& line) {
  this->outfile << line << std::endl;
}
void FileWriter::add_color(const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // Translate the [0,1] component values to the byte range [0,255].
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);
  this->addline(std::to_string(rbyte) + " " + std::to_string(gbyte) + " " +
                         std::to_string(bbyte));
}

void FileWriter::close() { this->outfile.close(); }
