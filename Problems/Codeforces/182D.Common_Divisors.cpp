#include <bits/stdc++.h>
using namespace std;
string s,t;
bool check(int l,int who){
	int n;
	string str;
	if(who)
		str = s;
	else str = t;
	n = str.size();
	for(int i = 1;i<n/l;i++){
		int of = i*l;
		for(int j = 0;j<l;j++){
			if(str[j] != str[of+j])return false;
		}
	}
	return true;
}
int main(){
	cin>>s>>t;
	int n = s.size();
	int n2 = t.size();
	vector<int> divs;
	vector<int> divs2;
	if(s[0]!= t[0])return cout<<0<<endl,0;
	for(int i = 1;i*i<=n;i++){
		if(n%i == 0){
			divs.push_back(i);
			if(n/i != i)divs.push_back(n/i);
		}

	}	
	for(int i = 1;i*i<=n2;i++){
		if(n2%i == 0){
			divs2.push_back(i);
			if(n2/i != i)divs2.push_back(n2/i);
		}
	}
	sort(divs.begin(),divs.end());
	sort(divs2.begin(),divs2.end());
	int i = 0,j = 0;
	int ans = 0;
	
	while(i<divs.size() && j<divs2.size()){
		if(divs[i]== divs2[j]){
			if(check(divs[i],1) && check(divs[i],0)){
				string ss = s.substr(0,divs[i]);
				string st = t.substr(0,divs[i]);
				if(ss == st)ans++;
			}
			i++,j++;
		}
		else if(divs[i]>divs2[j])j++;
		else if(divs2[j]>divs[i])i++;
	}
	cout<<ans<<endl;
}

