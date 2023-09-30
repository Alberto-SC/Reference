#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int n,k,x;
    cin>>n;
    cin>>k;
    vector<int> ons(n,1);
    int cont = 0,mx = 0;
    for(int i = 0;i<k;i++){
        cin>>x;
        for(int j = x-1;j<n;j+=x){
            if(ons[j]==1)cont++,ons[j]^=1;
            else cont--,ons[j]^=1;
        }
        mx = max(cont,mx);
    }
    cout<<mx<<endl;
    return 0;
}  

