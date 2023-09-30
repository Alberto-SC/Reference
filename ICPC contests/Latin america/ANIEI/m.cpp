#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n;
    cin>>t;
    while(t--){
        int h,m,h1,m1;
        scanf("%d:%d",&h,&m);
        scanf("%d:%d",&h1,&m1);
        int ans = 0;
        while(h!=h1){
            h++;
            m++;
            if(h==24)h=0;
            if(m==60)m = 0;
            ans++;
        } 
        if(m1>=m)
            ans+= m1-m;
        else 
            ans+=(60-m)+m1;
        cout<<ans<<endl;
    }
    return 0;
}  
