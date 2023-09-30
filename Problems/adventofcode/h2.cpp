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
    vector<int> change;
    for(int i = 0;i<inst.size();i++){
        if(inst[i].first == "nop")change.push_back(i);
        else if(inst[i].first == "jmp")change.push_back(i);
    }
    for(int i = 0;i<change.size();i++){
        if(inst[change[i]].first== "nop"){
            int idx = 0,total = 0;
            inst[change[i]].first = "jmp";
            used.assign(inst.size(),false);
            while(!used[idx] && idx<inst.size()){
                // cout<<i<<endl;
                used[idx] = true;
                if(inst[idx].first== "nop")idx++;
                else if(inst[idx].first == "acc")total+=inst[idx].second,idx++;
                else if(inst[idx].first == "jmp")idx+=inst[idx].second;
            }   
            inst[change[i]].first = "nop";
            if(idx>=inst.size()){cout<<"FIN "<<total<<endl;break;}
        }
        else if(inst[change[i]].first== "jmp"){
            int idx = 0,total = 0;
            inst[change[i]].first = "nop";
            used.assign(inst.size(),false);
            while(!used[idx] && i<inst.size()){
                // cout<<i<<endl;
                used[idx] = true;
                if(inst[idx].first== "nop")idx++;
                else if(inst[idx].first == "acc")total+=inst[idx].second,idx++;
                else if(inst[idx].first == "jmp")idx+=inst[idx].second;
            }   
            inst[change[i]].first = "jmp";
            if(idx>=inst.size()){cout<<"FIN "<<total<<endl;break;}
            
        }   
    }
    return 0;
}