#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<tuple<int,int,int>> obstacle;

int N,M;

struct pairhash { template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const {
		return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 32);
	}
};

unordered_map<pair<int,int>,long long int, pairhash> mem;

long long int dp(int obs, int x){
    if(mem.count({obs,x})>0) return mem[{obs,x}];
    int t,l,r , nl, nr ,costl,costr;
    tie(t,l,r)= obstacle[obs];
    if(obs>= obstacle.size()) return 0;
    if(t==1){
        if(l==1 and r==N) return INT_MIN;
        if(x<l or r<x){
            costl=costr=0; nl=x; nr=x;
        }else{
            if(l!=1) {nl= l-1; costl= abs(x-nl);}
            else {nl=r+1; costl= abs(x-nl); }
            if(r!=N){ nr= r+1; costr= abs(x-nr); }
            else{ nr= l-1; costr= abs(x-nr); }
        }
    }else{
        if(l<=x and x<=r){
            costl=costr=0; nl=x; nr=x;
        }else if(x<l){
            nl= nr=l;
            costl=costr= abs(x-nr);
        }else{
            nl= nr= r;
            costl=costr= abs(x-nr);
        }
    }


    return mem[{obs,x}]= min(costl+dp(obs+1, nl) , costr+dp(obs+1, nr) );
}

int main(){__
    int x,t,l,r;
    cin>>N>>M>>x;
    mem.reserve(1024);
    mem.max_load_factor(0.25);
    for(int i=0; i<M;i++){
        cin>>t>>l>>r;
        obstacle.push_back(make_tuple(t,l,r));
    }
    long long int res = dp(0,x);
    if(res<0) cout<<"-1\n";
    else
        cout<<res<<"\n";
    return 0;
}
