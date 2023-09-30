#include <bits/stdc++.h>
using namespace std;
const double eps = 10e-6;
int main(){
    long double y1,x,k;
    cin>>k;
    vector<pair<int,int>> ans;
    for(int i = 2*k;i>k;i--){
        x = k/(1.0-(k/(i*1.0)));
        long double x2 = round(x);
        if((fabs(x2-x)<eps))round(x);
        x = (int)round(x);
        int a1,a2;
        a1 = k*(i+x);
        a2 = i*x;
        if(a1==a2 && x>=i && x>0)ans.push_back({floor(x),i});
        // if(ceil(x)==floor(x) && floor(x)>=i && floor(x)>0){
            // ans.push_back({i,floor(x)});
        // }
    }
    cout<<ans.size()<<endl;
    for(int i = ans.size()-1;i>=0;i--){
        cout<<"1/"<<k<<" = 1/"<<ans[i].first<<" + 1/"<<ans[i].second<<endl;
    }
    return 0;
}