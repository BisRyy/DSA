#include <iostream>

using namespace std;

void simpleSort(int arr[], int n)
{
    cout << endl
         << "Simple Sorting..." << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    cout << endl
         << "Insertion Sorting..." << endl;
    int x, y;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
            else
            {
                break;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    cout << endl
         << "Sorting..." << endl;
    int a;
    for (int i = 0; i < n; i++)
    {
        int x = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[x])
            {
                x = j;
            }
        }
        swap(arr[i], arr[x]);
    }

    cout << endl
         << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int linearsearch(int arr[], int n, int value)
{
    cout << endl
         << "Linear Searching..." << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            cout << "fount at: " << i << endl;
            return i;
        }
    }
    cout << "not found" << endl;
    return -1;
}

int binarysearch(int arr[], int n, int value)
{
    selectionSort(arr, n);
    cout << endl
         << "Binary Search" << endl;
    int first = 0, last = n, mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == value)
        {
            cout << "fount at: " << mid << endl;
            return mid;
        }
        else if (arr[mid] > value)
        {
            last = mid - 1;
        }
        else
            first = mid + 1;
    }
    cout << "not found" << endl;
    return -1;
}

void unsort(int *a1, int *a2, int n)
{
    for (int i = 0; i < n; i++)
    {
        a2[i] = a1[i];
    }
}

void showArray(int *arr, int n)
{
    cout << endl
         << "Here is the array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// int* getValues(int n){

//     int a[n];

//     for(int i=0; i<n; i++){
//         cout << "value for index " << i << ": ";
//         cin >> a[i];
//     }

//     return a;
// }

void menu()
{
    int list[100], unsorted[100];
    int count = 0;

    while (true)
    {

        cout << endl
             << "\tChoice:\n\n1.Enter Array\n2.Simple Sort\n3.Bubble Sort\n4.Insertion Sort\n5.Selection Sort\n6.Unsort Array\n7.Show Array\n0.Exit\n\n Enter Your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "How many elements? ";
            cin >> count;
            for (int i = 0; i < count; i++)
            {
                cout << "value for index " << i << ": ";
                cin >> list[i];
                unsorted[i] = list[i];
            }

            cout << endl
                 << "Array Added" << endl;
            showArray(list, count);
            break;
        case 2:
            simpleSort(list, count);
            cout << endl
                 << "Array Sorted" << endl;
            showArray(list, count);
            break;
        case 3:
            bubbleSort(list, count);
            cout << endl
                 << "Array Sorted" << endl;
            showArray(list, count);
            break;
        case 4:
            insertionSort(list, count);
            cout << endl
                 << "Array Sorted" << endl;
            showArray(list, count);
            break;
        case 5:
            selectionSort(list, count);
            showArray(list, count);
            break;
        case 6:
            unsort(unsorted, list, count);
            cout << endl
                 << "Array UnSorted" << endl;
            showArray(list, count);
            break;
        case 7:
            showArray(list, count);
            break;
        default:
            exit(0);
        }
    }
}

int main()
{

    // int n, value;
    // cout << "How many elements? ";
    // cin >> n;
    // int a[n];

    // for(int i=0; i<n; i++){
    //     cout << "value " << i+1 << ": ";
    //     cin >> a[i];
    // }

    // cout << endl << "search for what? ";
    // cin >> value;

    // int a[8] = {6,8,7,24,19,2,3,5};
    // int n = 8;

    // bubbleSort(a, n);

    // for(int i=0; i<n; i++){
    //     cout << endl<< a[i];
    // }

    menu();
    return 0;
}
