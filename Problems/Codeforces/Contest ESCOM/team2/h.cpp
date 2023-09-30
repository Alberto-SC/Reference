#include <bits/stdc++.h>
using namespace std;
typedef  unsigned long long int lli;
int main(){
    lli a,b;
    set<lli>A;
    // vector<vector<lli>> A(64*65);
    lli aux = 0; 
    for(int i = 1;i<=64;i++){
        aux  = aux<<1|1;
        for(int j =0 ;j<=64;j++){
            int cont = i;
            bool flag = true;
            lli num = aux;
            // if(j==0)
            A.insert(num);
            while(cont<=64){
                if(flag)num= num<<j;
                else num= num<<i,num+=aux;
                // cout<<"NUM:"<<num<<"   ";
                A.insert(num);
                if(flag)cont+=j;
                else cont+=i;
                flag = !flag;
                // if(i == 5 && j == 5)cout<<num<<" "<<cont<<endl;
            }
        }
    }
    vector<lli> C;
    for(auto c:A)C.push_back(c);
    lli z = 2147483647;
    // cout<<(z<<31)<<endl;
    while(cin>>a>>b){
        
        lli ans = 0;
        int l,r;
        l = lower_bound(C.begin(),C.end(),a)-C.begin();
        r = upper_bound(C.begin(),C.end(),b)-C.begin();
        ans+=(r-l);
            // for(auto c:C[i])cout<<c<<" ";
            // cout<<endl;
            // cout<<"INDICES "<<l<<" "<<r<<endl;
    
        cout<<ans<<endl;
    }
        
    return 0;
}
// 1111111111111111111111111111100000000000000000000000000000
// 4611686016279904000		
// 2147483647