#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

 int n;
 int num[10];

void Merge(int low, int mid, int hi){
    int tmp[10];
    int i,j,t;
    for(i=low;i<=mid;i++)
        tmp[i-low]=num[i];
    for(t=low,i=0,j=mid+1;t<=hi && i<=mid-low && j<=hi;t++){
        if(tmp[i]<num[j]) {num[t]=tmp[i]; i++;}
        else {num[t]=num[j]; j++;}
    }
    if(t<=hi){
            for(;i<=mid-low;i++,t++)
               num[t]=tmp[i];
            for(;j<=hi;j++,t++)
                num[t]=num[j];
    }
    return ;
}
void MergeSort(int low, int hi){
    if(hi-low<1) return;
    int mid=(low+hi)/2;
    MergeSort(low,mid);
    MergeSort(mid+1,hi);
    Merge(low, mid, hi);
    return ;
}
int Find(int low, int high, int x){
      if(x>=num[high]) return high+1;
      if(x<num[low]) return low;
      int mid=(low+high)>>1;
      if(x>=mid) return Find(mid+1,high,x);
      else return Find(low,mid,x);
}

void InsertSort(){
    int i,j,t,tmp;
    for(i=1;i<n;i++){
       j=Find(0,i-1,num[i]);
       tmp=num[i];
       for(t=i-1;t>=j;t--)
        num[t+1]=num[t];
       num[j]=tmp;
    }
    return ;
}

void BubbleSort(){
     int i,j;
     bool mark;
     for(i=1;i<n;i++){
            mark=true;
        for(j=1;j<=n-i;j++){
            if(num[j]<num[j-1]){
                swap(num[j],num[j-1]);
                mark=false;
            }
        }
           if(mark==true) break;
     }

     return ;
}

void SelectSort(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(num[j]<num[i]) swap(num[j],num[i]);
        }
    }
}

void QuickSort(int low,int hi){
    if(hi-low<1) return ;
    int pivot=low,j=hi,x=num[low];
    int stand=num[low];
    while(pivot<j){
        while(pivot<j && num[j]>x) j--;
        if(pivot<j) num[pivot++]=num[j];
        while(pivot<j && num[pivot]<x) pivot++;
        if(pivot<j) num[j--]=num[pivot];
    }
    num[pivot]=x;
    QuickSort(low,pivot-1);
    QuickSort(pivot+1,hi);
    return ;
}

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);

    //InsertSort();
    //BubbleSort();
    //SelectSort();
   // MergeSort(0,n-1);
    QuickSort(0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
    printf("\n");
    return 0;
}

