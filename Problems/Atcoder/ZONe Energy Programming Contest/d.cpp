#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        string t;
        vector<int> rev;
        for(int i = 0;i<n;i++){
            if(s[i]!= 'R')t.push_back(s[i]);
            else rev.push_back(i-rev.size());
        }
        for(auto c:rev)cout<<c<<" ";
        cout<<endl;
        int ans = 0;
        for(int i = 0;i<n;){
            int j = i;
            while(j<t.size() &&t[i]== t[j]){
                j++;
            }
            if((j-i)&1)
        }
    }
    return 0;
}  
