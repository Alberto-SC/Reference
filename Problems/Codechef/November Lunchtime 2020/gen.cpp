// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {

    cout<<101*101<<endl;
    for(int i = 0;i<=100;i++){
        for(int j = 0;j<=100;j++){
            cout<<i<<" "<<j<<" "<<100<<endl;
        }
    }
}
    
