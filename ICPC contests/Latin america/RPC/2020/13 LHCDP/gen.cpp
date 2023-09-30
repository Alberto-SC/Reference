// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {

    srand(atoi(argv[1])); 
    int n,t;
    n = rand(1, 1000000);
    t = rand(1, 1000000);
    cout<<n<<" "<<t<<endl;
    cout<<rand(1,n)<<" "<<rand(1,n)<<" "<<rand(1,n)<<endl;
}
    
