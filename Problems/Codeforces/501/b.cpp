#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    string t,s;
    cin>>n;
    cin>>s>>t;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(s[i] == t[i])continue;
        int pos = -1;
        for(int j = i+1;j<n;j++)
            if(s[j] == t[i]){pos = j;break;}
        if(pos  == -1 )return cout<<-1<<endl,0;
        for(int j = pos-1;j>=i;j--){
            swap(s[j],s[j+1]);
            ans.push_back(j);
        }
    }
    assert(t == s);
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c+1<<" ";
    return 0;
}