#include <stdio.h>
#include <stdlib.h>

typedef struct number {
    char *numar;
    int dimensiune;
} Number;


Number inmultireCifra( Number number, char cifra, int startIndex ) {
    int i;
    Number rezultat;// = (Number*) malloc(sizeof(Number));
    char* newNumber = (char*) malloc(200);
    int carryIn = 0;
    int currentNumber;
    int index;
    
    for( i = 0; i < number.dimensiune; i ++ ) {
        index = startIndex + i;
        currentNumber = number.numar[i] * cifra + carryIn; 
        newNumber[index] = currentNumber % 10;
        carryIn = (currentNumber - newNumber[index]) / 10;
    }

    if( carryIn > 0 ) {
        newNumber[startIndex + i] += carryIn;    
        rezultat.numar = newNumber;
        rezultat.dimensiune = i + 1 + startIndex;
    }
    else {
        rezultat.numar = newNumber;
        rezultat.dimensiune = i + startIndex;
    }
    
    return rezultat;
}



Number adunareNumere ( Number numar1, Number numar2 ) {
    Number rezultat; // = (Number*) malloc(sizeof(Number));

    char* newNumber = (char*) malloc(200);
    int carryIn = 0;
    int i;
    int numar;
    for( i = 0; i < numar1.dimensiune || i < numar2.dimensiune; i ++ ) {
        numar = numar1.numar[i] + numar2.numar[i] + carryIn;
        newNumber[i] = numar % 10;
        carryIn = (numar - newNumber[i]) / 10;
    }
    if( carryIn > 0 ) {
        newNumber[i] += carryIn;    
        rezultat.numar = newNumber;
        rezultat.dimensiune = i + 1;
    }
    else {
        rezultat.numar = newNumber;
        rezultat.dimensiune = i;
    }

    return rezultat;
}


Number inmultireNumbers( Number numar1, int numar2 ) {
    Number rezultat; // = (Number*) malloc(sizeof(Number));
    rezultat.numar = (char*) malloc(200);
    rezultat.dimensiune = 0;
    int startIndex = 0;
    int i;
    Number aux;
    Number auxRezultat;
    while( numar2 > 0 ) {
        aux = inmultireCifra( numar1, numar2 % 10, startIndex );
        rezultat = adunareNumere(rezultat, aux);

        numar2 /= 10;
        startIndex ++;
    }
    return rezultat;
}


int main () {
    int n, i, maxNforNumber;
    int dimensiune = 0;
    unsigned long long int semiFactorial = 1;
    Number factorial;// = (Number*) malloc(sizeof(Number));

    factorial.numar = (char*) malloc(200);
    factorial.dimensiune = 0;
    maxNforNumber = 20;

    scanf("%d", &n);

    if ( n <= 20 ) {
        maxNforNumber = n;
    }
    else 
        maxNforNumber = 20;

    for( i = 2; i <= maxNforNumber; i ++ )
        semiFactorial *= i;

    while( semiFactorial > 0 ) {
        factorial.numar[factorial.dimensiune] = semiFactorial % 10;
        factorial.dimensiune ++;
        semiFactorial /= 10;
    }

    for( i = maxNforNumber + 1; i <= n; i ++ ) {
         factorial = inmultireNumbers(factorial, i);
    }

    for( i = factorial.dimensiune - 1; i >= 0; i -- )
        printf("%d", factorial.numar[i] );
    printf("\n");

    return 0;
}