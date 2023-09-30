#include<bits/stdc++.h>

using namespace std;


void simplyfy(unsigned long long int k, string &s){
    if(k==1){
        s+="2";
    }else if(k%2==0){
        s+="(";
        simplyfy(k/2,s);
        s+=")^2";
    }else if(k%2 == 1){
        s+="(2*";
        simplyfy(k-1,s);
        s+=")";
    }
}

int main(){
    unsigned long long int N,K;
    cin>>N;
    string res;
    while(N--){
        cin>>K;
        res="";
        simplyfy(K,res);
        cout<<res<<"\n";
    }
    return 0;
}
// 1000000000000000000
