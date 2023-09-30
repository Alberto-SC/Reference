#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<string> answer;
    int ans = 0;
    vector<pair<string,int>> inst;
    vector<bool> used;
    while(getline(cin,s)){
        istringstream in(s);
        string w;
        vector<string> ins;
        while(getline(in, w, ' ')){
            ins.push_back(w);
        }
        int num = stoi(ins[1]);
        used.push_back(false);
        inst.push_back({ins[0],num});
    }
    for(auto c:inst){
        cout<<c.first<<" "<<c.second<<endl;
    }
    int i = 0;
    int total = 0;
    while(!used[i]){
        cout<<i<<endl;
        used[i] = true;
        if(inst[i].first== "nop")i++;
        else if(inst[i].first == "acc")total+=inst[i].second,i++;
        else if(inst[i].first == "jmp")i+=inst[i].second;
    }   
    cout<<total<<endl;
    cout<<endl;
    return 0;
}