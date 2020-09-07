/* Copyright (C) 2020 IBM Corp.
 * This program is Licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. See accompanying LICENSE file.
 */

#ifndef CI_TEST_PRELUDE
#define CI_TEST_PRELUDE

#include <string>

namespace ci_test {

inline std::string get_name_h() { return "ci_test_h"; }

std::string get_name_cpp();

} // namespace ci_test

#endif // CI_TEST_PRELUDE
