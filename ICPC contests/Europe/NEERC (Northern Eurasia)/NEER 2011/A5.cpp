#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;


int main()
{
    int h , w , l = 0 , p = 0, t = 0;
    char a;
    cin >> h >> w;
    for(int i = 0 ; i <h ; i++)
    {
        t = 0;
        for(int j = 0 ; j < w ; j++)
        {
            cin >> a;
            if(a == '/' || a == '\\')
            {
                t++;
                l++;
            }else if(a == '.')
            {
                if(t%2!=0)
                    l+=2;
            }
        }
    }
    cout << (l/2) << '\n';

    return 0;
}