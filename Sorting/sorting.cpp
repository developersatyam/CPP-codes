#include <bits/stdc++.h> 
using namespace std;
class Sorting{
    int i,j, temp;
    public:
    void swap(int *a, int *b){
        temp=*a;
        *a=*b;
        *b=temp;
    }
    int* BubbleSort(int arr[], int l){
        for(i=0;i<l-1;i++)
            for(j=0;j<l-i-1;j++)
                if(arr[j]>arr[j+1])
                   swap(&arr[j], &arr[j+1]);
        return arr;
    }
    int* SelectionSort(int arr[], int l){
            
        return arr;
    }
    int* MergeSort(int arr[], int l){

        return arr;
    }
    int* InsertionSort(int arr[], int l){

        return arr;
    }
    void printFn(int arr[], int l){
        for(i=0;i<l;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    cout<<endl<<"---------Sorting algorithms----------"<<endl;
    int arr[]={10, 44, 2, 27, 100, 67, 88, 32};
    int l=sizeof(arr)/sizeof(arr[0]);
    Sorting sort;
    int* sortArr;
    cout<<endl<<"Normal Array -> ->"<<endl;
    sort.printFn(arr, l);
    cout<<endl<<"Bubble Sorting -> ->"<<endl;
    sortArr=sort.BubbleSort(arr, l);
    sort.printFn(sortArr, l);
    cout<<endl<<"Selection Sorting -> ->"<<endl;
    sortArr=sort.BubbleSort(arr, l);
    sort.printFn(sortArr, l);
    cout<<endl<<"Merge Sorting -> ->"<<endl;
    sortArr=sort.BubbleSort(arr, l);
    sort.printFn(sortArr, l);
    cout<<endl<<"Insertion Sorting -> ->"<<endl;
    sortArr=sort.BubbleSort(arr, l);
    sort.printFn(sortArr, l);
    return 0;
}
