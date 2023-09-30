// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {

    srand(atoi(argv[1])); 
    int n,m,q,k;
    n = 200;
    m = (200*200)-200;
    q = 200;
    cout<<n<<" "<<m<<" "<<q<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i!= j)
                cout<<i<<" "<<j<<endl;
        }
    }
    for(int i = 0;i<q;i++){
        int u = rand(1,n);
        int v = rand(1,n);
        int k = rand(100000000,1000000000);
        cout<<u<<" "<<v<<" "<<k<<endl;
    }
}
    
