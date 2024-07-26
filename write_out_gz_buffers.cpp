#include <fstream>
#include <cstdint>
#include "camera_index.h"

int main(int argc, char *argv[]) {
  std::ofstream ofs("index_ov2640.html.gz", std::ios::binary);
  if (ofs.is_open()) {
    ofs.write((const char *)index_ov2640_html_gz, index_ov2640_html_gz_len);
    ofs.close();
  }

  ofs.open("index_ov3660.html.gz", std::ios::binary);
  if (ofs.is_open()) {
    ofs.write((const char *)index_ov3660_html_gz, index_ov3660_html_gz_len);
    ofs.close();
  }

  ofs.open("index_ov5640.html.gz", std::ios::binary);
  if (ofs.is_open()) {
    ofs.write((const char *)index_ov5640_html_gz, index_ov5640_html_gz_len);
    ofs.close();
  }

  return 0;
}