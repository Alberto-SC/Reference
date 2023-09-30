#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    cin>>n;
    vector<lli> divs;
    bool odd = false;
    for(lli i = 2;i*i<=n;i++){
        if(n%i == 0){
            divs.push_back(i);
            if(n/i != i)divs.push_back(n/i);
            if(i&1)odd = true;
            if((n/i) &1)odd = true;
        }
    }
    if(divs.size()== 0)cout<<n<<endl;
    else if(n&1){
        bool flag = true;
        for(auto c:divs){
            if(c%divs[0])flag = false;
        }
        if(flag)
            cout<<divs[0]<<endl;
        else    
            cout<<1<<endl;
    }
    else if(n%2 == 0 && odd)
        cout<<1<<endl;
    else 
        cout<<2<<endl;
    return 0;
}  

