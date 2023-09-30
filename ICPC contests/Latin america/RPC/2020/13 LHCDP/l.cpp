#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;


ll fact[17];


void preCalc(){
    fact[0]=1;
    for(int i=1; i<17; i++){
        fact[i]=fact[i-1]*i;
        // cout<<"fact"<<fact[i]<<" ";
    }
}

ll comb(int n, int k){
    // cout<<n<<" "<<k<<endl;
    return (fact[n])/( fact[k] * fact[n-k]);
}

long double hiper(int x, int n, int K, int N){
    long double res=0.0;
    if( (K>=x) and ((N-K)>=(n-x)) and (N>=n))
        res+= (double)((comb(K,x)*comb(N-K, n-x))/((double)comb(N,n)));
    return res;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preCalc();
    int T,a,b,c,n,k,N;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>n>>k;
        N=a+b+c;
        long double res=0.0;
        for(int i=k; i<=n;i++){

            res+=(double)hiper(i,n,a,N);
            // cout<<res<<endl;
        }
        cout<<fixed<<setprecision(4)<<res<<"\n";
    }
    return 0;
}
