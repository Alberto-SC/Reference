// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int t = rand(1,3);
    cout<<t<<endl;
    while(t--){
        int n = rand(2, 15);
        cout<<n<<endl;
        vector<int> perm(n);
        for(int i = 0;i<n;i++)
            perm[i] = rand(1,n);
        // iota(perm.begin(),perm.end(),1);
        // random_shuffle(perm.begin(),perm.end());
        for(auto c:perm)cout<<c<<" ";
        cout<<endl;
    }
}

