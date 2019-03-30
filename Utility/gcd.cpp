#include<stdio.h>

long gcd(long a, long b)
{
    while (b > 0) {
        a = a % b;
        a ^= b; // exclusive OR
        b ^= a;
        a ^= b;
    }
    return a;
}

long gcdrecursive(long a, long b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

long lcm(long a, long b)
{
    return a * (b / gcd(a, b));
}

int main()
{
    long a, b;

    scanf("%ld %ld", &a, &b);

    printf("GCD(%ld,%ld) = %ld\n", a, b, gcd(a,b));
    printf("GCD(%ld,%ld) = %ld\n", a, b, gcdrecursive(a,b));
    printf("LCM(%d,%d) = %d\n", a, b, lcm(a,b));

    return 0;
}
