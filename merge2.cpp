#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    ;
    int temp[r - l + 1];
    int k = 0;

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= m)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }

    for (int x = 0; x < k; x++)
    {
        a[l + x] = temp[x];
    }
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int a[] = {2, 15, 6, 7, 56, 76, 9};
    int n = sizeof(a) / sizeof(a[0]);
    mergesort(a, 0, n - 1);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}