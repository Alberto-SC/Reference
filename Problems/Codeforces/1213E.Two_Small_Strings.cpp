#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
	string s, t;
	cin>>n;
    cin>>s>>t;
	string abc = "abc";
	vector<string> poss;
	do { 
		string aux;
		for (int i = 0; i < n; i++) aux += abc;
		poss.push_back(aux);
		poss.push_back(string(n, abc[0]) + string(n, abc[1]) + string(n, abc[2]));
	} while (next_permutation(abc.begin(), abc.end()));
	for (auto str : poss) {
		if (str.find(s) == string::npos && str.find(t) == string::npos) {b b 
			cout << "YES" << endl << str << endl;
			return 0;
		}
	}	
    return 0;
}