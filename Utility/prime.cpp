#include<stdio.h>
#include<math.h>

// prime number starts from 2
bool isprime(unsigned long long n)
{
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    unsigned long long limit = (unsigned long long) sqrt(n);

    for (unsigned long long i = 3; i <= limit; i = i + 2)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    unsigned long long n;

    scanf("%llu", &n);

    if (isprime(n))
        printf("%llu is prime\n", n);
    else
        printf("%llu is not prime\n", n);

    return 0;
}
