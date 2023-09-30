#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,a,b,c;
    cin>>t;
    vector<int> products;
    while(t--){
        cin>>n>>k;
        products.clear();
        for(int i = 0;i<n;i++){
            cin>>a>>b>>c;
            if(a >=b && a>= c){
                products.push_back(b);
                products.push_back(c);
            }
            else if(b >= a && b >= c){
                products.push_back(a);
                products.push_back(c);
            }
            else if(c >= a&& c >= b){
                products.push_back(b);
                products.push_back(a);
            }

        }
        sort(products.begin(),products.end());
        int sum = 0;
        int cont = 0;
        for(int i = 0;i<products.size();i++){
            if(cont != k){
                sum+=products[i];
                cont ++;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}