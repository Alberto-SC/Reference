#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
    int T = 1,n,x,y;
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            if(j==i+1|| i == j+1)continue;
            int x = i;
            int y = j;
            int cont = 0;
            cout<<x<<" "<<y<<" "<<max(x,y)-min(x,y)<<" ";
            while(__gcd(x,y)==1){
                cont++;
                x++;
                y++;
            }
            cout<<cont<<" "<<__gcd(x,y)<<endl;
        }
    }
    return 0;
}