#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int quarter = 0, dime = 0, nickel = 0, penny = 0;

        int cent;
        scanf("%d", &cent);
        
        int _quarter;
        _quarter = cent / 25; 
        quarter = _quarter;
        cent -= 25 * _quarter;
        
        int _dime;
        _dime = cent / 10; 
        dime = _dime;
        cent -= 10 * _dime;

        int _nickel;
        _nickel = cent / 5; 
        nickel = _nickel;
        cent -= 5 * _nickel;

        int _penny;
        _penny = cent / 1; 
        penny = _penny;
        cent -= 1 * _penny;

        printf("%d %d %d %d\n", quarter, dime, nickel, penny);
    }

    return 0;
}