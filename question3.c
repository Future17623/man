#include <stdio.h>
#define MOD 1000000007
long long calculate_beautiful(int n) {
    if (n == 1) {
        return 2;
    }
    if (n == 2) {
        return 4;
    }
    
    //f(n) = f(n-1) + f(n-2)
    long long a = 2; 
    long long b = 4;  
    long long result = 0;
    
    for (int i = 3; i <= n; i++) {
        result = (  a + b ) % MOD;  
        a = b%MOD;          
        b = result%MOD;   
    }
    return result;
}

long long power(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = (2*result)% MOD;
    }
    return result;
}


int main() {
    int n;
    scanf("%d", &n);
    
    long long beautiful = calculate_beautiful(n);
    long long total = power(n);
    printf("%d", (total - beautiful + MOD) % MOD);
    return 0;
}

