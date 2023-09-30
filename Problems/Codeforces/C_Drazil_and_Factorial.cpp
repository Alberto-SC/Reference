#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,t;
    cin>>t;
    cin>>n;
    vector<int> facts;
    
    int i = 0,two = 0;
    while(n){
        facts.push_back(n%10);
        n/=10;
    }
    vector<int> ans(10);
    for(auto c:facts){
        if(c == 9)ans[2]+=1,ans[3]+=2,ans[7]++;
        else if(c == 8)ans[2]+=3,ans[7]++;
        else if(c == 6)ans[3]++,ans[5]++;
        else if(c == 4)ans[2]+=2,ans[3]++;
        else ans[c]++;
    }
    for(int i =9;i>1;i--){
        for(int j = 0;j<ans[i];j++)cout<<i;
    }
    cout<<endl;
    return 0;
}