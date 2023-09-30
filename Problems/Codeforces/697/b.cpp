#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = false;
        for(int i = 0;i<10000;i++){
            if((i*2020)>n)break;
            if((n-(i*2020))%2021==0){
                flag = true;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}  

