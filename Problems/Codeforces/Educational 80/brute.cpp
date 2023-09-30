#include <bits/stdc++.h>
using namespace std;
typedef long long int  lli;
int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int count = 0;
        for(int i = 1;i<=a;i++){
            for(int j = 1;j<=b;j++){
                lli result = (i*j)+(i+j);
                string a = to_string(i);
                string b = to_string(j);
                a+=b;
                if(to_string(result) == a){count++;}
            }
        }
        cout<<count<<endl;
    }
    return 0;
}