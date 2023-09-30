#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> res = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405,1082401 ,22369621};

int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        int mx = 0;
        lli x = 32-__builtin_clz(n);
        if((1<<x)-1== n)
            cout<<res[x]<<endl;
        else
            cout<<(1<<x)-1<<endl;
        
    }
    return 0;
}  

