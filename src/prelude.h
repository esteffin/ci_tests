#ifndef CI_TEST_PRELUDE
#define CI_TEST_PRELUDE

#include <string>

namespace ci_test {

inline std::string get_name_h() { return "ci_test_h"; }

std::string get_name_cpp();

} // namespace ci_test

#endif // CI_TEST_PRELUDE
