#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Array {
    int *A;
    int size;
    int length;
};
void Append(struct Array* arr, int x) {
    if (arr->size > arr->length) {
        arr->A[arr->length++] = x;
    }
}
void Insert(struct Array* arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Array* arr, int index) {
    int x = 0;
    if (index >= 0 && index <= arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
void itemSwap(int *x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;

}
int LinearSearch(struct Array *arr, int key) {
    
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            // using Transposition: I used If else statement to avoid exception when I search for the second element 2 times because index of '0-1' not found in the array
            /*if (i == 0) {
                return i;
            }
            else {
                itemSwap(&arr->A[i], &arr->A[i - 1]);
                return i;
            }*/
            // Front to head Method: we don't use If else statement because in the first time it exchanged the place, in the second time it will still 0 ,don't access '0-1' index,
            itemSwap(&arr->A[0], &arr->A[i]);
            return i;
        }
    }
    return -1;
}


int BinSearch(struct Array arr,int key) {
    int l = 0;
    int h = arr.length-1;
    int m = (l + h) / 2;

    while (h >= l) {
        m = (l + h) / 2;
        if (key == arr.A[m])
            return m;
        else if (key > arr.A[m]) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    return -1;
}
int RBinSearch(int arr[], int l, int h, int key) {
    int mid;
    if (h >= l) {
        mid = (l + h) / 2;
        if (key == arr[mid])
            return mid;
        else if (key > arr[mid])
            return RBinSearch(arr, mid + 1, h, key);
        else
            return RBinSearch(arr, l, mid - 1, key);
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;

}


int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) {
    int total = 0;
    for (int i = 0; i < arr.length; i++) {
        total += arr.A[i];
    }
    return total;
}

float Avg(struct Array arr) {
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array* arr) {
    
    int *B = new int[arr->length];
    int i,j;
    // If I declare i , j in the for loop, it will give an error 
    for ( i = 0,  j = arr->length-1; j >= 0; i++, j--)
        B[i] = arr->A[j];

    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse2(struct Array* arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i<j; i++, j--)
        itemSwap(&arr->A[i], &arr->A[j]);
}
void ShiftOneItem(struct Array* arr) {
    int temp = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        arr->A[i - 1] = arr->A[i];
    }
    arr->A[arr->length - 1] = temp;
}

void ShiftNItems(struct Array* arr, int numOfShifts) {
    int count = 0;
    while (count<numOfShifts)
    {
        int temp = arr->A[0];
        for (int i = 1; i < arr->length; i++) {
            arr->A[i - 1] = arr->A[i];
        }
        arr->A[arr->length - 1] = temp;
        count++;
    }
    
}

void insertInSorted(struct Array*arr, int x) {
    if (arr->length == arr->size)
        return;

    int i = arr->length - 1;

    while (i>=0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int IsSorted(struct Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
        return 1;
}

void display(struct Array arr) {
    printf("\nElements are: \n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    cout << endl;
}

void Rearrange(struct Array* arr) {
    int i = 0, j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;

        if(i<j)
            itemSwap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2) {

    //I used pointers to create the array in the heap;

    struct Array *arr3 = new Array();
    arr3->size = 10;
    arr3->length = arr1->length + arr2->length;

    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k] = arr2->A[j];

    return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2) {

    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = new Array();
    
    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
    return arr3;

}

struct Array* Intersection(struct Array* arr1, struct Array* arr2) {

    struct Array* arr3 = new Array();
    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else if(arr1->A[i]<arr2->A[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2) {

    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = new Array();
    
    while (i < arr1->length && j < arr2->length) {

        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else {
            i++;
            j++;
        }
    }
    for (i; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}


int main() {

    struct Array arr;
    printf("Enter size of an array");
    cin >> arr.size;
    arr.A = new int[arr.size];
    
    // It is important to initialize length to 0, otherwise insert function will not start
    arr.length = 0;
    int ch;
    
    do {
        
        cout << "Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        int n, index;
        cin >> ch;
        switch (ch)
        {
        case 1: {
            cout << "Enter index and number\n";
            cin >> index >> n;
            Insert(&arr, index, n);
            break;
        }
        case 2:
        {
            cout << "Enter index to delete\n";
            cin >> index;
            Delete(&arr, index);
            break;
        }
        case 3:
        {
            cout << "Enter element to search for";
            cin >> n;
            index = LinearSearch(&arr, n);
            cout << index;
            break;
        }
        case 4:
            cout <<"Sum = "<< Sum(arr);
            break;
        case 5:
        {
            display(arr);
            break;
        }
        default:
            break;
        }
    } while (ch < 6);
    

    return 0;
}