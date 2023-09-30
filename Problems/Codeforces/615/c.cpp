#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> trial_division2(int n) {
    vector<pair<int,int>>fact;
    int p = -1;
    if(n%2== 0){
        fact.push_back({2,1});
        n/=2;
        p++;
        while (n % 2 == 0) {
            fact[p].second++;
            n /= 2;
        }
    }
    for (int d = 3; d * d <= n; d += 2) {
        if(n%d == 0){p++;fact.push_back({d,1});n/=d;}
        while (n % d == 0) {
            fact[p].second++;
            n /= d;
        }
    }
    if (n > 1)
        fact.push_back({n,1});
    return fact;
}


int main(){
    ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<fixed<<setprecision(0);
        vector<pair<int,int> > f;
        f = trial_division2(n);
        if(f.size()>3){
            cout<<"YES"<<endl;
            cout<<pow(f[0].first,f[0].second)<<" "<<pow(f[1].first,f[1].second)<<" ";
            int last= pow(f[2].first,f[2].second);
            for(int i =3;i<f.size();i++)
                last*=pow(f[i].first,f[i].second);
            cout<<last<<endl;
        }
        else if(f.size()==3){
            cout<<"YES"<<endl;
            for(pair<int,int> c:f)cout<<pow(c.first,c.second)<<" ";
            cout<<endl;
        }
        else if(f.size()==2){
            if(f[0].second>2||f[1].second>2){
                cout<<"YES"<<endl;
                if(f[0].second>2)cout<<f[0].first<<" "<<pow(f[0].first,f[0].second-1)<<" "<<pow(f[1].first,f[1].second)<<endl;
                else cout<<f[1].first<<" "<<pow(f[1].first,f[1].second-1)<<" "<<pow(f[0].first,f[0].second)<<endl;
            }
            else if(f[0].second == 2&& f[1].second==2)cout<<"YES"<<endl<<f[0].first<<" "<<f[1].first<<" "<<f[0].first*f[1].first<<endl;
            else cout<<"NO"<<endl;
        }
        else if(f.size()==1){
            if(f[0].second>=6){

                cout<<"YES"<<endl;
                cout<<f[0].first<<" "<<pow(f[0].first,2)<<" "<<pow(f[0].first,f[0].second-3)<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
}
// 5
// 64
// 32
// 97
// 2
// 12345