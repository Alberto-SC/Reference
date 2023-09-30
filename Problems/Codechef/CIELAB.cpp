#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    a = a-b;
    bool yes = true;
    vector<int> ans;
    while(a){
        if(yes){
            if(a%10==9)ans.push_back(2);
            else ans.push_back((a%10)+1);
            yes = false;
            a/=10;
        }
        else{
            ans.push_back(a%10);
            a/=10;
        }
    }
    for(int i = ans.size()-1;i>=0;i--)cout<<ans[i];
    return 0;
}