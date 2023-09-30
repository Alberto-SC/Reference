#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s,t;
        cin>>n;
        cin>>s>>t;
        int cont1 = 0,cont2 = 0,ones1 = 0,ones2 = 0,ones3 =0;
        for(int i = 0;i<n;i++){
            if(s[i]!= t[i]){
                cont1++;
                if(s[i]=='1')ones1++;
            }
            else if(s[i]==t[i]){
                cont2++;
                if(s[i]=='0')ones2++;
                else ones3++;
            }
        }
        int ans = n+1;
        if(cont2== 1&& ones3==1)ans = min(ans,1ll);
        if(cont1%2 ==0 && ones1 == cont1/2)ans = min(ans,cont1);
        if((cont2-1)%2 ==0 && ones2 == cont2/2)ans = min(ans,cont2);
        if(ans ==n+1)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}  
