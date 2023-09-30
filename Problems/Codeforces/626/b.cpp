#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<int> divisors;
void getdivisors(int s){
    for(int i = 1;i*i<=s;i++){
        if(s%i==0){
            if(i*i==s)divisors.push_back(i);
            else {divisors.push_back(i);divisors.push_back(s/i);}
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m,s;
    cin>>n>>m>>s;
    vector<int> r1(n);
    vector<int> r2(m);
    vector<int> ones1;
    vector<int> ones2;
    for(auto &c:r1)cin>>c;
    for(auto &c:r2)cin>>c;
    getdivisors(s);
    for(int i = 0;i<n;i++){
        int ones  = 0;
        while(r1[i]==1){ones++;i++;}
        if(ones>0)ones1.push_back(ones);
    }
     for(int i = 0;i<m;i++){
        int ones  = 0;
        while(r2[i]==1){ones++;i++;}
        if(ones>0)ones2.push_back(ones);
    }
    sort(ones1.begin(),ones1.end());
    sort(ones2.begin(),ones2.end());
    sort(divisors.begin(),divisors.end());
    lli ans = 0;
    for(int i = 0;i<ones1.size();i++){
        for(int j = 0;j<divisors.size();j++){
            if(ones1[i]<divisors[j])break;
            int index = lower_bound(ones2.begin(),ones2.end(),s/divisors[j])-ones2.begin();
            // cout<<"INDEx "<<index<<" divisor "<<divisors[j]<<" "<<ones2.size()<<endl;
            for(int k= index;k<ones2.size();k++)
                ans+= (lli)(ones1[i]-divisors[j]+1)*((ones2[k]-(s/divisors[j]))+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}