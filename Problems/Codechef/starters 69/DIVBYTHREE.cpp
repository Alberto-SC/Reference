#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int Ones(int x){
    if(x == 1)return 6;
    if(x == 2)return 5;
    if(x == 3)return 4;
    int y = x/4;
    if(x%4)y++;
    return (y*3) + (4-(x%4));
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int c1 = 0,c2 = 0,c0 = 0; 
        for(auto &c:nums){
            cin>>c;
            c%=3;
            c1+=c==1;
            c2+=c==2;
            c0+=c==0;
        }
        int ans = 0;
        while(c0){
            if(c1+1<=c2 &&c1){
                c1++;
                ans++;
                c0--;
            }
            else if(c2+1<=c1 && c2){
                c2++;
                ans++;
                c0--;
            }
            else break;
        }
        int mn = min(c1,c2);
        ans += mn;
        c1-=mn;
        c2-=mn;
        c0+=mn*2;
        if(c2){ 
            if(c2==1)ans+=7;
            else if(c2 ==2)ans+=6;
            else ans+=(c2+1)/2 +Ones(c2-2);
            
        }
        else if(c1){
            ans+=Ones(c1);
        }
        cout<<ans<<endl;
    }
    return 0;
}