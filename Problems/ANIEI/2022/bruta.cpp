#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

bool isSet(int x,int j){
    return (x>>j)&1;
}

signed main(){
    int last = 0;
    int ac = 0;
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cout<<"N: "<<i<<" ";
        int ans = 0;
        for(int mask = 0;mask<(1<<i);mask++){
            bool flag = false;
            for(int k = 0;k<i;){
                int j = k;
                while(j<i && isSet(mask,j) == isSet(mask,k)){
                    j++;
                }
                if((j-k)&1 && isSet(mask,k))flag = true;
                k = j;
            }
            if(flag)ans++;
        }
        int diff = ans-(last*2);
        ac+=ans;
        cout<<ans<<" "<<ac<<endl;
        last = ans;
    }
    return 0;
}
