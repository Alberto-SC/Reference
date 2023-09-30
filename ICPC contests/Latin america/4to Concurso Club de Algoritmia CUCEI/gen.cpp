// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(5, 8);
    int k = rand(1,3);
    cout<<n<<" "<<k<<endl;
    for(int i = 0;i<n;i++){
        cout<<char(rand(0,5)+'a');
    }
    cout<<endl;
    
}

