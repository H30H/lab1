//
// Created by Grisha on 19.02.2021.
//

#include "myVector.h"

myVector *newVector(void *x, void *y, void *z, size_t element_size, unsigned int type, const struct operation *op) {
    myVector *res = (myVector*) malloc(sizeof(myVector));
    res->operation = op;

    res->x = x;
    res->y = y;
    res->z = z;

    res->element_size = element_size;
    res->myVectorSize = sizeof(myVector);
    res->type = type;

    res->add = vectorAdd;
    res->scalarMult = vectorScalarMult;
    res->mult = vectorMult;

    res->print = printVector;
    res->remove = removeMyVector;

    return res;
}

myVector *vectorAdd(myVector *v1, myVector *v2) {
    if (v1->element_size != v2->element_size || v1->type != v2->type) return NULL;

    void *x = calloc(1, sizeof(v1->element_size));
    v1->operation->add(v1->x, v2->x, x);

    void *y = calloc(1, sizeof(v1->element_size));
    v1->operation->add(v1->y, v2->y, y);

    void *z = calloc(1, sizeof(v1->element_size));
    v1->operation->add(v1->z, v2->z, z);

    return newVector(x, y, z, v1->element_size, v1->type, v1->operation);
}

void *vectorScalarMult(myVector *v1, myVector *v2) {
    if (v1->element_size != v2->element_size || v1->type != v2->type) return NULL;

    void *x = malloc(sizeof(v1->element_size)), *y = malloc(sizeof(v1->element_size)), *z = malloc(sizeof(v1->element_size));
    v1->operation->mult(v1->x, v2->x, x);
    v1->operation->mult(v1->y, v2->y, y);
    v1->operation->mult(v1->z, v2->z, z);

    void *sum = malloc(sizeof(v1->element_size));
    v1->operation->add(x, y, sum);
    v1->operation->add(sum, z, sum);

    return sum;
}

myVector *vectorMult(myVector *v1, myVector *v2) {
    if (v1->element_size != v2->element_size || v1->type != v2->type) return NULL;

    void *x = malloc(sizeof(v1->element_size)), *y = malloc(sizeof(v1->element_size)), *z = malloc(sizeof(v1->element_size)),
         *k1 = malloc(sizeof(v1->element_size)), *k2 = malloc(sizeof(v1->element_size));
    struct operation *op = v1->operation;
    op->sub(op->mult(v1->y, v2->z, k1), op->mult(v1->z, v2->y, k2), x);

    op->sub(op->mult(v1->z, v2->x, k1), op->mult(v1->x, v2->z, k2), y);

    op->sub(op->mult(v1->x, v2->y, k1), op->mult(v1->y, v2->x, k2), z);

    return newVector(x, y, z, v1->element_size, v1->type, op);
}

void printVector(myVector *v) {
    if (v == NULL) {
        printf("Пустой вектор!");
        return;
    }
    printf("Тип вектора: %s", v->operation->type);

    printf("; элемент х: ");
    v->operation->print(v->x);
    printf("; элемент y: ");
    v->operation->print(v->y);
    printf("; элемент z: ");
    v->operation->print(v->z);
    printf("\n");
}

void removeMyVector(myVector *v) {
    free(v->x);
    free(v->y);
    free(v->z);

    free(v);
}