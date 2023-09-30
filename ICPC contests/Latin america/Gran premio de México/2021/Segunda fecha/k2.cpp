#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
int addmod(int a,int b){
    int x = a+b;
    if(x>mod)x-=mod;
    return x;
}
int restmod(int a,int b){
    int x = a-b;
    if(x<0)x+=mod;
    return x;
}

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
	int t= 1,k;
    cin>>t;
    while(t--){
        cin>>k;
        if(k==1){
            cout<<0<<endl;
            continue;
        }
        vector<int> divs;
        for(int i = 1;i*i<=k;i++){
            if(k%i==0){
                divs.push_back(i);
                if(k/i!= i && k/i != k)
                    divs.push_back(k/i);
            }
        }
        int ans = 0;
        vector<int> past;
        sort(divs.begin(),divs.end());
        for(int i = divs.size()-1;i>=0;i--){
            ans=addmod(bin_pow(2,divs[i]),ans);
            int gcd = 1;
            for(int j = 0;j<past.size();j++){
                gcd = max(gcd,__gcd(divs[i],past[j]));
            }
            past.push_back(divs[i]);
            ans = restmod(ans,bin_pow(2,gcd));
        }
        cout<<addmod(ans,2)<<endl;
    }
    return 0;
}  