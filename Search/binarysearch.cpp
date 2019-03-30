#include<stdio.h>

int parti(int* data, int left, int right)
{
    int pivot = data[left + (right - left)/2];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while(data[i] < pivot);

        do {
            j--;
        } while(data[j] > pivot);

        if (i >= j)
            return j;

        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

void quicksort(int* data, int left, int right)
{
    if (left < right) {
        int p = parti(data, left, right);
        quicksort(data, left, p);
        quicksort(data, p + 1, right);
    }
}

int binarysearch(int* data, int left, int right, int item)
{
    while (left <= right) {
        int p = left + (right - left) / 2;

        if(data[p] < item)
            left = p + 1;
        else if(data[p] > item)
            right = p - 1;
        else
            return p;
    }

    return -1;
}

int main()
{
    int data[] = {20, 30, 40, 50, 80, 90, 100};
    int n = sizeof(data) / sizeof(data[0]);

    quicksort(data, 0, n-1);

    int searchItem = 50;
    int index = binarysearch(data, 0, n-1, searchItem);

    printf("Index of %d = %d\n", searchItem, index);

    return 0;
}
