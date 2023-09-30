#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,q,u,v;
    cin>>q;
    for(int x = 0;x<q;x++){
        cin>>u>>v;
        if(u>v){
            cout<<"NO"<<endl;
            continue;
        }
        vector<int> b1(40),b2(40);
        for(int i= 29;i>=0;i--){
            if((u>>i)&1)b1[i] = 1;
            if((v>>i)&1)b2[i] = 1;
        }
        int c1 = 0,  c2 = 0;
        bool m = false,flag = true;
        for(int j =0;j<35;j++){
            c1+=b1[j];
            c1-=b2[j];
            if(c1<0){
                flag = false;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
 
    return 0;
}  
