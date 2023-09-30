#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c: A)cout<<c<<" ";
long long i, j;
long long primes[1000000];
void Prime(){
    primes[0] = primes[1] = 1;
    for(i=2;i<1000000;i++){
        if (primes[i]==0){
            for(j=i*i;j<1000000;j+=i){
                primes[j] = 1;
            }
        }
    }
}

int main(){
    Prime();
    //print(criba)cout<<endl;
    int n,a;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a;
        double sq = sqrt(a);
        if(a == 4)  cout<<"YES\n";
        else if(a%2 == 0|| a<4)cout<<"NO\n";
        else if((sq == int(sq)) && primes[int(sqrt(a))] == 0 )cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}