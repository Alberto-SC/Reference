// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    int n,k,z;
    cout<<1<<endl;
    n = rand(100, 100);
    z = rand(0,5);
    k = rand(1,n-1);
    cout<<n<<" "<<k<<" "<<z<<endl;
    for(int i = 0;i<n;i++){
        int u =  rand(1,10000);
        cout<<u<<" ";
    }
    cout<<endl;
}
    
