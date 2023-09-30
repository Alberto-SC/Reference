#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<string> _all;
signed main(){__
	int t= 1,n;
    for(int x = 2;x<=10;x+=2){
        for(int mask = 0;mask<(1<<x);mask++){
            string str = "";
            for(int i = 0;i<x;i++){
                if((mask>>i)&1)
                    str+='7';
                else 
                    str+='4';
            }
            _all.push_back(str);
        }
    }
    vector<int> lucky;
    for(auto c:_all){
        int c4 = 0,c7 = 0;
        for(int i = 0;i<c.size();i++){
            c4+=c[i]=='4';
            c7+=c[i]=='7';
        }
        if(c4 ==c7)
            lucky.push_back(stoll(c));
        
    }
    sort(lucky.begin(),lucky.end());
    cin>>n;
    
    int idx = lower_bound(lucky.begin(),lucky.end(),n)-lucky.begin();
    cout<<lucky[idx]<<endl;
    return 0;
}  
