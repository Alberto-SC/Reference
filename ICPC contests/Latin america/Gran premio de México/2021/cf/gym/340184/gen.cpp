#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

signed main(){__
    int n = 1000,m = 1000,q = 100000;
    cout<<n<<" "<<m<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i== 0 && j ==0)
                cout<<"E ";
            else
                cout<<". ";
        }
        cout<<endl;
    }
    cout<<q<<endl;
    for(int i = 0;i<q;i++)
        cout<<rand(1,n)<<" "<<rand(1,m)<<endl;
    
    return 0;
}