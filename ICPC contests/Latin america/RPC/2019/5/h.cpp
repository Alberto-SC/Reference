#include <bits/stdc++.h>

using namespace std;
map<char, int> cont(string s) {
    map<char, int> atoms;
    int i = 0;
    while(i < s.size()) {
        char atom = s[i];
        i++;
        int am, j = 0;
        while(i + j < s.length() && s[i+j] >= '0' && s[i+j] <= '9')
            j++;
        if(j == 0)
            am = 1;
        else
            am = stoi(s.substr(i, j));
        if(atoms.find(atom) != atoms.end())
            atoms[atom] += am;
        else
            atoms[atom] = am;
        i += j;
    }
    return atoms;
}

int main() {
    string a,b; 
    int n;
    cin >> a >> n >>b;
    auto mapa = cont(a);
    auto mapb = cont(b);
    int mn = 2000000000;
    for(auto p : mapb) {
        char atom = p.first;
        if(mapa.find(atom) == mapa.end()) {
            mn = 0;
            break;
        }
        mn = min(mn, (mapa[atom]*n)/mapb[atom]);
    }
    cout << mn << endl;
    return 0;
}
