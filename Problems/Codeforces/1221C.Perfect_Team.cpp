#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int ans = min({a,b,c});
        a-=ans;
        b-=ans;
        c-=ans;
        if(a== 0|| b== 0){
            cout<<ans<<endl;
            continue;
        }
        if(a>b){
            int diff = a-b;
            // cout<<diff<<" "<<ans<<endl;
            if(diff>b){
                ans+=b;
                b = 0;
            }
            else {
                ans+=diff;
                b-=diff;
                a-=(diff*2);    
            }
        }
        else{
            int diff = b-a;
            if(diff>a){
                ans+=a;
                a = 0;
            }
            else {
                ans+=diff;
                a-=diff;
                b-=(diff*2);
            }
        }
        if(a== 0|| b== 0){
            cout<<ans<<endl;
            continue;
        }
        if(a!= b){
            ans++;
            if(a>b)
                a-=2,b-=1;
            else  
                a-=1,b-=2;
        }

        ans+= (min(a,b)/3)*2;
        if(a%3 ==2)ans++;
        cout<<ans<<endl;
    }
    return 0;
}



