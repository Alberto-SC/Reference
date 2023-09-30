#include<bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int main(){__
    int N,K,aux;
    cin>>N>>K;

    vector<int> elo;
    for(int i=0; i<(1LL<<N);i++){
        cin>>aux;
        elo.push_back(aux);
    }

    sort(elo.begin(), elo.end());
    reverse(elo.begin(),elo.end());

    int close = 0;
    for(int i=0; i<N; i++){
        for(int j=0, r=1LL<<i; j<(1LL<<i); j++){
            if(abs(elo[r]-elo[j])<=K){
                close++;
                r++;
            }
        }
    }

    cout<<close<<"\n";

    return 0;
}
