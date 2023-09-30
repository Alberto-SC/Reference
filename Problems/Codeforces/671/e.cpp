#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<lli,lli> fact;
void factP(lli n){ 
    while(n%2 ==0){
        n/=2;
        fact[2]++;
    }

    for(lli i =3;i*i<=n;i+=2){
        while(n%i ==0){
            fact[i]++;
            n/=i;
        }
    }
    if(n>1)fact[n]++;
}
map<lli,bool> used;
vector<vector<lli>> divs;
void generateDivisors(lli idx, lli div, vector<pair<lli,lli>>& Fact){
    if (idx == Fact.size()) {
        for(lli i = 0;i<Fact.size();i++){
            if(div%Fact[i].x==0){
                divs[i].push_back(div);
            }

        }
        used[div] = false;
        return;
    }

    for (lli i = 0; i <= Fact[idx].y; ++i) {
        generateDivisors(idx + 1, div, Fact);
        div *= Fact[idx].x;
    }
}

int main(){
    lli t = 1,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        fact.clear();
        used.clear();
        divs.clear();
        factP(n);
        bool pot1 = true;
        lli cont = 0;
        vector<pair<lli,lli>> f;
        for(auto c:fact){
            // cout<<c.first<<" "<<c.second<<endl;
            if(c.y>1)pot1 = false;
            f.push_back({c.x,c.y});
            cont++;
        }
        divs.resize(fact.size());
        if(cont==2 && pot1){
            for(auto c:fact)
                cout<<c.x<<" ";
            cout<<n<<endl;
            cout<<1<<endl;
        }
        else {
            lli N =fact.size();
            generateDivisors(0,1,f);
            for(lli i = 0;i<N;i++){
                if(N>1 && i == 0)cout<<f[0].x*f[N-1].x<<" ",used[f[0].x*f[N-1].x] = true;
                cout<<f[i].x<<" ";
                used[f[i].x] = true;
                for(auto c:divs[i]){
                    if(!used[c] && i+1<N && c!= f[i].x*f[i+1].x )cout<<c<<" ",used[c]= true;
                    else if(!used[c] && i==N-1)cout<<c<<" ",used[c] = true;
                }
                if(i+1<N && !used[f[i].x*f[i+1].x])cout<<f[i].x*f[i+1].x<<" ",used[f[i].x*f[i+1].x] = true;
            }
            cout<<endl<<0<<endl;
        }
    }
    return 0;
}


