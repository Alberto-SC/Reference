#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> pre;
    pre.push_back(0);
    for(int i = 1;pre.back()<100000;i++)
        pre.push_back((i*(i+1))/2);

    int cont = 0;
    string s = "";
    // for(auto c:pre)cout<<c<<" ";
    // cout<<endl;
    if(n == 0)return cout<<'a'<<endl,0;
    while(n){
        int index = lower_bound(pre.begin(),pre.end(),n)-pre.begin();
        if(pre[index] != n)index--;
        s+= string(index+1,(char)cont+'a');
        n-=pre[index];
        cont++;
    }
    cout<<s<<endl;
    return  0;
}