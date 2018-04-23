/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

//       reverse_iterator rend();
// const_reverse_iterator rend() const;

#include <string>
#include <cassert>
#include "libcxx_tc_common.h"
#include <cstddef>


template <class S>
static int
test(S s)
{
    const S& cs = s;
    typename S::reverse_iterator e = s.rend();
    typename S::const_reverse_iterator ce = cs.rend();
    if (s.empty())
    {
        TC_ASSERT_EXPR(e == s.rbegin());
        TC_ASSERT_EXPR(ce == cs.rbegin());
    }
    TC_ASSERT_EXPR(static_cast<std::size_t>(e - s.rbegin()) == s.size());
    TC_ASSERT_EXPR(static_cast<std::size_t>(ce - cs.rbegin()) == cs.size());
    return 0;
}

int tc_libcxx_strings_string_iterators_rend(void)
{
    {
    typedef std::string S;
    TC_ASSERT_FUNC((test(S())));
    TC_ASSERT_FUNC((test(S("123"))));
    }
    TC_SUCCESS_RESULT();
    return 0;
}
