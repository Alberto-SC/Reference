/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: Wikipedia
 * Description: Recovers any $n$-order linear recurrence relation from the first
 * $2n$ terms of the recurrence.
 * Useful for guessing linear recurrences after brute-forcing the first terms.
 * Should work on any field, but numerical stability for floats is not guaranteed.
 * Output will have size $\le n$.
 * Usage: berlekampMassey({0, 1, 1, 3, 5, 11}) // {1, 2}
 * Time: O(N^2)
 * Status: bruteforce-tested mod 5 for n <= 5 and all s
 */
#pragma once

#include "ModPow()"

vector<int> berlekampMassey(vector<int> s) {
	int n = sz(s), L = 0, m = 0;
	vector<int> C(n), B(n), T;
	C[0] = B[0] = 1;

	int b = 1;
	for(int i = 0;i<n;i++){
		++m;
		int d = s[i] % mod;
		for(int j = 1;j<L+1) d = (d + C[j] * s[i - j]) % mod;
		if (!d) continue;
		T = C; int coef = d * modpow(b, mod-2) % mod;
		for(int j = m;j<n;j++) C[j] = (C[j] - coef * B[j - m]) % mod;
		if (2 * L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}

	C.resize(L + 1); C.erase(C.begin());
	for (int& x : C) x = (mod - x) % mod;
	return C;
}
