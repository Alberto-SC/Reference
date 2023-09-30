#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        string t(n,'0');
        for(int i = 0,j = 0;i<(2*n)-1;i+=2,j++){
            t[j] = s[i];
        }
        cout<<t<<endl;

    }
    return 0;
}

