#include <iostream>
using namespace std;
long long int  s(string n){
	long long int ans = 0;
	int size = n.size();
	acMod[size];
	acMod[0] = 0;
	for(int i = 0;i<size;i++){
		acMod[i+1] = (acMod[i] + n[i]-'0')%3;
	}
	for(int i = 0;i<size;i++){
		if(!acMod)ans++;
	}
	return ans;

}

int main(){
	string s;
	int i = 0;
	while (cin >> s) {
		int n = s.size();
		string numPart = "";
		long long ans = 0LL;
		i = 0;
		while (i < n) {
			if (s[i]>'0' && s[i]<'9') numPart += s[i];
			else {
				if (numPart != "") ans += Sol(numPart);
				numPart = "";
			}
			i++;
		}
		if (numPart != "") ans += solve(numPart); 
		cout << ans << 'n';
	}
	return 0;   
}

