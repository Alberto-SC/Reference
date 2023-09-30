/**
 * Author: Cp-Algorithms / Alberto SIlva
 * License: MIT
 * Description: pi[x] computes the length of the longest prefix of s that ends at x, other than s\[0...x\] itself (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */
#pragma once

vector<int> p_function(const string& v){
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i]){
            j = p[j - 1];
        }
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}
bool match(const string& s, const string& pat) {
	int n = pat.size();
	int m = s.size();
	if(m<n)
		return false;

	string match = pat+"#"+s;
	vector<int> kmp =p_function(match);
	for(int i = 0; i < m - n + 1; i++){   
		if(kmp[2 * n + i] == n){   
            return true;
        }
    }
    return false;
}

