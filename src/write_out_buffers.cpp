#ifndef ARDUINO
#include "include/camera_index.h"
#include <fstream>

int main(int argc, char *argv[]) {
  std::ofstream ofs("index_ov2640.html.br", std::ios::binary);
  if (ofs.is_open()) {
    ofs.write((const char *)index_ov2640_html_br, index_ov2640_html_br_len);
    ofs.close();
  }

  ofs.open("index_ov3660.html.br", std::ios::binary);
  if (ofs.is_open()) {
    ofs.write((const char *)index_ov3660_html_br, index_ov3660_html_br_len);
    ofs.close();
  }

  ofs.open("index_ov5640.html.br", std::ios::binary);
  if (ofs.is_open()) {
    ofs.write((const char *)index_ov5640_html_br, index_ov5640_html_br_len);
    ofs.close();
  }

  return 0;
}
#endif
