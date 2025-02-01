#include <iostream>
#include <vector>
using namespace std;

// void mergeArray(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans)
// {
//     int i = 0, j = 0;
//     while (i < sizeArr && j < sizeBrr)
//     {
//         if (arr[i] < brr[j])
//         {
//             ans.push_back(arr[i]);
//             i++;
//         }
//         else
//         {
//             ans.push_back(brr[j]);
//             j++;
//         }
//     }
//     while (i < sizeArr)
//     {
//         ans.push_back(arr[i]);
//         i++;
//     }
//     while (j < sizeBrr)
//     {
//         ans.push_back(brr[j]);
//         j++;
//     }
// }

void merge(int arr[], int s, int e, int mid)
{
    // calculating left array size & right array size
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    // creating new left array & right array
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    int index = s;
    // copying into left array
    for (int i = 0; i < leftLength; i++)
    {
        leftArr[i] = arr[index];
        index++;
    }

    index = mid + 1;
    // copying into right array
    for (int i = 0; i < rightLength; i++)
    {
        rightArr[i] = arr[index];
        index++;
    }

    // merge logic
    int i = 0;
    int j = 0;
    int mainArrayIndex = s;
    while (i < leftLength && j < rightLength)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[mainArrayIndex] = leftArr[i];
            i++;
            mainArrayIndex++;
        }
        else
        {
            arr[mainArrayIndex] = rightArr[j];
            j++;
            mainArrayIndex++;
        }
    }
    
    // handling 2 case if any of two array is shorter than other
    while(i < leftLength){
        arr[mainArrayIndex] = leftArr[i];
        i++;
        mainArrayIndex++;
    }
    while(j < rightLength){
        arr[mainArrayIndex] = rightArr[j];
        j++;
        mainArrayIndex++;
    }

    // freeing up heap memory
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    // left part Recursion se solve karwao
    mergeSort(arr, s, mid);
    // right part Recursion se solve karwao
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}

int main()
{
    int arr[] = {10, 90, 100, 50, 60, 20, 40, 30, 80, 70};
    int size = 10;
    int s = 0;
    int e = size - 1;

    cout << "Before : "  << endl;
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;

    mergeSort(arr, s, e);
    
    cout << "After : "  << endl;
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    // int arr[] = {1, 2, 3, 4, 5};
    // int sizeArr = 5;
    // int brr[] = {6, 7, 8, 9, 10};
    // int sizeBrr = 5;
    // vector<int> ans;
    // mergeArray(arr, sizeArr, brr, sizeBrr, ans);
    // cout << "Printing ans : " << endl;
    // for (auto num : ans)
    // {
    //     cout << num << " ";
    // }

    return 0;
}