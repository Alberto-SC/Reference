#include <bits/stdc++.h>
using namespace std;
map<int,int> primes(int x){
    map<int,int> p;
    while(x%2== 0){
        p[2]++;
        x/=2;
    }
    for(int i = 3;i*i<=x;i+=2){
        while(x%i == 0){
            p[i]++;
            x/=i;
        }
    }
    if(x>1)p[x]++;
    return p;
}
int main(){
    int x;
    cin>>x;
    map<int,int> px;
    int ans = 1000000000;
    px = primes(x);
    for(auto c:px){
        int mn = (x/c.first)-1;
        // cout<<c.first<<"    "<<(c.first*mn)+1<<endl;
        for(int i = (c.first*mn)+1;i<x;i++){
            // cout<<"        "<<i<<endl;
            map<int,int> px1;
            px1 = primes(i);
            if(px.size()==1 && px1.find(i)!= px1.end() && c.first == 2)ans = min(i,ans);
            if(px1.size()==1 && px1.find(i)!= px1.end())continue;
            for(auto d:px1){
                // cout<<"primes "<<d.first<<" "<<d.second<<endl;
                int mn2 = (i/d.first)-1;
                ans = min((d.first*mn2)+1,ans);
            }
            // cout<<"ANS "<<ans<<endl;
        }
    }
    cout<<ans;
    return 0;
}