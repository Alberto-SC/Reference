// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {

    srand(atoi(argv[1])); 
    int t,k,x;
    cout<<99*99<<endl;
        for(int i=2;i<=100;i++)
            for(int j = 2;j<=100;j++)
                cout<<i<<" "<<j<<endl;
}
    
 