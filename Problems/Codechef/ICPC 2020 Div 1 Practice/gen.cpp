// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(1,100);
    int m = rand(1,100);
    for(int i = 0;i<n;i++){
        cout<<char(rand(0,25)+'a');
    }
    cout<<endl;
    for(int i = 0;i<m;i++){
        cout<<char(rand(0,25)+'a');
    }
    cout<<endl;

}

