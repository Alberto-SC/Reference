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
        int f = -1, l = -1;
        for(int i= 0;i<n;i++)
            if(s[i]== '1')l = i;
        for(int i = n-1;i>=0;i--)
            if(s[i]== '1')f = i;
        if(f==-1)cout<<n<<endl;
        else {
            cout<<max((n-f)*2,(l+1)*2)<<endl;
        }
    }
    return 0;
}

