#ifndef FILEWRITER
#include "color.hpp"
#include <fstream>
#include <string>

class FileWriter {
public:
  FileWriter();
  FileWriter(const std::string& name);
  virtual ~FileWriter();
  const std::string get_Name();
  void set_Name(const std::string& Name);
  void addline(const std::string& line);
  void add_color(const color& pixel_color);
  void close();

private:
  std::string name;
  std::ofstream outfile;
};

#endif // !
