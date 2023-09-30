#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        set<string> profs;
        string s;
        getline(cin, s);
        bool flag= false;
        for(int i = 1;i<=n;i++){
            getline(cin, s);
            istringstream in(s);
            vector<string> words;
            string w;
            while(getline(in, w, ' ')){
                words.push_back(w);
            }
            flag = false;
            bool C = false;
            for(int j = 0;j<words.size();j++){
                if(words[j]=="->"){
                    C = true;
                    continue;
                }
                if(!C){
                    if(!profs.count(words[j]))
                        flag= true;
                }
                else{
                    profs.insert(words[j]);
                }
            }
            if(flag){
                cout<<i<<endl;
                break;
            }
        }
        if(!flag)cout<<"correct"<<endl;
    }
    return 0;
}  
