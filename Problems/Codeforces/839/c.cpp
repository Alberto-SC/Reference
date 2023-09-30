#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>k>>n;
        cout<<1<<" ";
        int diff = 1,last = 1;
        int left = k-1;
        for(int i = 0;i<k-1;i++){
            if(n-(last+diff)>=left-1){
                cout<<last+diff<<" ";
                last+=diff;          
                diff++;
                left--;
            }
            else{
                break;
            }
        }
        for(int i = 0;i<left;i++){
            cout<<last+1<<" ";
            last++;
        }
        cout<<endl;
    }
    return 0;
}