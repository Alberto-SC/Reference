#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,a,b,c;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> products;
        for(int i = 0;i<n;i++){
            cin>>a>>b>>c;
            if(a>=b && a<=c){
                products.products(b);
                products.products(c);
            }
            else if(b>=a && b >=c){
                products.products(a);
                products.products(c);
            }
            else{
                products.products(b);
                products.products(a);
            }

        }
        sort(products.begin(),products.end());
        int sum = 0;
        for(int i = 0;i<k;i++)
            sum+=products[i];
        cout<<sum;
    }

    return 0;
}