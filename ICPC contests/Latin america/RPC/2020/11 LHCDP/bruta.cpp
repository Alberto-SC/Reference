#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli _hash(string const& s) {
    lli p = 31; 
    lli m = 1e9 + 9;
    int S = s.size();
    vector<lli> p_pow(S); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    lli h_s = 0; 
    for (int i = 0; i < S; i++){
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
        if(h_s<0)
            (h_s+=m)%=m;
    }
    return h_s;
}


int main(){__
    int t = 1,n;
    string a,b,c;
    cin>>a>>b>>c;
    n = a.size();
    int mn = n+1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                int cont = 0;
                for(int z = 0;z<n;z++){
                    if(a[(z+i)%n] != b[(z+j)%n] && a[(z+i)%n] != c[(z+k)%n] && c[(z+k)%n] != b[(z+j)%n])cont++;
                }
                if(cont ==n){
                    // if(min(i,n-i)+min(j,n-j)+min(k,n-k)<mn){
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                    // }
                    mn = min(mn,min(i,n-i)+min(j,n-j)+min(k,n-k));
                    
                }
            }
        }
    }

    if(mn ==n+1)cout<<-1<<endl;
    else
        cout<<mn<<endl;
    return 0;
}

