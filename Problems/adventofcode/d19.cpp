#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

set<string> possible;
vector<string> match;
vector<string> DP[10000];
void get_possibles(string rules){
    int n = rules.size();
    int j = 0;
    while(j<n && rules[j]>='0' && rules[j]<='9'){j++;}
    int idx = stoi(rules.substr(0,j));
    cout<<"STRING "<<rules<<endl;
    cout<<"IDX: "<<idx<<endl;
    if(DP[idx].size())return;
    rules = rules.substr(j+2);
    j = 0;
    n = rules.size();
    cout<<rules<<endl;
    while(j<n && rules[j]!= '|'){j++;}
    cout<<j<<" "<<n<<endl;
    if(j<n && rules[j]== '|'){
        cout<<"OR: "<<rules<<endl;
        string s1,s2;
        s1 = rules.substr(0,j);
        s2 = rules.substr(j+2);
        vector<int> numbers1;
        istringstream in1(s1);
        string w;
        while(getline(in1, w, ' ')){
            numbers1.push_back(stoi(w));            
        } 
        vector<int> numbers2;
        istringstream in2(s2);
        while(getline(in2, w, ' ')){
            numbers2.push_back(stoi(w));            
        } 

        for(auto c:numbers1){
            cout<<c<<" ";
            get_possibles(match[c]);
        }
        cout<<endl;
        for(auto c:numbers2){
            cout<<c<<" ";
            get_possibles(match[c]);
        }
        for(auto c:numbers2){
            cout<<c<<" ";
            get_possibles(match[c]);
        }
        cout<<"GET POSSIBLES FOR: "<<idx<<endl;        
        if(numbers1.size() == 1){
            for(int i = 0;i<DP[numbers1[0]].size();i++)
                DP[idx].push_back(DP[numbers1[0]][i]);
        }
        else if(numbers1.size()==2){
            for(int i = 0;i<DP[numbers1[0]].size();i++){
                for(int j = 0;j<DP[numbers1[1]].size();j++){
                    DP[idx].push_back(DP[numbers1[0]][i]+DP[numbers1[1]][j]);
                }
            }
        }
        else if(numbers1.size()==3){
            for(int i = 0;i<DP[numbers1[0]].size();i++){
                for(int j = 0;j<DP[numbers1[1]].size();j++){
                    for(int k = 0;k<DP[numbers1[2]].size();k++){
                        DP[idx].push_back(DP[numbers1[0]][i]+
                        DP[numbers1[1]][j]+DP[numbers1[2]][k]);
                    }
                }
            }
        }
        if(numbers2.size() == 1){
            for(int i = 0;i<DP[numbers2[0]].size();i++)
                DP[idx].push_back(DP[numbers2[0]][i]);
        }
        else if(numbers2.size()==2){
            for(int i = 0;i<DP[numbers2[0]].size();i++){
                for(int j = 0;j<DP[numbers2[1]].size();j++){
                    DP[idx].push_back(DP[numbers2[0]][i]+DP[numbers2[1]][j]);
                }
            }
        }
        else if(numbers2.size()==3){
            cout<<"3__________________________________________________________"<<endl;
                cout<<DP[numbers2[0]].size()<<" "<<DP[numbers2[1]].size();
            cout<<" "<<DP[numbers2[2]].size()<<endl;
            for(int i = 0;i<DP[numbers2[0]].size();i++){
                for(int j = 0;j<DP[numbers2[1]].size();j++){
                    for(int k = 0;k<DP[numbers2[2]].size();k++){
                        if((lli)DP[numbers2[0]][i].size()+
                            (lli)DP[numbers2[1]][j].size()+
                            (lli)DP[numbers2[2]][k].size()>200)continue;
                        DP[idx].push_back(DP[numbers2[0]][i]+
                        DP[numbers2[1]][j]+DP[numbers2[2]][k]);
                    }
                }
            }
        }
        else if(numbers2.size()==4){
            cout<<DP[numbers2[0]].size()<<" "<<DP[numbers2[1]].size();
            cout<<" "<<DP[numbers2[2]].size()<<" "<<DP[numbers2[3]].size()<<endl;
            for(int i = 0;i<100;i++){
                cout<<"Hi "<<i<<endl;
                for(int j = 0;j<DP[numbers2[1]].size();j++){
                    for(int k = 0;k<DP[numbers2[2]].size();k++){
                        for(int z = 0;z<DP[numbers2[3]].size();z++){
                            if((lli)DP[numbers2[0]][i].size()+
                            (lli)DP[numbers2[1]][j].size()+
                            (lli)DP[numbers2[2]][k].size()+
                            (lli)DP[numbers2[3]][z].size()>200)continue;
                            DP[idx].push_back(DP[numbers2[0]][i]+
                            DP[numbers2[1]][j]+DP[numbers2[2]][k]+
                            DP[numbers2[3]][z]);
                        }
                    }
                }
            }
        }
    }
    else{
        bool flag = false; 
        for(int i = 0;i<n;i++){
            if(rules[i]== '"'){ 
                DP[idx].push_back(rules.substr(i+1,1));
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"LETTER "<<DP[idx][0]<<endl;
            return;
        }
        cout<<"OTHER RULES"<<endl;
        vector<int> numbers;
        istringstream in(rules);
        string w;
        while(getline(in, w, ' ')){
            numbers.push_back(stoi(w));            
        }
        for(auto c:numbers)cout<<c<<" ";
        cout<<endl;
        cout<<"RECURCION"<<endl;
        for(int i = 0;i<numbers.size();i++){
            get_possibles(match[numbers[i]]);
        }
        cout<<"GET POSSIBLES FOR: "<<idx<<endl;
        if(numbers.size() == 1){
            for(int i = 0;i<DP[numbers[0]].size();i++)
                DP[idx].push_back(DP[numbers[0]][i]);
        }
        else if(numbers.size()==2){
            for(int i = 0;i<DP[numbers[0]].size();i++){
                for(int j = 0;j<DP[numbers[1]].size();j++){
                    DP[idx].push_back(DP[numbers[0]][i]+DP[numbers[1]][j]);
                }
            }
        }
        else if(numbers.size()==3){
            for(int i = 0;i<DP[numbers[0]].size();i++){
                for(int j = 0;j<DP[numbers[1]].size();j++){
                    for(int k = 0;k<DP[numbers[2]].size();k++){
                        DP[idx].push_back(DP[numbers[0]][i]+
                        DP[numbers[1]][j]+DP[numbers[2]][k]);
                    }
                }
            }
        }
    }
}
int main(){
    string s;
    while(getline(cin,s)){
        match.push_back(s);
    }
    vector<string>copy = match;
    for(int i = 0;i<copy.size();i++){
        if(copy[i][0]== 13)break;
        else {
            int j = 0;
            while(copy[i][j]>='0' && copy[i][j]<='9'){j++;}
            int num = stoi(copy[i].substr(0,j));
            match[num] = copy[i];
        }
    }
    int ans = 0;
    vector<string> to_check;
    for(int i = 0;i<match.size();i++){
        // cout<<match[i]<<endl;
        if(match[i][0]== 13)continue;
        if(match[i][0]>='a' && match[i][0]<='z'){
            if(match[i].back()==13)match[i].pop_back();
            to_check.push_back(match[i]);
        }
        else{
            get_possibles(match[i]);
        }
    }
    cout<<endl<<endl;
    // for(int i = 5;i<=5;i++){
    set<string> st;
    for(auto c:DP[8]){
        cout<<c<<endl;
        st.insert(c);
    }
    // }
    cout<<endl;
    cout<<match.size()<<endl;
    cout<<st.size()<<endl;
    for(auto c:to_check){
        if(st.count(c))ans++;
        // cout<<c<<endl;
    }
    cout<<ans<<endl;
    return 0;
}