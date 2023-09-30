#include <bits/stdc++.h>
using namespace std;
vector<int> fa(3,0);
vector<int> fb(3,0);
int factorize(int a,int who){
    while(a%2==0){a/=2;who?fa[0]++:fb[0]++;}
    while(a%3==0){a/=3;who?fa[1]++:fb[1]++;}
    while(a%5==0){a/=5;who?fa[2]++:fb[2]++;}
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    if(factorize(a,1)!= factorize(b,0))return cout<<-1<<endl,0;
    int ans = 0;

    for(int i = 0;i<3;i++)
        ans+=abs(fa[i]-fb[i]);
    cout<<ans<<endl;
    return 0;
}