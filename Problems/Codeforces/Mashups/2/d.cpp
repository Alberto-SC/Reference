#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int N = 20000;
signed main(){__
	int t= 1,n,a,b,c,A,B,C;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int mn = 1e15;
        int x,y,my;
        for(int i = 1;i<=N;i++){
            x = abs(a-i);
            my = 1e15;
            for(int j = 1;i*j<=N;j++){
                y = abs((i*j)-b);
                if(c<(i*j))y +=(i*j)-c;
                else y+=min((i*j)-(c%(i*j)),c%(i*j));
                my = min(my,y);
            }
            if(x+my<mn){
                mn = min(x+my,mn);
                A = i; 
            }
        }
        my = 1e15;
        for(int i = 1;A*i<=N;i++){
            y = abs((A*i)-b);
            if(c<(A*i))y+=(i*A)-c;
            else y+=min((i*A)-(c%(i*A)),c%(i*A));
            if(y<my){
                my = min(my,y);
                B = A*i;
                if(c<B)C = B;
                else if(B-(c%B)< c%B)C = c+(B-(c%B));
                else C = c-(c%B);                    
            }
        }
        cout<<mn<<endl;
        cout<<A<<" "<<B<<" "<<C<<endl;
    }
    return 0;
}  
