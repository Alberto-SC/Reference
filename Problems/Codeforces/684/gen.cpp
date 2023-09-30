// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {

    srand(atoi(argv[1])); 
    int t,n;
    n = 1<<15;
    cout<<n<<endl;
    for(int i = 0;i<n;i++){
        cout<<5<<" "<<3<<endl;
        for(int j = 0;j<15;j++)
            if((i>>j)&1)cout<<1;
            else cout<<0;
        cout<<endl;
    }
    
}
    
