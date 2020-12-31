#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <stdbool.h>

typedef char numberType;

typedef struct  {

    float imaginary;
    float real;   

} complexNumber;

bool isEven(float f) {
    int integer = (int)f;
    float half = f/2;
    int halfI = integer/2;
    if (halfI == half)
        return true;
    return false;
}

complexNumber createComplex(float real, float im) {
    complexNumber c;
    c.real = real;
    c.imaginary = im;
    return c;
}

float SquareModule(complexNumber num) {
    return (num.real*num.real+num.imaginary*num.imaginary);
}

complexNumber Square(complexNumber num) {

        return createComplex(
            (num.real * num.real) - (num.imaginary * num.imaginary)  ,
            2*num.real*num.imaginary );
}

complexNumber Sum(complexNumber a, complexNumber b) {
    return createComplex(a.real+b.real, a.imaginary+b.imaginary);
}

#endif