#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string ans = "";
        for(int i= 0;i<n;i+=k){
            for(int j = 0;j<k;j++){
                if(i+j<n)ans+=(char)(j+'a');
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}