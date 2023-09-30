#include <bits/stdc++.h>
using namespace std;
vector<int> z;
int n;
void z_function(string s){
    z[0] = 0;
    for(int i = 1,l = 0,r = 0;i<n;i++){
        if(i<=r)
            z[i] = min(z[i-l], r-i+1);
        while(i + z[i]<n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if(i+z[i]-1>r)
            l = i,r = i+z[i]-1;
    }
}
  
int len = 0; 
vector<int> bit; 
void update(int idx, int val) { 
	if (idx == 0) 
		return; 
	while (idx <= n) { 
		bit[idx] += val; 
		idx += (idx & -idx); 
	} 
} 
int pref(int idx) { 
	int ans = 0; 
	while (idx > 0) { 
		ans += bit[idx]; 
		idx -= (idx & -idx); 
	} 
	return ans; 
} 
int main() { 
	string s ; 
	cin>>s;
    n = s.size(); 
    z.resize(n);
    bit.resize(n+1);
	z_function(s); 
	for (int i = 1; i < n; i++) { 
		update(z[i], 1); 
	} 

	for (int i = n - 1; i > 1; i--) { 
		if (z[i] != (n - i)) 
			continue; 
		if (pref(n) - pref(z[i] - 1) >= 2) { 
			len = max(len, z[i]); 
		} 
	} 
	if (!len) 
		cout << "Just a legend"; 
	else
		cout << s.substr(0, len); 
	return 0; 
} 