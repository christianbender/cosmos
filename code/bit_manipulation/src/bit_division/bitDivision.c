#include <stdio.h>
#include <assert.h>  /* for the tests */

// Prototypes
void test(void);
unsigned bit_division(unsigned, unsigned);

int main(void) {
    test();
    return 0;
}

void test(void){
    assert(bit_division(23,5) == 4);
    assert(bit_division(25,5) == 5);
    assert(bit_division(5,5) == 1);
    assert(bit_division(3,5) == 0);
    printf("tests successful\n");
}


unsigned bit_division(unsigned numerator, unsigned denominator) {

    unsigned current = 1;
    unsigned answer = 0;

    if ( denominator > numerator)
        return 0;

    else if ( denominator == numerator)
        return 1;

    while (denominator < numerator) {
        denominator <<= 1;
        current <<= 1;
    }

    denominator >>= 1;
    current >>= 1;

    while (current) {
        if ( numerator >= denominator) {
            numerator -= denominator;
            answer |= current;
        }
        current >>= 1;
        denominator >>= 1;
    }
    
    return answer;
}