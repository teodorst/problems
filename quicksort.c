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
    int v[10] = { 1, 5, 6, 2, 9, 7, 23, 12, 33, 10 };
    quicksort(v, 0, 9);
    int i;
    
    for( i = 0 ; i < 10; i ++ ) 
        printf("%d ", v[i]);

    printf("\n");

    return 0;
}