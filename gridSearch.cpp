#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n1, m1, n2, m2, i, j, k, l;
    char largeGrid[1000][1000], smallGrid[1000][1000] ;
    
    cin >> t;
    while ( t > 0 ) {
        cin >> n1 >> m1;
        
        for( i = 0; i < n1; i ++ ) {
            for ( j = 0; j < m1; j ++ ) {
                cin >> largeGrid[i][j];
            }
        }

        cin >> n2 >> m2;

        for( i = 0; i < n2; i ++ ) {
            for ( j = 0; j < m2; j ++ ) {
                cin >> smallGrid[i][j];
            }
        }
        
        
        int bigFlag = 0;
        for( i = 0; i <= n1 - n2; i ++ ) {
            for ( j = 0; j <= m1-m2; j ++ ) {
                if( largeGrid[i][j] == smallGrid[0][0]) {
                    int flag = 1;
                    for(k = i; k < i + n2; k ++ ) {
                        for(l = j; l < j + m2; l ++ ) {
                            if( largeGrid[k][l] != smallGrid[k-i][l-j] ){
                                flag = 0;
                                break;
                            }
                        } 
                    }
                    if( flag ) {
                       bigFlag = 1; 
                       break;
                    }
                }
            }
        }
        if( bigFlag ) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        t --;
    } 
    
    
    return 0;
}
