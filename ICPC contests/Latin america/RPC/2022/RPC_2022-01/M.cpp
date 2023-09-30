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

const int MX = 1e5;
const ll LIM = 1e9;

bool es_espacio(char c){
    if(c == ' ') return true;
    if(c == '\n') return true;
    if(c == '\t') return true;
    return false;
}

bool lee_espacios(){
    char c = ' ';
    while(es_espacio(c)){
        c = getc(stdin);
        if(c == EOF) return false;
    }
    ungetc(c, stdin);
    return true;
}

bool leer_token(string& s){
    if(!lee_espacios()) return false;
    char c;
    do{
        c = getc(stdin);
        if(c == EOF){
            break;
        }
        if(!es_espacio(c)){
            s += c;
        }else{
            ungetc(c, stdin);
            break;
        }
    }while(true);
    return true;
}

bool es_numero(const string& s){
    for(char c : s){
        if(c < '0' || c > '9') return false;
    }
    if(s.size() > 11) return false;
    return s[0] != '0';
}

ll conv_num(const string& s){
    stringstream ss(s);
    ll num;
    ss >> num;
    return num;
}

bool es_primo(ll x){
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> tkn(3);

    forn(i, 3){
        if(!leer_token(tkn[i])){
            cout << 0 << endl;
            return 0;
        }
    }
    string basura;
    if(leer_token(basura)){
        cout << 0 << endl;
        return 0;
    }

    for(const string& s : tkn){
        if(!es_numero(s)){
            cout << 0 << endl;
            return 0;
        }
    } 

    vector<ll> val_tkn(3);

    forn(i, 3){
        val_tkn[i] = conv_num(tkn[i]);
    }
    if(val_tkn[0] & 1){
        cout << 0 << endl;
        return 0;
    }
    if(val_tkn[0] <= 3 || val_tkn[0] > LIM){
        cout << 0 << endl;
        return 0;
    }

    if(!es_primo(val_tkn[1]) || !es_primo(val_tkn[2])){
        cout << 0 << endl;
        return 0;
    }

    cout << (val_tkn[0] == val_tkn[1] + val_tkn[2]) << endl;

    return 0;
}

