#include <bits/stdc++.h>
using namespace std;

struct sortBitset{
    bool operator ()(const bitset<10000> a,bitset<10000> b){
        if(a.count()== b.count()){
            for(int i = 0;i<10000;i++){
                if(a[i]<b[i])return 0;
                else if(a[i]>b[i])return 1;
            }
        }
        return a.count()>b.count();
    }
};
struct sortBitsetless{
    bool operator ()(const bitset<10000> a,bitset<10000> b){
        if(a.count()== b.count()){
            for(int i = 0;i<10000;i++){
                if(a[i]<b[i])return 1;
                else if(a[i]>b[i])return 0;
            }
        }
        return a.count()<b.count();
    }
};
int main(){
  // Input file
    // freopen("a_example","r",stdin);
    // freopen("b_little_bit_of_everything.in","r",stdin);
    freopen("c_many_ingredients.in","r",stdin);
    // freopen("d_many_pizzas.in","r",stdin);
    // freopen("e_many_teams.in","r",stdin);
    // freopen("out","w",stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num_pizzas=0; cin >> num_pizzas;
    int team_1=0, team_2=0, team_3=0, team_4=0;
    cin  >> team_2 >> team_3 >> team_4;
    vector<vector<string>>pizzas(num_pizzas);
    vector<bitset<10000>> pizzas_bits(num_pizzas);
    set<string> all_ingredients;
    for(int i=0; i<num_pizzas; i++){
        int num_ingredients=0; 
        cin >> num_ingredients;
        string ingredient;
        for(int j=0; j<num_ingredients; j++){
            cin>>ingredient;
            pizzas.at(i).push_back(ingredient);
            all_ingredients.insert(ingredient);
        }
    }
    // cout<<all_ingredients.size()<<endl;
    vector<string> all_ingredients_v(all_ingredients.begin(),all_ingredients.end());
    multiset<bitset<10000>,sortBitset> st;
    set<string> ing;
    map<bitset<10000>,vector<int>,sortBitsetless>mp;
    for(int i = 0;i<num_pizzas;i++){
        for(int j = 0;j<pizzas[i].size();j++){
            int idx = lower_bound(all_ingredients_v.begin(),all_ingredients_v.end(),pizzas[i][j])-all_ingredients_v.begin();
            // cout<<idx<<endl;
            // cout<<pizzas[i][j]<<" ";
            pizzas_bits[i][idx] = 1;
        }
        st.insert(pizzas_bits[i]);
        // cout<<endl;
        // cout<<"INSERT "<<pizzas_bits[i]<<endl;
        mp[pizzas_bits[i]].push_back(i);
    } 

    vector<vector<int>> ans ;
    // cout<<st.size()<<endl;
    // cout<<mp.size()<<endl;
    // for(auto c:mp){
        // cout<<c.first<<endl;
        // for(auto d:c.second)cout<<d<<" ";
        // cout<<endl;
    // }


    while(team_4--){
        if(st.size()<4)
            break;
        // cout<<"FIND team of 4"<<endl;
        vector<int> res;
        res.push_back(4);
        bitset<10000> mask = *st.begin();
        res.push_back(mp[*st.begin()].back());
        mp[*st.begin()].pop_back();
        // cout<<"Selecet "<<(*st.begin())<<" "<<mp[*st.begin()].back()<<endl;
        st.erase(st.begin());
        int cont = 3;
        while(cont--){
            int mx =-1;
            bitset<10000> who;
            for(auto x: st){
                // cout<<x<<endl;
                if(((int)(x.count()-(mask&x).count()))>mx){
                    mx = x.count()-(mask&x).count();
                    who = x;
                }
            }
            // cout<<"SELECTED "<<who<<" "<<mp[who].back()<<endl;
            st.erase(st.find(who));
            mask|=who;
            // cout<<"MASK "<<mask<<endl;
            res.push_back(mp[who].back());
            mp[who].pop_back();
        }
        ans.push_back(res);
    }
    while(team_2--){
        if(st.size()<2)
            break;
        // cout<<"FIND team of 4"<<endl;
        vector<int> res;
        res.push_back(2);
        bitset<10000> mask = *st.begin();
        res.push_back(mp[*st.begin()].back());
        mp[*st.begin()].pop_back();
        // cout<<"Selecet "<<(*st.begin())<<" "<<mp[*st.begin()].back()<<endl;
        st.erase(st.begin());
        int cont = 1;
        while(cont--){
            int mx =-1;
            bitset<10000> who;
            for(auto x: st){
                // cout<<x<<endl;
                if(((int)(x.count()-(mask&x).count()))>mx){
                    mx = x.count()-(mask&x).count();
                    who = x;
                }
            }
            // cout<<"SELECTED "<<who<<" "<<mp[who].back()<<endl;
            st.erase(st.find(who));
            mask|=who;
            // cout<<"MASK "<<mask<<endl;
            res.push_back(mp[who].back());
            mp[who].pop_back();
        }
        ans.push_back(res);
    }

    while(team_3--){
        if(st.size()<3)
            break;
        // cout<<"FIND team of 4"<<endl;
        vector<int> res;
        res.push_back(3);
        bitset<10000> mask = *st.begin();
        res.push_back(mp[*st.begin()].back());
        mp[*st.begin()].pop_back();
        // cout<<"Selecet "<<(*st.begin())<<" "<<mp[*st.begin()].back()<<endl;
        st.erase(st.begin());
        int cont = 2;
        while(cont--){
            int mx =-1;
            bitset<10000> who;
            for(auto x: st){
                // cout<<x<<endl;
                if(((int)(x.count()-(mask&x).count()))>mx){
                    mx = x.count()-(mask&x).count();
                    who = x;
                }
            }
            // cout<<"SELECTED "<<who<<" "<<mp[who].back()<<endl;
            st.erase(st.find(who));
            mask|=who;
            // cout<<"MASK "<<mask<<endl;
            res.push_back(mp[who].back());
            mp[who].pop_back();
        }
        ans.push_back(res);
    }


    cout<<ans.size()<<endl;
    for(auto c:ans){
        for(auto d:c)cout<<d<<" ";
        cout<<endl;
    }

    return 0;
}