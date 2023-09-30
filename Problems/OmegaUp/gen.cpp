// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    int n,m,q;
    n = rand(300000,300000);
    m = rand(300000,300000);
    q = rand(300000,300000);
    cout<<n<<" "<<m<<" "<<q<<endl;
    for(int i = 0;i<n;i++){
        cout<<rand(1,m)<<" ";
    }
    cout<<endl;
    for(int i = 0;i<q;i++){
        cout<<rand(1,n)<<" "<<rand(1,n)<<" "<<rand(1,m)<<" "<<rand(1,m)<<endl;
    }
    cout<<endl;
}
    
