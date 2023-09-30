#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

map<string,int>days = {{"Lunes",0}, {"Martes",1}, {"Miércoles",2}, {"Jueves",3}, {"Viernes",4}, {"Sábado",5}, {"Domingo",6}};
vector<string> days1 = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};

string getDay(int a,int b){
    return days1[(a+b)%7];
}

signed main(){__
    int n,s;
    string day;
    
    cin>>n>>s>>day;
    vector<double> x(n);
    for(auto &c:x)cin>>c;
    double m = 0;
    for(int i = 0;i<n;i++)
        m+=x[i];
    
    m/=n;
    double des = 0;
    for(int i = 0;i<n;i++){
        des+= (x[i]-m)* (x[i]-m);
    }
    des/=n;
    des = sqrt(des);
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(isgreater(fabs(x[i]-m),s*des))cout<<"Día #"<<i<<" - "<<getDay(days[day],i)<<" - "<<(x[i]>m?"Más de los normal":"Menos de los normal")<<endl,cont++;
    }
    if(!cont)cout<<"No hubo anomalías"<<endl;
    return 0;
}