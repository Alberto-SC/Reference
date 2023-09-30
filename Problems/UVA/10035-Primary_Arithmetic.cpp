#include <iostream>
using namespace std;
int main(){
    int a, b;
    int count, res;
    while(cin>>a>>b){
        if(!(a or b))break;
        res=0;
        count=0;
        while(a||b){
            res=((a%10)+(b%10)+res)/10;
            a/=10;
            b/=10;
            count+=res;
        }
        if(count == 0)
            cout<<"No carry operation."<<endl;
        else if(count == 1)
        	cout<<"1 carry operation."<<endl;
        else
            cout<<count<<" carry operations."<<endl;
    }
    return 0;
}