// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2017 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

using namespace std;

typedef int gph[502][502];

int dcnt;

void mul(gph x, gph y) { // mul_equ: *=
	gph ret; memset(ret, 0x3f, 502 * 502 << 2);
	for (int k = 1; k <= dcnt; k++) {
		for (int i = 1; i <= dcnt; i++) {
			for (int j = 1; j <= dcnt; j++) {
				ret[i][j] = min(ret[i][j], x[i][k] + y[k][j]);
			}
		}
	}
	memcpy(x, ret, 502 * 502 << 2);
}

void pow(gph base, int exp, gph res) {
	memcpy(res, base, 502 * 502 << 2); exp--; // 弃单位矩阵的新科技
	while (exp) {
		if (exp&1) mul(res, base);
		mul(base, base);
		exp >>= 1;
	}
}

int n, t, s, e, x, y, z;
int disc[1000006];
gph rec, ans;

int main() {
	memset(rec, 0x3f, sizeof rec);
	for (scanf("%d%d%d%d", &n, &t, &s, &e); t--; ) {
		scanf("%d%d%d", &x, &y, &z);
		if (!disc[y]) disc[y] = ++dcnt;
		if (!disc[z]) disc[z] = ++dcnt;
		rec[disc[y]][disc[z]] = rec[disc[z]][disc[y]] = x;
	}
	pow(rec, n, ans);
	printf("%d", ans[disc[s]][disc[e]]);
	return 0;
}