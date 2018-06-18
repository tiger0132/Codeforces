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

struct node {
	int l, p, s;
	bool operator<(const node& rhs) const {
		return s < rhs.s;
	}
} rec[102];

int dp[110][16010];
int que[16010];
int head, tail;
int n, k;

int val(int x, int y) {
	return dp[x-1][y] - rec[x].p * y;
}

void add(int i, int x) {
	while (head <= tail && val(i, que[tail]) <= val(i, x)) tail--;
	que[++tail] = x;
}

int query(int i, int j) {
	while (head <= tail && que[head] < j - rec[i].l) head++;
	if (head <= tail) return val(i, que[head]);
	return 0xcfcfcfcf;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &rec[i].l, &rec[i].p, &rec[i].s);
	}
	sort(rec+1, rec+k+1);
	for (int i = 1; i <= k; i++) {
		head = 1; tail = 0;
		for (int j = max(rec[i].s - rec[i].l, 0); j < rec[i].s; j++) add(i, j);
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (j >= rec[i].s) dp[i][j] = max(dp[i][j], query(i, j) + rec[i].p * j);
		}
	}
	printf("%d", dp[k][n]);
	return 0;
}