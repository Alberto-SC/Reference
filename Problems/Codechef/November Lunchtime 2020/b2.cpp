#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,x,y,n;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        bitset<32> bx(x);
        bitset<32> by(y);
        bitset<32> bn(n);
        int ans = 0;
        // cout<<bx<<endl<<by<<endl<<bn<<endl;
        for(int i= 31;i>=0;i--){
            if(bx[i]!= by[i]){
                // cout<<i<<endl;
                int maskL = (n>>(i+1));
                int maskR = (n&((1<<i)-1));
                int R = pow(2,i);
                // cout<<maskL<<" "<<maskR<<" "<<R<<endl;
                if(!bx[i] && by[i] && !bn[i])
                    ans = (maskL*R)+maskR+1;
                else if(!bx[i] && by[i] && bn[i])
                    ans = ((maskL+1)*R);
                else if(bx[i] &&!by[i] && bn[i])
                    ans = (maskL*R)+maskR+1;
                else if(bx[i] &&!by[i] && !bn[i])
                    ans = (maskL*R);
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

