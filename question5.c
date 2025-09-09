#include <stdio.h>

void solve(int n, int *a, int *result) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            int start = (i - a[i] + 1) > 0 ? (i - a[i] + 1) : 0;
            for (int j = start; j <= i; ++j) {
                result[j] = 1;
            }
        }
    }
}


int main() {
    int t;
    scanf("%d", &t);
    while (t!=0) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        
        int result[n];
        for (int i = 0; i < n; i++) {
            result[i] = 0;
        }
        solve(n, a, result);
        for (int i = 0; i < n; ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
        t--;

    }
    return 0;
}
