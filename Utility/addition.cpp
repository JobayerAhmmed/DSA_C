// add 1000 digits number

#include<stdio.h>
#include<string.h>

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

int main()
{
    int n = 1000;
    char* a = new char[n + 1];
    char* b = new char[n + 1];
    char* c = new char[n + 2];

    scanf("%s %s", a, b);

    add(a, b, c);

    printf("%s + %s = %s\n", a, b, c);

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
