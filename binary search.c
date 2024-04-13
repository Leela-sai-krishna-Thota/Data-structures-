/* Binary search using recursive function */
#include<stdio.h>
int binarysearch(int, int);
int a[20], key;
int main() {
    int i, n, pos;
    printf("enter n:");
    scanf("%d",&n);
    printf("enter n elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("enter key:");
    scanf("%d",&key);
    pos = binarysearch(0, n-1);
    if(pos==-1)
        printf("search unsuccessful");
    else
        printf("Key is found at the index:%d",pos);
    return 0;
}
int binarysearch (int low, int high)
{
    int mid;
    if(low>high) 
        return(-1);
    mid=(low+high)/2;
    if(key==a[mid]) 
        return(mid);
    else if(key<a[mid]) 
        return(bsearch(low,mid-1));
    else 
        return(bsearch(mid+1,high));
}