#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


struct SuffixAutomaton {
    vector<map<int,int>> edges; 
    vector<int> link;            
    vector<int> len;        
    int last;                   

    SuffixAutomaton(string s) {
        edges.push_back(map<int,int>());
        link.push_back(-1);
        len.push_back(0);
        last = 0;
        for(int i=0;i<s.size();i++) {
            int c = int(s[i]);
            edges.push_back(map<int,int>());
            len.push_back(i+1);
            link.push_back(0);
            int cur = edges.size() - 1;
            int p = last;
            while(p >= 0 && !edges[p].count(c)) {
                edges[p][c] = cur;
                p = link[p];
            }
            if(p != -1){
                int q = edges[p][c];
                if(len[p] + 1 == len[q]) 
                    link[cur] = q;
                else {
                    edges.push_back(edges[q]); 
                    len.push_back(len[p] + 1);
                    link.push_back(link[q]); 
                    int clone = edges.size()-1;
                    link[q] = link[cur] = clone;
                    while(p >= 0 && edges[p].count(c) && edges[p][c] == q) {
                        edges[p][c] = clone;
                        p = link[p];
                    }
                }
            }
            last = cur;
        }
    }
};

//Aditonial implementations.
//Get de kth lexicografic string
vector<int> dp;
void getSize(SuffixAutomaton SA){
    int n = SA.edges.size();
    vector<int> order(n);
    dp.resize(n,0);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a,int b){
        return SA.len[a]>SA.len[b];
    });
    for(int i = 0;i<n;i++){
        dp[order[i]] = 1;
        for(auto c:SA.edges[order[i]])
            dp[order[i]]+=dp[c.second];
    }
};

int main(){__
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        SuffixAutomaton SA(s);
        getSize(SA);
        cout<<dp[0]-1<<endl;
    }

    return 0;
}   