#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ull acu[1000003];

ull shortGauss(int i){
    ull a=i;
    ull b=i+1;
    if(a%2==0)
        a=a>>1;
    else
        b=b>>1;
    return a*b;
}

void pre(){
    acu[0]=0;
    for(int i=1; i<=1000000; i++){
        acu[i]= acu[i-1]+shortGauss(i);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pre();
    int T,x;
    cin>>T;
    while(T--){
        cin>>x;
        cout<<acu[x]<<"\n";
    }
    // for(int i=0; i<20; i++){
    //     cout<<acu[i]<<endl;
    // }
    return 0;
}
