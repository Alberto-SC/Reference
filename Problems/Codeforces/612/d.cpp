#include <bits/stdc++.h>
using namespace std;
const int maxn = 2007;
vector<int> graph[maxn];

vector<int> e(maxn); 
vector<int> s(maxn);
vector<int> times(maxn); 
int t  = 0;

void dfs(int u,int p =-1){
    times[t] = u;
    s[u]= t++;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u);
    }
    e[u] = t;
}
int main(){
    int n,p;
    cin>>n;
    vector<int> c(n);
    int root = 0;
    for(int i = 0;i<n;i++){
        cin>>p>>c[i];
        if(p == 0){root = i;continue;}
        graph[p-1].push_back(i);
    }
    dfs(root);
    vector<int> ans(n);
    ans[0] = 10000;
    for(int i = 0;i<n;i++){
        if(i == 0){
            if(c[times[i]]> e[times[i]-s[times[i]]])return cout<<"NO"<<endl,0;
            ans[i]+= 2*(e[times[i]]-s[times[i]]);
            for(int j = i;j<e[times[i]]-c[times[i]];j++)
                ans[j] = ans[i];
            for(int j = e[times[i]]-c[times[i]];j<e[times[i]];j++)
                ans[j] = 1;
        }
        else{
            ans[i]+= 2*(e[times[i]]-s[times[i]]);
            for(int j = i;j<e[times[i]]-c[times[i]];j++)
                ans[j] = ans[i];   
        }
    }
    vector<int> ans2(n);
    for(int i = 0;i<n;i++)
        ans2[times[i]] = ans[i];
    
    bool flag = true;
    for(int i = 0;i<n;i++){
        int x = 0;
        for(int j = i+1;j<e[times[i]];j++){
            if(ans[j]<ans[i])x++;
        }
        if(x!= c[times[i]])flag = false;
    }
    if(flag){
        cout<<"YES"<<endl;
        for(auto c:ans2)cout<<c<<" ";
        cout<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}