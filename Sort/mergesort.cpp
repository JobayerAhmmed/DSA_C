// average case: O(n log n)
// worst case: O(n log n)
// stable sort

#include<stdio.h>

void merg(int* data, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int dataLeft[n1];
    int dataRight[n2];

    for(int i = 0; i < n1; i++)
        dataLeft[i] = data[left+i];

    for(int i = 0; i < n2; i++)
        dataRight[i] = data[middle+1+i];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if (dataLeft[i] <= dataRight[j]) {
            data[k] = dataLeft[i];
            i++;
        }
        else {
            data[k] = dataRight[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        data[k] = dataLeft[i];
        i++;
        k++;
    }

    while(j < n2) {
        data[k] = dataRight[j];
        j++;
        k++;
    }
}

void mergesort(int* data, int left, int right)
{
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergesort(data, left, middle);
        mergesort(data, middle + 1, right);
        merg(data, left, middle, right);
    }
}

int main()
{
    int data[] = {5, 50, 15, 25, 55, 35};
    int n = sizeof(data) / sizeof(data[0]);

    mergesort(data, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
}
