#include<conio.h>
#include<stdio.h>
#include<time.h>

void merge( int a[],int low,int mid,int high ){
    int i, j, k, b[20];
    i = low, j = mid + 1, k = low;
    while(i <=mid && j<= high){
        if(a[i]<=a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    while(i<=mid)
        b[k++] = a[i++];
    while(j<=high)
        b[k++] = a[j++];

    for (k = low; k <= high; k++){
        a[k] = b[k];
    }
}

void mergeSort(int a[], int low, int high){
    int mid; 
    if(low>=high)
        return;

    mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

void main(){
    int n, a[2000], k;
    clock_t st, et;
    double ts;
    // clrscr();
    printf("\n Enter number of elements: ");
    scanf("%d", &n);
    printf("\n The Random Numbers are: ");
    for (k = 1; k <= n;k++){
        a[k] = rand();
        printf("%d\n", a[k]);
    }

    st = clock();
    mergeSort(a, 1, n);
    et = clock();
    ts = (double)(et - st) / CLOCKS_PER_SEC;

    printf("sortednumbersw are : \n");
    for (k = 1; k <= n; k++)
    {
        printf("%d\n", a[k]);
    }
    printf("timr taken is: %e", ts);

}