#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void heap(int nums[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int large=i;
    if(left<n &&nums[left]>nums[large]){
        large=left;
    }
    if(right<n && nums[right]>nums[large]){
        large=right;
    }
    if(i!=large){
      swap(&nums[i],&nums[large]);
      heap(nums,large,n);
    }
      
}

void heapsort(int nums[],int n){
    int i;
    for(i=n/2-1;i>=0;i--)
        heap(nums,i,n);
    
    for(i=n-1;i>0;i--)
    {
        swap(&nums[0],&nums[i]) ; 
           n--;  
            heap(nums,0,i);    
}
}
int main()
{  
    int a[]={9,4,5,78,3,7,0,1};
    
    heapsort(a,8);
    
    for(int i=0;i<8;i++)
    printf("%d ",a[i]);
   
    return 0;
}