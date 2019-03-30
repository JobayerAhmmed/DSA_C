#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

bool isprime(unsigned long long n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    unsigned long long limit = (unsigned long long) sqrt(n);
    for (unsigned long long i = 3; i <= limit; i = i + 2)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> primefactors(int n)
{
    vector<int> factors;

    for (int i = 1; i <= n; i++) {
        if (n%i == 0 && isprime(i)) {
            factors.push_back(i);
            n = n / i;
            i = 1;
        }
    }

    return factors;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> p = primefactors(n);
    for (int i = 0; i < p.size(); i++)
        printf("%d ", p[i]);
    printf("\n");

    return 0;
}
