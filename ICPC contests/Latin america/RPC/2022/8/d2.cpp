#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200006;

vector<set<int> > C(MAXN, set<int>());
vi A,B;
vi dead;

int refcount[MAXN] = {0};
int alive[MAXN] = {0};
vi Q;

vector<vi> dying(MAXN, vi());

void kill_node(int i){
    trav(y, C[i]){
        refcount[B[y]]--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].insert(c1);
        A.push_back(a);
        B.push_back(b);
        dead.push_back(big);
    }

    cin >> q;
    rep(c1,0,q){
        cin >> a >> b;
        b--;
        if(a == 1){
            dead[b] = c1+1;
            Q.push_back(-b-1);
        }
        else{
            Q.push_back(b);
        }
    }


    priority_queue<pll> pq;
    vector<bool> mark(n, 0);
    pq.push({big,0});
    alive[0] = big;
    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        if(!mark[i]){
            if(alive[i] < big)dying[alive[i]].push_back(i);
            mark[i] = 1;
            trav(y, C[i]){
                int w = min(dead[y], alive[i]);
                int j = B[y];
                refcount[j]++;
                if(w > alive[j]){
                    alive[j] = w;
                    pq.push({alive[j], j});
                }
            }
        }
    }

    rep(c1,0,q){
        trav(y, dying[c1]){
            kill_node(y);
        }
        if(Q[c1] < 0){
            int e = -Q[c1]-1;
            a = A[e];
            b = B[e];
            if(alive[a] > c1){
                refcount[b]--;
                C[a].erase(e);
            }
        }
        else{
            cout << refcount[Q[c1]] << "\n";
        }
    }

    return 0;
}
