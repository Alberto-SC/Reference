#include <bits/stdc++.h>   
using namespace std;
vector<long long int> phis(200004);
int phi(int n){
    int result =n;
    for(int i = 2;i*i<=n;i++){
        if(n%i ==0){
            while(n%i==0)   
                n/=i;
            result -= result/i;
        }
    }
    if (n>1)
        result -= result/n;
    return result;
}
void precalc(){
    phis[1]=2;
    phis[2]=3;
    for(int i=3;i<200003;i++)
        phis[i]=phi(i)+phis[i-1];
}
int main(){
    long long int k;
    precalc();
    while(true){
        cin>>k;
        if(k ==0)break;
        if(k == 2){cout<<1<<"/"<<1<<endl;continue;}
        int n =upper_bound(phis.begin(),phis.end(),k)-phis.begin();
        long long cont =phis[n-1];
        if(cont ==k){cout<<n-2<<"/"<<n-1<<endl;continue;}
        for(int i =0;i<=n;i++){
            if(__gcd(i,n)==1)cont++;
            if(cont ==k){cout<<i<<"/"<<n<<endl;break;}
        }
    }
    return 0;
}