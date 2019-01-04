#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
using namespace std;

int n;
int c =pow(2,30);
int *num = new int[c];
clock_t starttime,endtime;

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

void savedata(const char * filnm,int data[]){
    FILE * fp;
    if((fp = fopen(filnm,"wb"))==NULL){
      printf("cant open the file");
      exit(0);
    }
    //fwrite(data,sizeof(int),n,pf);
    int i;
    for(i=0;i<n;i++){
      fprintf(fp,"%d ",data[i]);
      if((i+1)%7==0){
        fprintf(fp,"\n");
      }
    }
    fclose(fp);
    return ;
}

int main()
{
    scanf("%d",&n);
    int i;

    for(i=0;i<n;i++)
      scanf("%d",&num[i]);

    savedata("./data.txt",num);
    starttime = clock();
    QuickSort(0,n-1);
    endtime = clock();
    savedata("./sort.txt",num);
    double sorttime = (double)(endtime - starttime)/CLOCKS_PER_SEC;
    printf("sort time:%f s",sorttime);

    return 0;
    
}

