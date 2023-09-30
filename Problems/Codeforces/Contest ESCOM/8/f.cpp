#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string last="1000",s;
	vector<string> sol;
    bool yes = true;
	for(int i=0;i<n;i++){
		cin>>s;
		string minpos="2012",temp;
		for(int i=0;i<4;i++){
			for(int j=0;j<10;j++){
				temp=s;
				temp[i]='0'+j;
				if(temp>=last)
					minpos=min(temp,minpos);
			}
        }
		if(minpos>"2011")
			yes = false;
		last=minpos;
		sol.push_back(minpos);
    }
    if(yes)
        for(auto c: sol)cout<<c<<endl;
    else cout<<"No solution"<<endl;
    return 0;
}
