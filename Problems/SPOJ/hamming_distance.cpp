#include <bits/stdc++.h>
using namespace std;

int hamming_distance(unsigned x, unsigned y)
{
    int dist = 0;
    unsigned  val = x ^ y;
    cout<<val<<endl;
    // Count the number of bits set
    while (val != 0)
    {
        // A bit is set, so increment the count and clear the bit
        dist++;
        val &= val - 1;
        cout<<val<<endl;
    }

    // Return the number of differing bits
    return dist;
}
int main(){
    int a = 32,b = 65;
    cout<<hamming_distance(a,b);
    return 0;
}