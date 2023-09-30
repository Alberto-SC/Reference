#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> lvl(maxn);
void dfs(int u){
    cout<<u<<endl;
    for(auto v:graph[u]){
        if(lvl[v] == 0){
            lvl[v] = lvl[u]+1;
            dfs(v);
        }
    }
}
int main(){
    int n;
    char s[1000];
    vector<int> nodes(100000);
    while(1){
        cin>>n;
        if(n==0)return 0;
        cout<<n<<endl;
        for(int i=0;i<n+100;i++)
            graph[i].clear();
        while(1){
            scanf("%[^\n]",s);
            if(s[0]=='0')
                break;
            int cnt=0;
            char *token = strtok(s," ");
            string str;
            while(token!=NULL){
                int x=stoi(token);
                nodes[cnt]=x;
                cnt++;
                token=strtok(NULL," ");
            }

            for(int j=1;j<cnt;j++){
                graph[nodes[0]-1].push_back(nodes[j]-1);
                graph[nodes[j]-1].push_back(nodes[0]-1);
            }
        }
        dfs(0);
    }
    return 0;
}