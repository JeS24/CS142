#include <iostream>
using namespace std;

long count = 0;  // ****REM

void printArray(long arr[]) { // ****REM
    cout << "\nPRINTING Array: \n";
    for (int i = 0 ; i < 4 ; i++)
        cout << arr[i] << " ";
}

void merge(long arr[], long l, long r, long m) {
    long i, j, k;
    long i1 = m - l + 1;
    long i2 = r - m;

    long L[i1], R[i2];

    for (i = 0 ; i < i1 ; i++)
        L[i] = arr[l+i];
    for (j = 0 ; j < i1 ; j++)
        R[j] = arr[m+1+j];

    // Comparing and putting in place (Merging)
    for (i = 0, j = 0, k = l ; i < i1 && j < i2 ; k++)
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

    for ( ; i < i1 ; i++, k++)
        arr[k] = L[i];

    for ( ; j < i2 ; j++, k++)
        arr[k] = R[j];
    cout << "\nINSIDE merge(): \n";
    printArray(arr);
}

void mergeSort(long arr[], long l, long r) {
    cout << "\nINSIDE mergeSort(): ";
    cout << "count = " << ++count << "\n"; // ****REM
    printArray(arr);
    long m = (l+r)/2;
    cout << "\nm = " << m << "\n";
    if (l < r) {
        mergeSort(arr, l, m);
        cout << "\nCONTROL CAME HERE, BEFORE mergeSort()\n";
        mergeSort(arr, m+1, r); // *
    cout << "\nCONTROL CAME HERE, BEFORE merge()\n";
    merge(arr, l, r, m); // BUT WHY SHOULD CONTROL COME/FALL HERE, INSTEAD OF THERE(*)??
    }
    cout << "\nCONTROL CAME HERE, AT THE END OF mergeSort()\n";
    // }
}

// Driver program to check the code, above
int main()
{
    long arr[] = {2342, 5, 1212, 2341}; // 34, 12, 0, 123, 13, 12, 19, 22, 1, 3};
    cout << "\nOriginal Array: \n";
    printArray(arr);
    mergeSort(arr, 0, 4);
    cout << "\nSorted array: \n";
    printArray(arr);
    cout << "\n\n";
}
