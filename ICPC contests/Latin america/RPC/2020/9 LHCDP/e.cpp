#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli maxn = 1000007;
vector<pair<lli,lli>> graph[maxn];
void add_edge(lli u,lli v,lli cost){
    graph[v].push_back({u,cost});
    graph[u].push_back({v,cost});
}

const lli INF = 1e15;
lli t;
lli calc(lli a,lli b){
    lli ans1 = 0,ans2 = 1;
    if(b == a+1)return 0;
    if(a == b)return 1;
    if(b<a){
        int aux = a+2;
        ans1++;
        ans1+=t-aux,ans1+=b;
    }
    else{
        int aux = a+2;
        ans1++;
        ans1+=b-aux;
    } 
    if(b<a)
        ans2+= a-b;
    else ans2+=a,ans2+=t-b;
    return min(ans1,ans2);
}
int main(){__
    lli s,n,song;
    cin>>t>>s;
    vector<pair<lli,lli>> past;
    lli N = 0;
    past.push_back({1,N++});
    for(lli i = 0;i<s;i++){
        cin>>n;
        vector<pair<lli,lli>> nw;
        for(lli j = 0;j<n;j++){
            // cout<<N<<endl;
            cin>>song;
            for(lli k = 0;k<past.size();k++){
                // cout<<past[k].first<<" "<<s<<" "<<calc(past[k].first,s)<<endl;
                if(i == 0)
                    add_edge(past[k].second,N,min(song-1,(t-song)+1));    
                else
                    add_edge(past[k].second,N,calc(past[k].first,song));
            }
            nw.push_back({song,N});
            N++;
        }
        // cout<<"HI "<<i<<endl;
        past = nw;
    }
    for(int i = 0;i<past.size();i++){
        add_edge(past[i].second,N,0);
    }
    N++;
    vector<lli> d(N+1);
    for(lli i=0 ; i<N;++i)
		d[i] = INF;
	d[0] = 0;
    set<pair<lli,lli>>st;
	st.insert(make_pair(d[0], 0));
    while (!st.empty()) {
        lli v = st.begin()->second;
        st.erase(st.begin());
        for(auto c:graph[v]){
            lli u = c.first;
            lli w = c.second;
            if (d[v] + w < d[u]) {
                st.erase(make_pair(d[u], u));
                d[u] = d[v]+  w;
                st.insert(make_pair(d[u], u));
            }
        }
    }  
    cout<<d[N-1]<<endl;  
}