// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1])); 
    int n,m;
    n = rand(3,10);
    cout<<n<<endl;
    m = rand(3,10);
    cout<<m<<endl;
    for(int i = 0;i<n;i++){
        int u = rand(1,5);
        cout<<char(u+'a');
    }
    cout<<endl;
    for(int i = 0;i<m;i++){
        int u = rand(1,5);
        cout<<char(u+'a');
    }
    cout<<endl;
}
    
