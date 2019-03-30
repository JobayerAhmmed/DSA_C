#include<stdio.h>
#include<math.h>

long gcd(long a, long b)
{
    if (a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}

void divbygcd(long& a, long& b)
{
    long g = gcd(a,b);
    a = a / g;
    b = b / g;
}

long nCr(int n, int r)
{
    long numerator = 1, denominator = 1, mul, div;

    if (r > n/2)
        r = n - r;

    for (long i = r; i; i--) {
        mul = n - r + i;
        div = i;
        divbygcd(mul, div);
        divbygcd(numerator, div);
        divbygcd(mul, denominator);
        numerator = numerator * mul;
        denominator = denominator * div;
    }

    return numerator / denominator;
}

int main()
{
    long n, r;

    scanf("%ld %ld", &n, &r);
    printf("C(%ld,%ld) = %ld\n", n, r, nCr(n,r));

    return 0;
}
