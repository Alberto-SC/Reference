// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {

    srand(atoi(argv[1])); 
    int t,n;
    t = rand(1, 10);
    cout<<t<<endl;
    while(t--){
        n = rand(2,10000);
        cout<<n<<endl;
    }
}
    
