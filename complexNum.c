//
// Created by Grisha on 18.02.2021.
//

#include "complexNum.h"

complex *newComplex(float realPart, float complexPart) {
    complex *res = (complex*) malloc(sizeof(complex));
    res->realPart = realPart;
    res->complexPart = complexPart;
    res->size = sizeof(complex);
    return res;
}


void* complexAdd(void *num1, void *num2, void *res) {
    complex *n1 = (complex*) num1;
    complex *n2 = (complex*) num2;
    complex *n3 = newComplex(n1->realPart + n2->realPart, n1->complexPart + n2->complexPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}

void* complexSub(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart - n2->realPart, n1->complexPart - n2->complexPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}

void* complexMult(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart * n2->realPart - n1->complexPart * n2->complexPart,
                             n1->realPart * n2->complexPart + n1->complexPart * n2->realPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}

void complexPrint(void *num) {
    complex *n = num;
    printf("%f + %fi", n->realPart, n->complexPart);
}