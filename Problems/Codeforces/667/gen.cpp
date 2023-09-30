// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli rand(lli a, lli b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); 
    lli t,n;
    int test = rand(1,10);
    cout<<test<<endl;
    while(test--){

        t = rand(1, 1000000000000000000);
        cout<<t<<" ";
        int sum = 0;
        while(t){
            sum+=t%10;
            t/=10;
        }
        n = rand(1,sum);
        cout<<n<<endl;
    }
}
    
