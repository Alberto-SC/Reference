#include <bits/stdc++.h>
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
using namespace std;

using ld = long double;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

using time_stamp = tuple<int, int, int>;

const int MX = 1e5;

vector<time_stamp> tiempos;

void agrega_tiempos(const pii& rh, const pii& rm, const pii& rs){
    for(int h = rh.fi; h <= rh.se; h++){
        for(int m = rm.fi; m <= rm.se; m++){
            for(int s = rs.fi; s <= rs.se; s++){
                tiempos.eb(h, m, s);
            }
        }
    }
}

int str_to_int(const string& s){
    stringstream ss(s);
    int ret;
    ss >> ret;
    return ret;
}

pii str_to_rango(const string& s){
    if(s.find('-') == string::npos){
        int val = str_to_int(s);
        return pii(val, val);
    }
    int pos = s.find('-');
    int ini = str_to_int(s.substr(0, pos));
    int fin = str_to_int(s.substr(pos + 1));
    return pii(ini, fin);
}

vector<pii> lee_rangos(int max){
    vector<pii> ret;

    string token;
    cin >> token;
    if(token == "*"){
        ret.eb(0, max - 1);
        return ret;
    }
    int idx = 0;
    while(token.find(',', idx) != string::npos){
        int pos = token.find(',', idx);
        pii act_rango = str_to_rango(token.substr(idx, pos - idx));
        ret.pb(act_rango);
        idx = pos + 1;
    }
    pii act_rango = str_to_rango(token.substr(idx));
    ret.pb(act_rango);
    return ret;
}

void lee_linea(){
    vector<pii> rangos_h = lee_rangos(24);
    vector<pii> rangos_m = lee_rangos(60);
    vector<pii> rangos_s = lee_rangos(60);

    for(const pii& rh : rangos_h){
        for(const pii& rm : rangos_m){
            for(const pii& rs : rangos_s){
                agrega_tiempos(rh, rm, rs);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while(n--){
        lee_linea();
    }

    int total = tiempos.size();
    sort(tiempos.begin(), tiempos.end());
    vector<time_stamp>::iterator it = unique(tiempos.begin(), tiempos.end());

    cout << (it - tiempos.begin()) << " ";
    cout << total << endl;

    return 0;
}

