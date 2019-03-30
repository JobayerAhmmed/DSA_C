#include<stdio.h>

long gcd(long a, long b)
{
    while (b > 0) {
        a = a % b;
        a = a^b;
        b = b^a;
        a = a^b;
    }
    return a;
}

int main()
{
    int n, a, b, g, i;

    while(scanf("%ld", &n) == 1) {
        scanf("%ld%ld", &a, &b);
        i = 2;
        while (i < n) {
            g = gcd(a,b);
            a = g;
            i++;
            scanf("%ld", &b);
        }
        g = gcd(a,b);
        printf("GCD = %ld\n", g);
    }

    return 0;
}
