#include<stdio.h>
#include<math.h>

void sieve(int L, int U)
{
    int i, j;
    int d = U - L + 1;
    bool *flag = new bool[d];

    // mark all to be true
    for (i = 0; i < d; i++)
        flag[i] = true;

    // set even numbers to false
    for (i = (L%2 != 0); i < d; i += 2)
        flag[i] = false;

    int limit = sqrt(U);
    for (i = 3; i <= limit; i += 2) {
        if (i > L && !flag[i-L])
            continue;

        j = L / i * i;
        if (j < L)
            j = j + i;

        if (j == i)
            j = j + i;

        j = j - L;
        for (; j < d; j += i)
            flag[j] = false;
    }

    if (L <= 1)
        flag[1-L] = false;
    if (L <= 2)
        flag[2-L] = true;

    for (i = 0; i < d; i++)
        if (flag[i])
            printf("%d ", L+i);
    printf("\n");
}

int main()
{
    int lower, upper;

    scanf("%d%d", &lower, &upper);
    sieve(lower, upper);

    return 0;
}
