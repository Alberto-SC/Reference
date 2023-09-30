#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<string> s(n);
        for(auto &c:s)cin>>c;
        for(int i = 0;i<n;i++)
            sort(s[i].rbegin(),s[i].rend());
        sort(s.begin(),s.end(),[&](string a,string b){
            int n = min(a.size(),b.size());
            for(int i = 0;i<n;i++){
                if(a[i]>b[i])return true;
                else return false;
            }
            return a.size()<b.size();
        });
        for(int i = 0;i<n;i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}  
