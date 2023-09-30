#include <bits/stdc++.h>
using namespace std;

//Pendiente
class RabbitStepping{
    public:

    int solve(int mask,int field){
        int n = field.size();
        vector<int> pos;
        for(int i = 0;i<n;i++)
            if((mask>>i)&1)pos.push_back(i);
        
        vector<int> lastpos = pos;
        bool first = true;
        int r = r.size();
        while(n>2){
            for(int i = 0;i<r;i++){
                if(pos[i]>=n)continue;
                if(pos[i] == 0 || field[pos[i]] == 'B'){
                    pos[i]++;
                }
                else if(pos[i] == n-1|| pos[i] == n-2 || field[pos[i]]== 'W'){
                    pos[i]--;
                }
                else if(field[i]== 'R' && first){
                    pos[i]--;
                }
                else{
                    pos[i] = lastpos[i];
                }
            }       
            for(auto c:pos){

            }
            for(int i = 0;i<n;i++){
                if(cont[i]>1)cont[i] = 0;
            }
            vector<int> newpos;
            lastpos = pos;
            first = false;
            n--;
        }
        vector<int> cont(2);
        for(auto c:pos){
            if(c>1)continue;
            cont[c]++;
        }
        return cont[0]+cont[1];

    }

    double getExpected(string field, int r){
        int n = field.size();
        for(int mask = 0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)==r){
                int remain = solve(mask); 
            }
        }
    }
};

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> counts(m);
    for(auto &c:counts)cin>>c;
    collisionProbability solve;
    cout<<fixed<<setprecision(10);
    cout<<solve.collisionProbability2(n,counts);
}

