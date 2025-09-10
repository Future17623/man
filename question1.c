#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

char* addStrings(const char* num1, int len1, const char* num2, int len2, char* result)  {
    
    int k = 0; // 暂时计算结果
    int n = 0;

    // 竖式计算
    for ( int i = len1 - 1, j = len2 - 1;     i >= 0 || j >= 0 || k > 0;     i--, j--, k /= 10) {
        if (i >= 0) k += num1[i] - '0';
        if (j >= 0) k += num2[j] - '0';
        result[n++] = k % 10 + '0'; // 计算低位在前结果
    }
    result[n] = '\0'; // 结束符

    // 反转
    for (int m = 0; m < n / 2; m++) {
        char tmp = result[m];
        result[m] = result[n - 1 - m];
        result[n - 1 - m] = tmp;
    }

    return result; 
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char num1[MAX_LEN], num2[MAX_LEN];
    
    scanf("%s %s", num1, num2);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char result[max(len1, len2) + 2]; // 结果数组
    
    char* sum = addStrings(num1, len1, num2, len2, result);

    printf("%s", sum);
    return 0;
}
