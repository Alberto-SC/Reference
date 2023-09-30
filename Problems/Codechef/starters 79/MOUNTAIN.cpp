#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;
int gauss(int x){
    return (x*(x+1))/2;
}

int gauss(int l,int r){
    return gauss(r)-gauss(l-1);
}

void solve(int x,int n,int m){
    int sum = 0;
    vector<int> v(n+1);
    int k = 0;
    for(int i = 1;i<=n;i++){
        int add = min(m,((x-sum)+(i-1))/i);
        sum+=i*add;
        v[i] = add;
        k = i;
        if(sum>=x)break;
    }
    if(sum<x){
        cout<<-1<<endl;
        return ;
    }
    v[sum-x]--;
    
    cout<<1<<" "<<k<<endl;
    for(int i = 1;i<=k;i++)cout<<v[i]<<" ";
    cout<<endl
        ;
    /* for(int i = 1;i<=n;i++){ */
    /*     int l = -1,r = n+1; */
    /*     while(l+1<r){ */
    /*         int m =(l+r)>>1; */
    /*         if(gauss(i,m)>=x)r = m; */
    /*         else l = m; */
    /*     } */
    /**/
    /*     if(gauss(i,r)== x && r<=n){ */
    /*         cout<<i<<" "<<(r-i)+1<<endl; */
    /*         for(int j = 0;j<(r-i)+1;j++)cout<<1<<" "; */
    /*         cout<<endl; */
    /*         return; */
    /*     } */
    /* } */
    /* cout<<-1<<endl; */
}

signed main(){__
    int T = 1,n,m,q;
    while(T--){
        cin>>n>>m>>q;
        
        vector<int> s(q);
        for(auto &c:s)cin>>c;
    
        int x = (n*(n+1))/2;
        int mx = x*m;
            

        for(int i = 0;i<q;i++){
            if(s[i]<x){
                solve(s[i],n,m);
                continue;
            }
            cout<<1<<" "<<n<<endl;
            int aux = s[i];
            int mx = (s[i]+(x-1))/x;
            s[i]-=(x*(s[i]/x));

            int z = x;
            vector<int> k(n+1);
            int id = n;
            while(s[i] && z>s[i]){
                if(z-id>=s[i]){
                    k[id] = 1;
                    z-=id;
                }
                id--;
            }
            int sum = 0;
            for(int j = 1;j<=n;j++){
                sum+=j*(mx-k[j]);
                cout<<mx-k[j]<<" ";
            }
            cout<<endl;
            assert(sum==aux);
        }
        
    }
}
