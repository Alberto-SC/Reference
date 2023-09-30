// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    int n,q;
    n = rand(1, 20);
    q = rand(10, 1000);
    cout<<n<<" "<<q<<endl;
    for(int i = 0;i<q;i++){
        int x = rand(0,2);
        if(x== 0){
            int u = rand(1,n);
            int v = rand(1,n);
            cout<<"R "<<u<<" "<<v<<endl;
        }
        else if(x ==1){
            cout<<"Q "<<rand(1,n)<<endl;
        }
        else{
            cout<<"B"<<endl;
        }
    }    
}

    
