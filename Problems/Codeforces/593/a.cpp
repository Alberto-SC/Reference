#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int ans = 0;
        while(1){
            if(c-2>=0 && b-1>=0){
                ans+=3;
                b--;
                c-=2;
            }
            else break;
        }
        while(1){
            if(b-2>=0 && a-1>=0){
                ans+=3;
                b-=2;
                a--;
            }
            else break;
        }
        cout<<ans<<endl;

    }
    return 0;
}  

