#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    lli t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        n = s.size();
        vector<lli> a(n);
        lli x = 0;
        for(lli i = 0;i<n;i++){
            if(s[i]== '-')x--;
            else x++;
            a[i]= x;
        }
        lli y = 0,ans = 0;
        bool flag = false;
        // for(auto c:a)cout<<c<<" ";
        // cout<<endl;    
        for(lli i = 0;i<n;i++){
            a[i]+=y;
            if(a[i]<0){
                y+=abs(a[i]);
                if(!flag)
                ans++;
                else
                ans+= i+1;
                flag = true;
            }
            else {
                if(flag == true)ans+=(i+1);
                else ans++;
                flag = false;
            }
            // cout<<ans<<" ";
        }
        if(flag)ans+=n;
        cout<<ans<<endl;
    }
    return 0;
}