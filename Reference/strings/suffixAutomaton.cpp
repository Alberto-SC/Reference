/**
 * Author: Alberto silva
 * Date: 2020-05-15
 * Description: Suffix automaton creates an automaton that recognizes all the suffixes of a string.
 * Time: $O(N)$
 * Status: tested in codeforces []
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

struct SuffixAutomaton {
    vector<map<int,int>> to; 
    vector<int> link;            
    vector<int> len;        
    int last;                   

    SuffixAutomaton(string s) {
        to.push_back(map<int,int>());
        link.push_back(-1);
        len.push_back(0);
        last = 0;
        for(int i=0;i<s.size();i++) {
            int c = int(s[i]);
            to.push_back(map<int,int>());
            len.push_back(i+1);
            link.push_back(0);
            int cur = to.size() - 1;
            int p = last;
            while(p >= 0 && !to[p].count(c)) {
                to[p][c] = cur;
                p = link[p];
            }
            if(p != -1){
                int q = to[p][c];
                if(len[p] + 1 == len[q]) 
                    link[cur] = q;
                else {
                    to.push_back(to[q]); 
                    len.push_back(len[p] + 1);
                    link.push_back(link[q]); 
                    int clone = to.size()-1;
                    link[q] = link[cur] = clone;
                    while(p >= 0 && to[p].count(c) && to[p][c] == q) {
                        to[p][c] = clone;
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
    int n = SA.to.size();
    vector<int> order(n);
    dp.resize(n,0);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a,int b){
        return SA.len[a]>SA.len[b];
    });
    for(int i = 0;i<n;i++){
        dp[order[i]] = 1;
        for(auto c:SA.to[order[i]])
            dp[order[i]]+=dp[c.second];
    }
};


int main(){__
    int n = 1,k;
    string s;
    cin>>s;
    cin>>n;
    SuffixAutomaton SA(s);
    getSize(SA);
    for(int i = 0;i<n;i++){
        cin>>k;
        int u = 0;
        while(k){
            for(auto c:SA.to[u]){
                if(dp[c.second]>=k){
                    k--;
                    u = c.second;
                    cout<<char(c.first);
                    break;
                }
                else 
                    k-=dp[c.second];
            }
        }
        cout<<endl;
    }
    return 0;
}   