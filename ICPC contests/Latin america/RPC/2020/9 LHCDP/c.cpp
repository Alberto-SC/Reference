#include <bits/stdc++.h>
using namespace std;
set<string> st;
int n;
map<string,int> mp;
bool comp(pair<string,string> A,pair<string,string> B){
    return mp[A.second]<mp[B.second];
}
int main(){
    int q;
    cin>>n;
    string s;

    for(int i = 0;i<n;i++){
        cin>>s;
        st.insert(s);
        mp[s] = i;
    }
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>s;
        cout<<s<<endl;
        bool flag = false;
        if(st.find(s)!= st.end())cout<<"CORRECT"<<endl,flag = true;
        if(flag){cout<<endl;continue;}
        vector<pair<string,string>> ans;
        map<string,int> mp2;
        for(int j = 0;j<s.size();j++){
            string aux;
            for(int k = 0;k<s.size();k++){
                if(k == j)continue;
                aux+=s[k];
            }
            // cout<<aux<<endl;
            if(st.find(aux) != st.end() && aux!= s){
                string res = "ONE LETTER ADDED TO "+aux;
                flag = true;
                if(!mp2.count(aux))
                    ans.push_back({res,aux});
                mp2[aux]=1; 
            } 
        }
        // cout<<endl;
        for(int j = 0;j<s.size();j++){
            string aux;
            for(int k = 0;k<26;k++){
                aux = s.substr(0,j)+char(k+'a')+s.substr(j);
                if(st.find(aux)!= st.end() && aux!= s){
                    string res = "ONE LETTER OMITTED FROM "+ aux;
                    flag = true;
                    if(!mp2.count(aux))
                        ans.push_back({res,aux});
                    mp2[aux] =1;
                }
            }
           
        }
        for(int k = 0;k<26;k++){
            string aux = s+char(k+'a');
            if(st.find(aux)!= st.end() && aux!= s){
                string res = "ONE LETTER OMITTED FROM "+ aux;
                flag = true;
                if(!mp2.count(aux))
                    ans.push_back({res,aux});
                mp2[aux] = 1;
            }
        }
        // cout<<endl;
        for(int j = 0;j<s.size()-1;j++){
            string aux = s;
            aux[j]^=aux[j+1];
            aux[j+1]^=aux[j];
            aux[j]^=aux[j+1];
            // cout<<aux<<endl;
            if(st.find(aux) != st.end() && aux!= s){
                string res = "TWO LETTERS TRANSPOSED IN "+aux;
                flag = true;
                if(!mp2.count(aux))
                    ans.push_back({res,aux});
                mp2[aux] = 1;
            }
        }
        // cout<<endl;
        for(int j = 0;j<s.size();j++){
            string aux = s;
            for(int k = 0;k<26;k++){
                // cout<<aux<<endl;
                aux[j] = char(k+'a');
                if(st.find(aux)!= st.end() && aux!=s){
                    string res = "ONE LETTER DIFFERENT FROM "+aux;
                    if(!mp2.count(aux))
                        ans.push_back({res,aux});
                    mp2[aux]= 1;
                    flag = true;
                }
            }
        }
        if(!flag)cout<<"UNKNOWN"<<endl;
        else{
            sort(ans.begin(),ans.end(),comp);
            for(auto c:ans)cout<<c.first<<endl;
        }
        cout<<endl;

    }
    return 0;
}