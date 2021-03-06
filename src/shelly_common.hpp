/*
 * Copyright (c) 2020 Deomid "rojer" Ryabkov
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <functional>
#include <memory>
#include <string>

#include "common/cs_dbg.h"
#include "common/util/status.h"
#include "common/util/statusor.h"

namespace shelly {

using mgos::Status;
using mgos::StatusOr;

using namespace std::placeholders;  // _1, _2, ...

inline const char *OnOff(bool on) {
  return (on ? "on" : "off");
}

inline const char *YesNo(bool yes) {
  return (yes ? "yes" : "no");
}

// TODO(rojer): Move upstream.
#define LOG_EVERY_N(l, n, x)                                              \
  do {                                                                    \
    static int cnt = 0;                                                   \
    if (cnt++ % (n) == 0 && cs_log_print_prefix(l, __FILE__, __LINE__)) { \
      cs_log_printf x;                                                    \
    }                                                                     \
  } while (0)

}  // namespace shelly
