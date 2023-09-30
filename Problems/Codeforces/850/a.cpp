#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int aw = 1,ab = 0,bw = 0,bb = 0;
        int c = 2;
        n--;
        int turn = 0;
        while(n){
            int x = min(c,n);
            n-=x;
            if(turn%4 == 2 || turn%4 == 3){
                aw+=(x+1)/2;
                ab+=x-((x+1)/2);
            }
            else{
                bb+=(x+1)/2;
                bw+=x-((x+1)/2);
            }
            turn++;
            c++;
        }
        cout<<aw<<" "<<ab<<" "<<bw<<" "<<bb<<endl;
    }
    return 0;
}