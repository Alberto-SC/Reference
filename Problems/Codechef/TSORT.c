#include <stdio.h> 
int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i = 0;i<n;i++){
        getInt(nums[i]);
    }
    qsort (nums, n, sizeof(int), compare);
    for(int i = 0;i<n;i++){
        printf("%d\n",nums[i]);
    }
    return 0;
}
void getInt(int &n)  {
  n = 0;
  int ch = getchar_unlocked();
  int sign = 1;
 
  while (ch<'0' || ch>'9')  
  {
    if (ch == '-')
    {
      sign = -1;
    }   
    ch = getchar_unlocked();
  }
 
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';  
    ch = getchar_unlocked();
  }
  
  n *= sign;  
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
