#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<string,bool> valid;
map<string,string> assign;
vector<int> used;
set<string> ingredients[1000];
set<string> allergens[1000];
void intersect(vector<set<string>> S,string alergeno,int idx,int N){
    map<string,int> fr;
    int n = S.size();
    for(int i = 0;i<n;i++){
        for(auto c:S[i]){
            fr[c]++;
        }
    }
    cout<<"Alergeno: "<<alergeno<<endl;
    set<string> st;
    for(int i = 0;i<n;i++){
        for(auto c:S[i]){
            if(fr[c]== n){
                st.insert(c);
                valid[c] = true; 
            }
        }
    }
    if(st.size()==1){
        cout<<"SIMON "<<*st.begin()<<endl;
        assign[alergeno] = *st.begin();
        used[idx] = true;
        for(int i = 0;i<N;i++){
            ingredients[i].erase(*st.begin());    
        }
    }
}

int main(){
    string line;
    set<string> all_allergens;
    map<string,int> count;
    int n =0;
    while(getline(cin,line)){
        set<string> ingredient;
        set<string> allergen;
        int idx =0;
        while(line[idx]!= '('){idx++;}
        string s1 = line.substr(0,idx);
        string s2 = line.substr(idx+10);
        if(s2.back()==13)
            s2.pop_back();
        s2.pop_back();
        istringstream in(s1);
        string w;
        while(getline(in, w, ' ')){
            int j = 0;
            while(j<w.size() && w[j]== ' '){j++;}
            w = w.substr(j);
            ingredient.insert(w);
            count[w]++;
            valid[w] = false;
        }
        istringstream in2(s2);
        while(getline(in2, w, ',')){
            int j = 0;
            while(j<w.size() && w[j]== ' '){j++;}
            w = w.substr(j);
            allergen.insert(w);
            all_allergens.insert(w);
        }   
        ingredients[n] = ingredient;
        allergens[n] = allergen;
        n++;
    }
    cout<<n<<endl;
    int m = all_allergens.size();
    used.resize(m,0);
    vector<int> ones(m,1);
    int cont = 0;
    while(used != ones){   
        int id = 0;
        for(auto c:all_allergens){
            if(used[id]){id++;continue;}
            vector<set<string>> S;
            for(int i = 0;i<n;i++){
                if(allergens[i].count(c)){
                    S.push_back(ingredients[i]);
                }
            }
            intersect(S,c,id,n);
            cout<<endl;
            id++;
        }
        for(auto k:used)cout<<k<<" ";
        cout<<endl;
    }
    lli ans = 0;
    lli total = 0;
    for(auto c:assign){
        cout<<c.second<<",";
    }
    cout<<endl;
    // for(auto d:valid){
        // cout<<d.first<<" "<<d.second<<" "<<count[d.first]<<endl;
        // if(!d.second){
            // ans+=count[d.first];
        // }
        // total+=count[d.first];
    // }
    // cout<<ans<<endl;
    // cout<<total<<endl;
    return 0;
}