#include<stdio.h>
#include<string.h>

// O(log n)
// using matrix property
unsigned long long fibonacci(int n)
{
    unsigned long long h, i, j, k, t;
    h = i = 1;
    j = k = 0;
    while (n > 0) {
        if (n%2 == 1) {
            t = h*j;
            j = h*i + j*k + t;
            i = i*k + t;
        }
        t = h*h;
        h = 2*h*k + t;
        k = k*k + t;
        n = (int) n/2;
    }
    return j;
}

void add(char* a, char* b, char* c)
{
    int an = strlen(a);
    int bn = strlen(b);

    int r = (an < bn) ? an : bn;
    int i = an - 1;
    int j = bn - 1;
    int k = 0;
    int sum, carry;

    // add common size of digits
    carry = 0;
    for (int p = 0; p < r; p++) {
        sum = (a[i] - '0') + (b[j] - '0') + carry;
        carry = sum / 10;
        c[k] = (sum % 10) + '0';
        i--;
        j--;
        k++;
    }

    // add remaining digits if any
    while(i >= 0) {
        sum = (a[i] - '0') + carry;
        carry = sum / 10;
        c[k] = (sum % 10) + '0';
        i--;
        k++;
    }

    // add remaining digits if any
    while(j >= 0) {
        sum = (b[j] - '0') + carry;
        carry = sum / 10;
        c[k] = (sum % 10) + '0';
        j--;
        k++;
    }

    // add remaining carry if has
    if (carry > 0) {
        c[k] = carry + '0';
        k++;
    }
    c[k] = '\0';

    // reverse output
    int cn = strlen(c);
    char temp;
    for(int p = 0; p < cn/2; p++) {
        temp = c[p];
        c[p] = c[cn-p-1];
        c[cn-p-1] = temp;
    }
}

void fibonacciseries(int n)
{
    char* f0 = new char[10000];
    char* f1 = new char[10000];
    char* f2 = new char[10000];

    f0[0] = '0';
    f0[1] = '\0';
    f1[0] = '1';
    f1[1] = '\0';
    printf("%s\n%s\n", f0, f1);

    for (int i = 3; i <= n; i++) {
        add(f0, f1, f2);
        printf("%s\n", f2);
        strcpy(f0, f1);
        strcpy(f1, f2);
    }

    delete[] f0;
    delete[] f1;
    delete[] f2;
}

void fibonaccinth(int n, char* f2)
{
    char* f0 = new char[10000];
    char* f1 = new char[10000];

    f0[0] = '0';
    f0[1] = '\0';
    f1[0] = '1';
    f1[1] = '\0';

    for (int i = 3; i <= n; i++) {
        add(f0, f1, f2);
        strcpy(f0, f1);
        strcpy(f1, f2);
    }

    delete[] f0;
    delete[] f1;
}

int main()
{
    int n;

    scanf("%d", &n);

//    fibonacciseries(n);

    char* fn = new char[10000];
    fibonaccinth(n, fn);
    printf("%s\n", fn);
    delete[] fn;

    return 0;
}
