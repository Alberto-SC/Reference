
#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 0;
    vector<pair<int,int>> v;
    vector<int> p(n);
    p[0] = s[0]== 'X';

    for(int i = 1;i<n;i++)
        p[i] = p[i-1]+(s[i]== 'X');
    
    vector<int> S(n);
    S[n-1] = s[n-1]== 'Y';
    vector<int> res(n);
    vector<int> rev(n);
    for(int i = n-2;i>=0;i--){
        if(s[i]== 'Y' && s[i+1]== 'Y')res[i] = res[i+1]+1;
        else res[i]=res[i+1];

        if(s[i]== 'X' && s[i+1]== 'X')rev[i] = rev[i+1]+1;
        else rev[i]=rev[i+1];

        S[i] =S[i+1]+(s[i]=='Y');
    }

  
    for(int i = 0;i<n;i++){
        int l = i-1,r = n;
        while(l+1<r){
            int m = (l+r)>>1;
            if(p[m]-(i?p[i-1]:0)<=k)l = m;
            else r = m;
        }
        if(l == i-1)continue;
        int zeros = p[l]-(i?p[i-1]:0);
        int aux = k-zeros;

        aux-=min(aux,i);
        
        if(!aux){
            ans = max(ans,(l-i)+((l+1)<n?res[l+1]:0));
            continue;
        }
        l = i-1,r = n;
        
        while(l+1<r){
            int m = (l+r)>>1;
            if(S[m]>=aux)l = m;
            else r = m;
        }
        ans = max(ans,(l-i-1)+((l+1)<n?rev[l+1]:0));
    }

    cout<<ans<<endl;
    return 0;
}

