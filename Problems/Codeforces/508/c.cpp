#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,i = 0,j = 0,who = 0,asum = 0,bsum = 0,moves = 0;
    cin>>n;
    vector<lli> a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    b.push_back(0);
    a.push_back(0);
    while(moves<2*n){
        moves++;
        if(!who)
            a[i]>=b[j]?asum+=a[i++]:j++;
        else 
            b[j]>=a[i]?bsum+=b[j++]:i++;
        who^=1;
        // cout<<asum<<" "<<bsum<<"  "<<i<<"  "<<j<<endl;
    }
    cout<<asum-bsum<<endl;
    return 0;
}