
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,q,x1,y1,x2,y2;
    cin>>n>>m;
    cin>>q;
    vector<int> mpM(m+1);
    vector<int> mpN(n+1);
    for(int i = 1;i<m;i++){
        mpM[__gcd(i,m)]++;
    }

    for(int i = 1;i<n;i++){
        mpN[__gcd(i,n)]++;
    }
    for(int i = 0;i<q;i++){
        cin>>x1>>y1>>x2>>y2;
        int x = x1-x2;
        (x+=n)%=n;
        if(x==0)x = n;
        int ansx = 0;
        for(int j = 1;j*j<=x;j++){
            if(x%j ==0){
                ansx+=mpN[j];
                if((x/j)!=j)
                    ansx+=mpN[x/j];
            }
        }

        int y = y1-y2;
        (y+=m)%=m;
        if(y==0)y = m;
        int ansy = 0;
        for(int j = 1;j*j<=y;j++){
            if(y%j ==0){
                ansy+=mpM[j];
                if((y/j) != j)
                    ansy+=mpM[y/j];
            }
        }
        cout<<ansx*ansy<<endl;
    }
    return 0;
}  
