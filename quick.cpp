#include<iostream>
using namespace std;

int partition(int nums[], int l, int r){
    int i=l+1;
    int j=r;
    int pivot=nums[l];
    int temp;

    do{
        while(nums[i]<=pivot&&nums[i]<=r){
            i++;
        }
        while(nums[j] > pivot){
            j--;
        }
        if(i<j){
        temp=nums[i];
        nums[i] = nums[j];
        nums[j]=temp;
        }
    }while(i<j);

    temp=nums[l];
    nums[l]=nums[j];
    nums[j]=temp;

    return j;
}
void quick(int nums[], int l, int r){
    if(l<r){
        int p=partition(nums,l,r);
        quick(nums,l,p-1);
        quick(nums,p+1,r);
    }
}

int mnumsin(){
    int nums[]={2,3,56,1,65};
    int n=5;
    quick(nums,0,n-1);
    cout<<"Sorted array"<<endl;
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
