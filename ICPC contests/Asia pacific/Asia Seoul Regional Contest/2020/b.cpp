#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    vector<int> a(6);
    vector<int> b(6);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    int wins = 0;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(a[i]>b[j])wins++;
        }
    }
    int p = wins/__gcd(wins,36);
    int q = 36/__gcd(wins,36);
    cout<<p<<"/"<<q<<endl;

    return 0;
}  

