#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
	while (cin>>s) {
		list<char> l;
		int n = s.size();
		list<char>::iterator it = l.begin();
		for (int i = 0; i < n; i++) {
			if (s[i] == '[') 
				it = l.begin();
			else if (s[i] == ']') 
				it = l.end();
			else
				l.insert(it, s[i]);
		}
		for (it = l.begin(); it != l.end(); it++) {
			printf("%c",*it);
		}
		cout<<endl;

	}
    return 0;
}