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
        if(n == 1)cout<<0<<endl;
        else{
            int ans =1000000; 
            for(int i = 1;i<100000;i++){
                if(n%i == 0)
                    ans = min(i+(n/i),ans);
                else 
                    ans = min(i+(n/i)+1,ans);
            }
            cout<<ans-2<<endl;
        }
    }
    return 0;
}

