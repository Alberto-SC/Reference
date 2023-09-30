#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int n;
    cin>>n;
    vector<int> nums(n);
    map<string,int> mp;
    for(int i = 0;i<n;i++){
        string s;
        int x;
        cin>>s>>x;
        mp[s]= x;
    }
    vector<pair<string,int>> mx;
    for(auto c:mp){
        mx.push_back(c);
    }
    sort(mx.begin(),mx.end(),[&](pair<string,int> a,pair<string,int> b){
        return a.second>b.second;
    });
    cout<<mx[1].first<<endl;
    return 0;
}  
