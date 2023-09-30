#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int getN(int x){
    return (x*(x+1))/2;
}

signed main(){__
	int t= 1,s;
    cin>>t;
    while(t--){
        cin>>s;
        int l = 0;
        for(int i = 1;i<=9;i++){
            int mn = getN(i);
            int mx = getN(9)-getN(9-i);
            if(s>=mn && s<=mx){
                l = i;
                break;
            }
        }
        int idx = 1;
        while(l){
            if((s-idx)<= (getN(9)-getN(9-(l-1)))){
                cout<<idx;
                l--;
                s-=idx;
            }
            idx++;
        }
        cout<<endl;
    }
    return 0;
}  
