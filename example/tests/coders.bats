#!/usr/bin/env bats

# Copyright (C) 2020 IBM Corp.
# This program is Licensed under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#   http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License. See accompanying LICENSE file.

function techo {
  while IFS= read -r line; do
    echo "# $line" >&3
  done <<< "$1"
}

function assert {
  if "$@"; then
    return 0
  else
    techo "Output: $output"
    techo "Status: $status"
    return 1
  fi
}

@test "basic line 1" {
  run ../build/ci_test_example
  assert [ "$status" -eq 0 ]
  assert [ "${lines[0]}" == "header name: ci_test_h" ]
}

@test "basic line 2" {
  run ../build/ci_test_example
  assert [ "$status" -eq 0 ]
  assert [ "${lines[1]}" == "cpp name:    ci_test_cpp" ]
}
