#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<string> answer;
    int ans = 0;
    do{ 
        if(s[0] == 13){
            vector<int> b(26);
            cout<<"NEW"<<endl;
            set<char> st;
            for(auto c: answer){
                if(c.back()==13)c.pop_back();
                cout<<c<<endl;
                for(auto d:c){
                    st.insert(d);
                    b[d-'a']++;
                }
            }
            
            int cont = 0;
            cout<<answer.size()<<endl;
            for(auto c:st)cout<<c<<" ";
            cout<<endl;
            for(int i = 0;i<26;i++){
                cout<<b[i]<<" ";
                if(b[i]==answer.size())cont++;
            }
            cout<<endl;
            // ans+=st.size();
            cout<<"ANS "<<ans<<endl;
            answer.clear();
        }
        else{
            istringstream in(s);
            string w;
            while(getline(in, w, ' ')){
                answer.push_back(w);
            }
        }
    }while(getline(cin,s));

    cout<<ans<<endl;
    return 0;
}