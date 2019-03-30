// average case: O(n log n)
// worst case: O(n^2)
// not stable sort

#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct {
    int key;
    int value;
} Node;

typedef struct {
    int day;
    int month;
    int year;
    char *name;
} Birthday;

int parti(int* data, int left, int right)
{
    int pivot = data[left + (right-left)/2];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while(data[i] < pivot);

        do {
            j--;
        } while(data[j] > pivot);

        if(i >= j)
            return j;

        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

void quicksort(int* data, int left, int right)
{
    if(left < right) {
        int p = parti(data, left, right);
        quicksort(data, left, p);
        quicksort(data, p+1, right);
    }
}

int compareint(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void intsort()
{
    int data[] = {5, 50, 15, 25, 55, 35, 40};
    int n = sizeof(data) / sizeof(data[0]);

    qsort(data, n, sizeof(data[0]), compareint);

    for(int i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");
}

int comparefloat(const void *a, const void *b)
{
    if( *(float*)a < *(float*)b )
        return -1;
    if( *(float*)a > *(float*)b )
        return 1;
    return 0;
}

void floatsort()
{
    float data[] = {5, 50.05, 50.04, 50.06, 55, 35, 40};
    int n = sizeof(data) / sizeof(data[0]);

    qsort(data, n, sizeof(data[0]), comparefloat);

    for(int i = 0; i < n; i++)
        printf("%f ", data[i]);
    printf("\n");
}

int comparechar(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

void charsort()
{
    int data[] = { 'p', 'x', 'q', 'b', 'm' };
    int n = sizeof(data) / sizeof(data[0]);

    qsort(data, n, sizeof(data[0]), comparechar);

    for(int i = 0; i < n; i++)
        printf("%c ", data[i]);
    printf("\n");
}

int comparestring(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

void stringsort()
{
    char data[][20] = {
        "Dhaka Bangladesh",
        "Delhi India",
        "DC USA",
        "London UK"
    };

    int n = sizeof(data) / sizeof(data[0]);
    qsort(data, n, sizeof(data[0]), comparestring);

    for(int i = 0; i < n; i++)
        printf("%s\n", data[i]);
    printf("\n");
}

int comparerecord(const void *a, const void *b)
{
    Node *x = (Node*) a;
    Node *y = (Node*) b;
    return x->key - y->key;
}

void recordsort()
{
    Node data[] = {
        {5, 50},
        {10, 100},
        {20, 200},
        {2, 20},
        {4, 40}
    };

    int n = sizeof(data) / sizeof(data[0]);
    qsort(data, n, sizeof(data[0]), comparerecord);

    for(int i = 0; i < n; i++)
        printf("%d %d\n", data[i].key, data[i].value);
    printf("\n");
}

int comparebirthday(const void *a, const void *b)
{
    Birthday *x = (Birthday*)a;
    Birthday *y = (Birthday*)b;

    if (x->month != y->month)
        return x->month - y->month;

    if(x->day != y->day)
        return x->day - y->day;

    return x->year - y->year;
}

void multifieldsort()
{
    Birthday data[] = {
        { 5, 6, 1991, "Jobayer" },
        { 12, 12, 2000, "Jayed" },
        { 12, 12, 1999, "Junayed" },
        { 10, 12, 2001, "Shoshi" },
        { 1, 1, 2001, "Nafisa" }
    };

    int n = sizeof(data) / sizeof(data[0]);
    qsort(data, n, sizeof(data[0]), comparebirthday);

    for(int i = 0; i < n; i++)
        printf("%d-%d-%d-%s\n", data[i].day, data[i].month, data[i].year, data[i].name);
    printf("\n");
}

int main()
{
    int data[] = {5, 50, 15, 25, 55, 35};
    int n = sizeof(data) / sizeof(data[0]);

    quicksort(data, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");

    intsort();
    floatsort();
    charsort();
    stringsort();
    recordsort();
    multifieldsort();

    return 0;
}
