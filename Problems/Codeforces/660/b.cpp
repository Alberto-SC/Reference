#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
	lli t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s = string(n,'8');
        int x = ceil(n/4.0);
        for(int i = 0;i<n-x;i++)s[i] = '9';
        cout<<s<<endl;
    }
    return 0;
}  