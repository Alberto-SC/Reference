#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c: A)cout<<c<<" ";
int main(){
    ios_base::sync_with_stdio(0);
	std::ios::sync_with_stdio(0);
    ios::sync_with_stdio(false), cin.tie(0);
    int n,a;
    cin>>n;
    vector<int> vec(n);
    int minr = 200,maxmin = -10;
    for(int i = 0;i<n;i++){
            minr = 200;
        for(int j = 0;j<n;j++){
            cin>>a;
            minr = min(minr,a);
        }
        maxmin = max(maxmin,minr);
    }
    cout<<maxmin;
    return 0;
}