#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> points(n);
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            points[i] = {x,y};
        }
        bool flag = true;
        sort(points.begin(),points.end());
        for(int i = 1;i<n;i++)
            if(points[i].second<points[i-1].second)flag = false;;
        if(flag){
            cout<<"YES"<<endl;
            int a = 0,b = 0,aa= points[0].first,bb =0 ,i ;
            for(i = 0;i<n;){
                while(points[i].first == aa){i++;}
                for(int j = a;j<aa;j++)cout<<"R";
                for(int j = b;j<points[i-1].second;j++)cout<<"U";
                aa = points[i].first;
                a = points[i-1].first;
                b = points[i-1].second;
            }
            for(int j = b;j<points[i-1].second;j++)cout<<"U";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
        
    }
    return 0;
}