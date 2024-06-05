// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int s1=m-l+1;
    int s2=r-m;
    int left[s1], right[s2];
    for(int i = 0; i<s1; i++){
        left[i] = arr[l+i];
    }
    for(int j=0; j<s2; j++){
        right[j] = arr[m+j+1];
    }
    int i=0, j=0, k=l;
    while(i<s1 && j<s2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    
    while(i<s1){
        arr[k++] = left[i++];
    }
    while(j<s2){
        arr[k++] = right[j++];
    }
}

void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[7] = {38, 23, 44, 56, 35, 61, 40};
    mergesort(arr, 0, 6);
    for(int i:arr) cout << i << " ";

    return 0;
}
