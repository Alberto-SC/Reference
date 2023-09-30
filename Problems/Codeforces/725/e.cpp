#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct q{
    string pref,suff; 
    int cont;
};

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        map<string,q> mp;
        string s;
        string last ="";
        getline(cin,s);
        for(int i = 0;i<n;i++){
            getline(cin,s);
            istringstream in(s);
            vector<string> words;
            string w;
            while(getline(in, w, ' '))
                words.push_back(w);
            if(words[1]==":="){
                string pref = words[2];
                if(pref.size()>3)pref.resize(3);
                string suff = words[2];
                if(suff.size()>3)suff = suff.substr(suff.size()-3);
                int cont  = 0;
                for(int i = 0;i<((int)words[2].size())-3;i++){
                    if(words[2][i] == 'h' && words[2][i+1]== 'a' && words[2][i+2] == 'h' && words[2][i+3]== 'a')cont++;
                }
                mp[words[0]] = {pref,suff,cont};
            }
            else{
                string suf = mp[words[2]].suff;
                string pref = mp[words[4]].pref;
                string nw = suf+pref;
                int cont  = 0;
                for(int i = 0;i<((int)nw.size())-3;i++){
                    if(nw[i] == 'h' && nw[i+1]== 'a' && nw[i+2] == 'h' && nw[i+3]== 'a')cont++;
                }

                string npref = mp[words[2]].pref;
                string nsuff = mp[words[4]].suff;
                if(npref.size()<3){
                    npref+=pref;
                    if(npref.size()>3)npref.resize(3);
                }
                if(nsuff.size()<3){
                    nsuff = suf+nsuff;
                    if(nsuff.size()>3)nsuff = nsuff.substr(nsuff.size()-3);
                }
                mp[words[0]] = {npref,nsuff,cont+mp[words[2]].cont+mp[words[4]].cont};
            }
            if(i ==n-1){
                cout<<mp[words[0]].cont<<endl;
            }
        }
    }
    return 0;
}