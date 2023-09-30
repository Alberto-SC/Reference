#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1;
    string s;
    cin>>s;
    int n = s.size();
    cout<<3<<endl;
    cout<<"L 2"<<endl;
    n++;
    cout<<"R 2"<<endl;
    n+=n-2;
    cout<<"R "<<n-1<<endl;

    return 0;
}

