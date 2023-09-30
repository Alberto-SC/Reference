#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__    
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n%7==0)cout<<n<<endl;
        else{
            int d1 = n%7,d2 = 7-(n%7);
            string s = to_string(n);
            int digit = s.back()-'0';
            if(digit-d1>=0)s.back() = char('0'+ (digit-d1));
            else s.back() = char('0'+ digit+d2);
            cout<<s<<endl;
        }   

    }

}