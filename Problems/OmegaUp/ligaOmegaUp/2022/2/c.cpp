#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
    int n;
    cin>>n;
    vector<int> x(n);
    for(auto &c:x)cin>>c;
    sort(x.begin(),x.end());
    double Q1 = 0,Q2 = 0,Q3 = 0;
    double j = (n+1)/4.0;
    if(ceil(j)==floor(j)){
        Q1 = x[(int)j];
    }
    else{
        int i = (int)j;
        double d = j-i;
        i--;
        Q1 = x[i] + d*(x[i+1]-x[i]);
    }

    if(n&1){
        Q2 = x[n/2];
    }
    else{
        Q2 = (x[n/2]+ x[(n/2)-1])/2.0;
    }

    j = (3*(n+1))/4.0;
    if(ceil(j)==floor(j)){
        Q3 = x[(int)j];
    }
    else{
        int i = (int)j;
        double d = j-i;
        i--;
        Q3 = x[i] + d*(x[i+1]-x[i]);
    }
    double IQR = Q3-Q1;
    double d = 1.5*IQR;
    vector<int> fliers;
    double b1 = -1,b2 = -1;
    for(int i = 0;i<n;i++){
        if(x[i]<Q1 &&isgreater(fabs(x[i]-Q1),d))fliers.push_back(x[i]);
        else if(x[i]>Q3 && isgreater(fabs(x[i]-Q3),d))fliers.push_back(x[i]);
        else {
            if(b1 ==-1)b1=x[i];
            b2 = x[i];
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<b1<<" "<<Q1<<" "<<Q2<<" "<<Q3<<" "<<b2<<endl;
    if(fliers.size()){
        for(auto c:fliers)cout<<c<<" ";
        cout<<endl;
    }
    else cout<<"No tiene"<<endl;

    if(isgreater(Q3-Q2,Q2-Q1))cout<<"Caja Arriba"<<endl;
    else if (isgreater(Q2-Q1,Q3-Q2))cout<<"Caja Abajo"<<endl;
    else cout<<"Nice Box!"<<endl;

    if(isgreater(b2-Q3,Q1-b1))cout<<"Bigote Arriba"<<endl;
    else if(isgreater(Q1-b1,b2-Q3))cout<<"Bigote Abajo"<<endl;
    else cout<<"Bigotazo!"<<endl;

    cout<<"El IQR es: "<<IQR<<endl;
    return 0;
}