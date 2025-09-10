#include <stdio.h>
#include <string.h>
#define MAX 10000

int compress(char* chars, int size) {
    int write = 0, read = 0;
    while (read < size) {
        char ch = chars[read];
        int count = 0;
        
        // 统计相同字符数量
        while (read < size && chars[read] == ch) {
            read++;
            count++;
        }
        
        // 写入当前字符
        chars[write++] = ch;
        
        // 当计数大于1取模方式处理
        if (count > 1) {

            char a[12];
            int len = 0;
            while (count > 0) {
                a[len++] = (count % 10) + '0';  // 数字最后一位转字符
                count /= 10;                    
            }
            
            // 恢复正确顺序
            for (int i = len - 1; i >= 0; i--) {
                chars[write++] = a[i];
            }
        }
    }
    return write;
}

int main() {
    char chars[MAX];
    scanf("%s", chars);
    int n = strlen(chars);

    int newLen = compress(chars, n);
    printf("%d\n", newLen);
    
    for (int i = 0; i < newLen; i++) {
        printf("%c ", chars[i]);
    }
    return 0;
}