#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int mod = 1e9+7;

vector<int> nums;
const int maxn = 500007;
vector<int> graph[maxn];

int D = 32;
int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

struct Trie{
    Trie* child[2];
    int count;
};
 
struct Trie *getNode(){
    struct Trie *p = new Trie;
    p->child[0] = NULL;
    p->child[1] = NULL;
    p->count = 0;
    return p;
}
 
void insert(struct Trie *root, int num){
    struct Trie *S = root;
    for(int i = D ; i>=0; i--){
        int x = (num>>i)&1;
        if(S->child[x] == NULL)
            S->child[x] = getNode(); 
        S = S->child[x];
    }
    S->count++;
}
 
int best(struct Trie *root, int num){
    struct Trie *S = root;
    for(int i = D;i>=0;i--){
        int x = (num>>i)&1;
        if(x){
            if(S->child[0]!=NULL){
                S = S->child[0];
            }
            else{
                S = S->child[1];
                num^=(1<<i);
            }
        }
        else{
            if(S->child[1]!=NULL){
                S = S->child[1];
                num^=(1<<i);
            }
            else{
                S = S->child[0];
            }
        }
    }
    return num;
}

Trie* remove(Trie* root, int val, int depth = D){ 
    if(!root) 
        return NULL; 
    if (depth == -1) { 
        root->count--;
        if (root->count==0) { 
            delete (root); 
            root = NULL; 
        } 
        return root; 
    } 
    int x = (val>>depth)&1;
    root->child[x] =  remove(root->child[x], val, depth - 1); 
    if (root->child[1] ==NULL && root->child[0]== NULL ) { 
        delete(root); 
        root=NULL; 
    } 
    return root; 
} 

void print(Trie* root,string s="",int level = D){
    if(root==NULL)return;
    if(level ==-1){
        for(int i = 0;i<root->count;i++)
            cout<<s<<endl;
    }
    if(root->child[0]!=NULL){
        
        print(root->child[0],s+"0",level-1);
    }
    if(root->child[1]!=NULL){
        print(root->child[1],s+"1",level-1);
    }

}


Trie *root;
int dfs(int u,int x,int p = -1){
    int ans = 0;
    int c= 0;
    x^=nums[u];
    insert(root,nums[u]);
    for(auto v:graph[u]){
        if(v ==p)continue;
        c++;
        ans+=dfs(v,x,u);
        ans%=mod;
    }
    if(c ==0){
        ans = best(root,x);
        remove(root,nums[u]);
        return ans; 
    }
    remove(root,nums[u]);
    ans*=mod_pow(c,mod-2);
    ans%=mod;
    return ans;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        root = getNode();
        nums.resize(n);
        for(int i = 0;i<n;i++)graph[i].clear();
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cout<<dfs(0,0)<<endl;
    }
    return 0;
}