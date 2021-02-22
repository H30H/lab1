//
// Created by Grisha on 18.02.2021.
//

#include "stdMath.h"

#define STR(X) #X

#define ImplementateStdMath(TYPE) \
                                    \
void* TYPE##Add(void *num1, void *num2, void *res) { \
    TYPE *t = malloc(sizeof(TYPE)); \
    *t = *((TYPE*)num1) + *((TYPE*)num2); \
    memcpy(res, t, sizeof(TYPE)); \
    free(t);                      \
    return res;                     \
}                                   \
                                    \
void* TYPE##Sub(void *num1, void *num2, void *res) { \
    TYPE *t = malloc(sizeof(TYPE)); \
    *t = *((TYPE*)num1) - *((TYPE*)num2); \
    memcpy(res, t, sizeof(TYPE)); \
    free(t);                      \
    return res;                    \
}                                   \
                                    \
void* TYPE##Mult(void *num1, void *num2, void *res) {\
    TYPE *t = malloc(sizeof(TYPE)); \
    *t = *((TYPE*)num1) * *((TYPE*)num2); \
    memcpy(res, t, sizeof(TYPE)); \
    free(t);                      \
    return res;                    \
}                                   \


ImplementateStdMath(int)
ImplementateStdMath(float)
ImplementateStdMath(double)

void intPrint(void *num) {
    int *n = num;
    printf("%d", *n);
}

void floatPrint(void *num) {
    float *n = num;
    printf("%f", *n);
}

void doublePrint(void *num) {
    double *n = num;
    printf("%lf", *n);
}


#define ImplementateOperation(TYPE) \
                                 \
const struct operation TYPE##Operation = { \
    STR(TYPE),                     \
    TYPE##Add,                     \
    TYPE##Sub,                     \
    TYPE##Mult,                    \
    TYPE##Print                    \
};                             \


ImplementateOperation(int)
ImplementateOperation(float)
ImplementateOperation(double)
ImplementateOperation(complex)