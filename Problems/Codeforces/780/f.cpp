#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n,k,a,b;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int c = 1,poss = 0;
            int cont1 = 0,cont2 = 0;
            for(int j = i;j<n;j++){
                if(j>i && s[j]== s[j-1])c++;
                else if(j>i && s[j]!=s[j-1])c = 1;
                if(s[j]== '-')cont1++;
                else cont2++;
                // cout<<i<<" "<<j<<" "<<cont1<<" "<<cont2<<" "<<(cont1-cont2)%3<<" "<<(cont1-cont2)/3<<" "<<poss<<endl;
                if(c%2==0  && s[j]== '-')poss++;
                if(cont2>cont1)continue;
                if((cont1-cont2)%3 ==0 && ((cont1-cont2)/3)<=poss)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
