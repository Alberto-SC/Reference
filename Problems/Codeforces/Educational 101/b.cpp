#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        cin>>m;
        vector<int> b(m);
        for(auto &c:b)cin>>c;
        int pref1 = 0,mx1 = 0;
        int pref2 = 0,mx2 = 0;
        for(int i = 0;i<n;i++){
            pref1+=a[i];
            mx1 = max(mx1,pref1);
        }
        for(int i =0;i<m;i++){
            pref2+=b[i];
            mx2 = max(mx2,pref2);
        }
        cout<<mx1+mx2<<endl;
    }
    return 0;
}  

