#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class collisionProbability{
public:
    double collisionProbability2(int num, vector <int> counts){
        lli total =0;
        int cont = 0;
        for(auto c:counts){
            total+=c;
            if(c == 0)cont++;
            if(c>num)return 1.0;
        }
        if(total > num)return 1.0;
        if(cont == counts.size()-1)return 0.0;
        else {
            long double ans = 0;
            cout<<total<<endl;
            for(int i = 2;i<total;i++){
                long double x = (num-1)*((i*(i+1))/2.0);
                x/=(num*num);
                // cout<<x<<endl;
                ans+=x;
            }
            ans+= 1.0/(num*num);
            return (do)ans;
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

