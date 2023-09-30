#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    vector<int> facts;
    facts.push_back(1);
    for(int i = 1;i<20;i++)
        facts.push_back(facts.back()*i) ;
    cin>>n;
    int cont = 0;
    while(n){
        auto it = lower_bound(facts.begin(),facts.end(),n);
        if(*it==n){
            cont++;
            n = 0;
        }
        else {
            --it;
            cont++;
            n-=*it;
        }
    }
    cout<<cont<<endl;
    return 0;
}  

