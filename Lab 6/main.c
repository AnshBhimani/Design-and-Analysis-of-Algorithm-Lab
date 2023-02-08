//merdge sort in recuurance 

#include <stdio.h>

void merge_sort(int a[],int p,int r)
{

    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

void merge(int a[],int p, int q, int r)
{
   int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    int i,j,k;
        L[n1]=9999;
    R[n2]=9999;
    i=0;
    j=0;
    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[q+j+1];
    }

    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
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