#include<iostream>
using namespace std;
void quickSort(int arr[], int size, int start, int end){
    // base case
    if(start >= end) return;
    int pivot = end;
    int i=start-1;
    int j=start;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }j++;
    }i++;
    swap(arr[i], arr[j]);
    quickSort(arr, size, start, i-1);
    quickSort(arr, size, i+1, end);
}

int main(){

    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    int size = 8;

    cout << "Before : " << endl;
    for(auto i: arr){
        cout << i << " ";
    }cout << endl;
    quickSort(arr, size, 0, size-1);
    cout << "After : " << endl;
    for(auto i: arr){
        cout << i << " ";
    }

    return 0;
}