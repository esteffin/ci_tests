#include <prelude.h>

int main(int argc, char** argv) {
  if (argc > 1) {
    return EXIT_FAILURE;
  }
  std::string header_name = ci_test::get_name_h();
  std::string src_name = ci_test::get_name_cpp();

  if (header_name.substr(0, 7) != src_name.substr(0, 7)) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
