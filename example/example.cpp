#include <prelude.h>
#include <iostream>

int main(int argc, char** argv) {
  if (argc > 1) {
    std::cout << "Bad..." << std::endl;
  }
  std::cout << "header name: " << ci_test::get_name_h() << std::endl;
  std::cout << "cpp name:    " << ci_test::get_name_cpp() << std::endl;

  return EXIT_SUCCESS;
}