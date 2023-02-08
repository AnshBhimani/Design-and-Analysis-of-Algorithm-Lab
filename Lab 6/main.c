//merdge sort in recuurance 

#include <stdio.h>

void merge_sort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,c[50];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        c[k]=a[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=c[i];
    }
}


int main()
{
    int a[10],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}