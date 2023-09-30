#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> b(k);
        iota(b.begin(),b.end(),1);
        int diff = n-k;
        diff++;
        reverse(b.begin()+(k-diff),b.end());
        for(auto c:b)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

