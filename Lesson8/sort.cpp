#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


void QuickSort(int num[],int low,int hi){
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
    QuickSort(num,low,pivot-1);
    QuickSort(num,pivot+1,hi);
    return ;
}

void savedata(const char * filnm,int data[],int n){
    FILE * fp;
    if((fp = fopen(filnm,"wb"))==NULL){
      printf("cant open the file");
      exit(0);
    }

    for(int i=0;i<n;i++){
      fprintf(fp,"%d ",data[i]);
      if((i+1)%7==0) fprintf(fp,"\n");
    }
    
    fclose(fp);
    return ;
}

int is_sorted(int a[], int n){
    for(int i=0 ;i<n-1; i++){
        if(a[i]>a[a+1]){
            return 0
        }
    }
    return 1
}

int main()
{
    int n, c = pow(2,30);
    int *num = new int[c];
    
    scanf("%d",&n);

    for(int i=0;i<n;i++)
      scanf("%d",&num[i]);

    savedata("./data.txt",num,n);
    QuickSort(num,0,n-1);

    int verifymark = is_sorted(num,n);
    if(verifymark == 0){
        printf("not sorted.\n")
    }
    else{
        printf("sorted successfully.\n");
        savedata("./sort.txt",num,n);
    }

    return 0;  
}

