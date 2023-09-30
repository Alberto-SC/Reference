#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(2);
    cin>>v[0];
    cin>>v[1];
    
    priority_queue<int> pq;
    pq.push(v[0]);
    pq.push(v[1]);

    for(int i = 0;i<n;i++){
        int mx1 = pq.top();
        pq.pop();
        int mx2 = pq.top();
            
        int a = mx1+mx2;
        int b = mx1-mx2;

        pq.push(mx1);
        pq.push(a);
        pq.push(b);
        v.push_back(a);
        v.push_back(b);
    }
    
    cout<<v.size()<<endl;
    sort(v.begin(),v.end());

    for(auto c:v)cout<<c<<" ";
    cout<<endl;

    return 0;
}
