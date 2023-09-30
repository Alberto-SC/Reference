#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}  

