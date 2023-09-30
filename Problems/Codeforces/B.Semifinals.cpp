#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> all;
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i];
        all.push_back(a[i]);
        all.push_back(b[i]);
    }
    sort(all.begin(),all.end());
    string sa = string(n/2,'1');
    string sb = string(n/2,'1');
    for(int i = n/2;i<n;i++){
        int index = lower_bound(all.begin(),all.end(),a[i])-all.begin();
        if(index<n)sa+="1";
        else sa+="0"; 
        index = lower_bound(all.begin(),all.end(),b[i])-all.begin();
        if(index<n)sb+="1";
        else sb+="0"; 
    }   
    cout<<sa<<endl<<sb<<endl;
    return 0;
}