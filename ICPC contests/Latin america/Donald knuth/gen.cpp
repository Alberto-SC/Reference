// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    int n = 10000;
    cout<<n<<endl;
    for(int i = 0;i<n;i++){
        int x = rand(1,18);
        for(int j = 0;j<x;j++){
        cout<<char(rand(1,9)+'0');
        }
        cout<<endl;
    }
    cout<<n<<endl;
}
    
