
#include <stdio.h>
#include <stdlib.h>

#define EXTRA 10

#define in32(x) scanf("%d", &x)
#define out64(x) printf("%lld\n", x)

typedef long long int lli;

int n;

int compare2(int * a, int * b) {
    if (a[0] < b[0])
        return -1;
    if (a[0] > b[0])
        return 1;
    if (a[1] < b[1])
        return -1;
    if (a[1] > b[1])
        return 1;
    return 0;
}

int compare(int * a, int * b) {
    if (a[0] < b[0])
        return -1;
    if (a[0] > b[0])
        return 1;
    if (a[1] < b[1])
        return 1;
    if (a[1] > b[1])
        return -1;
    return 0;
}

lli sum(int * arr, int x) {
    lli ret = 0;
    x++;
    while (x) {
        ret += arr[x];
        x ^= (x&-x);
    }
    return ret;
}

void inc2(int * arr, int x, int v) {
    x++;
    while (x < n+EXTRA) {
        arr[x] += v;
        x += (x&-x);
    }
}

void sort3(int ** arr, int n) {
    if (n < 10) {
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j && compare2(arr[j], arr[j - 1]) == -1) {
                int * tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
        }
        return;
    }
    int m = (n>>1);
    sort3(arr, m);
    sort3(arr + m, n - m);
    int ** tmp = (int **) calloc(n, sizeof(int *));
    int fptr = 0;
    int bptr = m;
    for (int i = 0; i < n; i++) {
        if (fptr == m || (bptr != n && compare2(arr[bptr], arr[fptr]) == -1))
            tmp[i] = arr[bptr++];
        else 
            tmp[i] = arr[fptr++];
    }
    for (int i = 0; i < n; i++)
        arr[i] = tmp[i];
    free(tmp);
}

void sort2(int * arr, int n) {
    if (n < 10) {
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j && arr[j] < arr[j - 1]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
        }
        return;
    }
    int m = (n>>1);
    sort2(arr, m);
    sort2(arr + m, n - m);
    int * tmp = (int *) calloc(n, sizeof(int));
    int fptr = 0;
    int bptr = m;
    for (int i = 0; i < n; i++) {
        if (fptr == m || (bptr != n && arr[bptr] < arr[fptr]))
            tmp[i] = arr[bptr++];
        else 
            tmp[i] = arr[fptr++];
    }
    for (int i = 0; i < n; i++)
        arr[i] = tmp[i];
    free(tmp);
}

void sort(int ** arr, int n) {
    if (n < 10) {
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j && compare(arr[j], arr[j - 1]) == -1) {
                int * tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
        }
        return;
    }
    int m = (n>>1);
    sort(arr, m);
    sort(arr + m, n - m);
    int ** tmp = (int **) calloc(n, sizeof(int *));
    int fptr = 0;
    int bptr = m;
    for (int i = 0; i < n; i++) {
        if (fptr == m || (bptr != n && compare(arr[bptr], arr[fptr]) == -1))
            tmp[i] = arr[bptr++];
        else 
            tmp[i] = arr[fptr++];
    }
    for (int i = 0; i < n; i++)
        arr[i] = tmp[i];
    free(tmp);
}

int find(int target, int * arr, int n) {
    int lo = 0;
    int hi = n - 1;
    int ret = 0;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (arr[mid] == target)
            ret = mid;
        if (arr[mid] >= target)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return ret;
}

int main() {
    in32(n);
    int ** points = (int **) calloc(n, sizeof(int*));
    int * arr_x = (int *) calloc(n, sizeof(int));
    int * arr_y = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        points[i] = (int *) calloc(3, sizeof(int));
        in32(points[i][0]);
        in32(points[i][1]);
        arr_x[i] = points[i][0];
        arr_y[i] = points[i][1];
        points[i][2] = i;
    }
    sort2(arr_x, n);
    sort2(arr_y, n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr_y[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        points[i][0] = find(points[i][0], arr_x, n) + 1;
        points[i][1] = find(points[i][1], arr_y, n) + 1;
    }
    sort(points, n);
    for(int i = 0;i<n;i++){
        printf("%d %d %d\n",points[i][0],points[i][1],points[i][2]);
    }
    printf("\n");
    lli ans = 0;
    int * bit = (int *) calloc(n + EXTRA, sizeof(int));
    lli * back = (lli *) calloc(n, sizeof(lli));
    for (int i = 0; i < n; i++) {
        lli fwd = sum(bit, points[i][1] - 1);
        ans += (fwd * (fwd - 1)) >> 1;
        inc2(bit, points[i][1], 1);
    }
    for (int i = 0; i < n + EXTRA; i++)
        bit[i] = 0;
    for (int i = n - 1; i >= 0; i--) {
        back[points[i][2]] = sum(bit, n + 1) - sum(bit, points[i][1]);
        inc2(bit, points[i][1], 1);
    }
    for (int i = 0; i < n + EXTRA; i++)
        bit[i] = 0;
    sort3(points, n);
    for(int i = 0;i<n;i++){
        printf("%d %d %d\n",points[i][0],points[i][1],points[i][2]);
    }
    for (int i = 0; i < n; i++) {
        lli fwd = sum(bit, points[i][1]);
        inc2(bit, points[i][1], 1);
        ans -= fwd * back[points[i][2]];
    }

    out64(ans);
    for (int i = 0; i < n; i++)
        free(points[i]);
    free(points);
    free(arr_x);
    free(arr_y);
    free(bit);
    return 0;
}
