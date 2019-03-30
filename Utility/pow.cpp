#include<stdio.h>

long square(long n)
{
    return n * n;
}

long exp(long base, long power)
{
    if (power == 0)
        return 1;
    if (power % 2 == 0)
        return square(exp(base, power/2));
    return base * exp(base, power-1);
}

int main()
{
    long base, power;

    scanf("%ld %ld", &base, &power);
    long ex = exp(base, power);
    printf("%ld^%ld = %ld\n", base, power, ex);

    return 0;
}
