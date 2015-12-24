#include <stdio.h>
#include <stdlib.h>


int partition ( int *v, int left, int right ) {
    int i = left, j;
    int tmp;
    int pivot = v[ right ];
    int h;

    for( j = left; j < right; j ++ ) {
        if( v[j] < pivot ) {
            tmp = v[j];
            v[j] = v[i];
            v[i] = tmp;
            i ++;
        }
    }

    tmp = v[right];
    v[right] = v[i];
    v[i] = tmp;

    return i;
}

void quicksort( int *v, int left, int right ) {
    int index = partition(v, left, right);
    if( left < index - 1 ) {
        quicksort(v, left, index -1);
    }
    if( right > index ) {
        quicksort(v, index, right);
    }
}

int main () {
    
    int n, k, *v, i;
    scanf("%d%d", &n, &k);
    v = (int*) malloc( n * sizeof(int));
    
    for( i = 0; i < n; i ++ ) {
        scanf("%d", &v[i]);
    }
    
    quicksort(v, 0, n-1);
    
    int left, right, count = 0;

    left = 0; 
    right = 0;

    while( right < n ) {
        if( v[right] - v[left] == k ) {
            count ++;
            right ++;
            left ++;
        }
        else 
            if ( v[right] - v[left] > k ) {
                left ++;
            }
        else 
            right ++;
    }

    printf("%d\n", count);


    return 0;
}