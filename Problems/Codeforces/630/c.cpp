#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        int a,ans = 0;
        for(int i = 0;i<ceil(k/2.0);i++){
            vector<int> b(27,0);
            for(int j = 0;j<n/k;j++){
                b[(s[(j*k)+i])-'a']++;
                b[(s[(j*k)+(k-1)-i])-'a']++;
            }  
            int mx = *max_element(b.begin(),b.end());
            int a;
            if(k&1 && i == ceil(k/2.0)-1)a= (n/k)-(mx/2);
            else a = ((n/k)*2)-mx;
            ans+=a;
        }
        cout<<ans<<endl;
    }
    return 0;
}