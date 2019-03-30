#include<stdio.h>

// unsigned long long = 18,446,744,073,709,551,616
// long long = 9,223,372,036,854,775,808

unsigned long long factorial(int n)
{
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int n;

    scanf("%d", &n);
    unsigned long long f = factorial(n);

    printf("%d! = %llu", n, f);

    return 0;
}
