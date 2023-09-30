#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int n,m;
    cin>>n;
    vector<string> words(n);
    for(auto &c:words)cin>>c;
    cin>>m;
    map<string,vector<string>> mpc;
    map<string,vector<string>> mpi;
    string s,t,type;
    for(int i = 0;i<m;i++){
        cin>>s>>t>>type;
        if(type== "correct")
            mpc[s].push_back(t);
        else
            mpi[s].push_back(t);
    }
    lli correct = 1;
    lli total = 1;
    string translated ="";
    for(int i = 0;i<n;i++){
        if(mpc.count(words[i]))
            translated+=mpc[words[i]][0]+" ";
        else 
            translated+=mpi[words[i]][0]+" ";
        int sum = 0;
        if(mpc.count(words[i]))sum+=mpc[words[i]].size();
        correct*=sum;
        if(mpi.count(words[i]))sum+=mpi[words[i]].size();
        total*=sum;
    }
    if(total == 1){
        cout<<translated<<endl;
        bool flag= true;
        for(int i = 0;i<n;i++){
            if(mpi.count(words[i]))flag = false;
        }
        if(flag)cout<<"correct"<<endl;
        else cout<<"incorrect"<<endl;
    }
    else{
        cout<<correct<<" correct"<<endl;
        cout<<(total-correct)<<" incorrect"<<endl;
    }
    return 0;
}  

