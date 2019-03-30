#include<stdio.h>
#include<string.h>

void substr(char* str, char* sub, int start, int len) {
    memcpy(sub, &str[start], len);
    sub[len] = '\0';
}

int main() {
    char str[] = "Mango People";
    char sub[6];

    substr(str, sub, 3, 5);

    puts(sub);

    return 0;
}
