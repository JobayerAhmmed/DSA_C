// wrong answer

#include<stdio.h>
#include<math.h>

long square(long x)
{
    return x * x;
}

long bigmod(long b, long p, long m)
{
    if (p == 0)
        return 1;
    else if (p % 2 == 0)
        return square(bigmod(b,p/2,m)) % m;
    else
        return ((b % m) * bigmod(b,p-1,m)) % m;
}

void twofactor(long n)
{
    long x = 1, y = n;
    long a = 2, b = n;

    while (a < b) {
        if (n%a == 0) {
            b = n/a;
            x = a;
            y = b;
        }
        a++;
    }
    printf("%ld = %ld * %ld\n", n, x, y);
}

int main()
{
    long n, m;

    scanf("%ld %ld", &n, &m);

    // calculate two factors
    long x = 1, y = n;
    long a = 2, b = n;
    while (a < b) {
        if (n%a == 0) {
            b = n/a;
            x = a;
            y = b;
        }
        a++;
    }

    long remainder = bigmod(x, y, m);
    printf("%ld  %ld = %ld\n", n, m, remainder);

    //twofactor(a);

    return 0;
}
