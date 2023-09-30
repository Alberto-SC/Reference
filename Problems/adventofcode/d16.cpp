#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;

struct segmentos{
    string name;
    lli l1,r1,l2,r2;
};
#define M 20
#define N 20
  
bool bpm(bool bpGraph[M][N], lli u, 
         bool seen[], lli matchR[]) { 
    for (lli v = 0; v < N; v++) { 
        if (bpGraph[u][v] && !seen[v]) { 
            seen[v] = true;  
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
vector<lli> ans(N);
lli maxBPM(bool bpGraph[M][N]) { 
    lli matchR[N]; 
    memset(matchR, -1, sizeof(matchR)); 
    lli result = 0;  
    for (lli u = 0; u < M; u++) { 
        bool seen[N]; 
        memset(seen, 0, sizeof(seen)); 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    for(lli i = 0;i<N;i++)
        ans[i] =matchR[i];
    return result; 
} 


int main(){
    string s;
    vector<lli> segments(100000,0);
    bool your = true;
    lli invalid = 0;
    vector<vector<lli>> valids; 
    vector<segmentos> sv;
    while(getline(cin,s)){
        vector<string> nums;
        string w;	
        istringstream in(s);
        while(getline(in, w, ' ')){
            nums.push_back(w);
        }
        if(nums[0][0]== 13|| nums[0] == "your") continue;
        if(nums[0]== "nearby"){
            for(lli i = 1;i<=100000;i++){
                segments[i] = segments[i-1]+segments[i];    
            }
            continue;
        }
        if(nums[0][0]>='0' && nums[0][0]<='9' ){
            if(your){
                your = false;
                vector<lli> numbers;
                string z;
                istringstream in(nums[0]);
                while(getline(in,z,',')){
                    numbers.push_back(stoi(z));
                }
                valids.push_back(numbers);
                continue;
            }
            else{                
                vector<lli> numbers;
                string z;
                istringstream in(nums[0]);
                while(getline(in,z,',')){
                    numbers.push_back(stoi(z));
                }
                bool flag = true;
                for(auto c:numbers){
                    if(segments[c]==0){invalid+=c;flag = false;}
                }
                if(flag)valids.push_back(numbers);
            }
        }
        else{
            lli l1 = -1 ,r1,l2,r2;
            for(lli i = 0;i<nums.size();i++){
                if(nums[i][0]>='0' && nums[i][0]<='9'){
                    lli idx = 0;
                    while(nums[i][idx]!= '-'){
                        idx++;
                    }
                    if(l1==-1){
                        l1 = stoi(nums[i].substr(0,idx));
                        r1 = stoi(nums[i].substr(idx+1));
                    }
                    else{
                        l2 = stoi(nums[i].substr(0,idx));
                        r2 = stoi(nums[i].substr(idx+1));
                    }
                }
            }
            segments[l1]++;
            segments[r1+1]--;
            segments[l2]++;
            segments[r2+1]--;
            sv.push_back({nums[0],l1,r1,l2,r2});
        }
     
    }
    lli m = valids[0].size();
    vector<bool> usedk(m,false);
    vector<bool> usedi(m,false);
    bool bpGraph[M][N]; 
    for(int i = 0;i<m;i++)
        for(int j = 0;j<m;j++)
            bpGraph[i][j] = false;   
    vector<bool> trues(m,true);
    // while(usedk!= trues){
        for(lli k = 0;k<m;k++){
            // if(usedk[k])continue;
            int contvalids = 0;
            int valido;
            for(lli i = 0;i<m;i++){
                // if(usedi[i])continue;
                lli cont = 0;
                for(lli j = 0;j<valids.size();j++){
                        if((valids[j][i]>=sv[k].l1 &&  
                            valids[j][i]<=sv[k].r1)||
                            (valids[j][i]>=sv[k].l2 &&
                            valids[j][i]<=sv[k].r2))cont++;
                }
                if(cont == valids.size()){
                    // contvalids++;
                    bpGraph[i][k] = true;
                }
            }
            if(contvalids ==1){
                ans[k] = valido;
                usedk[k] = true;
                usedi[valido] = true; 
            }
        }
    // }

    for(int i = 0;i<m;i++)
        for(int j = 0;j<m;j++)
            cout<<bpGraph[i][j]<<" \n"[j==m-1];
    cout<<valids.size()<<endl;
    lli res = 1;    
    cout<<maxBPM(bpGraph)<<endl;
    for(lli i = 0;i<m;i++)
        cout<<i<<"-> "<<ans[i]<<endl;
    cout<<endl;
    for(lli i = 0;i<6;i++)
        res*=valids[0][ans[i]];
    cout<<res<<endl;
    return 0;
}