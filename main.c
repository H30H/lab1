#include <stdio.h>

#include "menu.h"

void test1() {
    complex *c1 = newComplex(1, 2);
    complex *c2 = newComplex(3, 4);
    complex *c3 = malloc(sizeof(complex));
    complexAdd(c1, c2, c3);

    complexPrint(c1); printf("\n");
    complexPrint(c2); printf("\n");
    complexPrint(c3); printf("\n\n");

    complexSub(c1, c2, c3);

    complexPrint(c1); printf("\n");
    complexPrint(c2); printf("\n");
    complexPrint(c3); printf("\n\n");

    complexMult(c1, c2, c3);

    complexPrint(c1); printf("\n");
    complexPrint(c2); printf("\n");
    complexPrint(c3); printf("\n");

    exit(0);
}

void test() {
    //test1();
    myVector *v1 = getVector();
    myVector *v2 = getVector();

    v1->print(v1);
    v2->print(v2);
    printf("El size: %d\n", v1->element_size);
    myVector *v3 = v2->add(v1, v2);
    printf("Сумма: ");
    v3->print(v3);
    v3->remove(v3);
    printf("\nСкалярное произведение: ");
    v3 = v1->scalarMult(v1, v2);
    v3->print(v3);
    v3->remove(v3);
    printf("\nВекторное произведение: ");
    v3 = v1->mult(v1, v2);
    v3->print(v3);
    int i;
    scanf("%d", &i);
    exit(0);
}


int main() {
    //system("chcp 65001");
    //test();
    double xx = 1, yy = 2, zz = 3;
    int err, n, len = 0;
    myVector *v = NULL;
    myVector **arr = (myVector **) malloc(sizeof(myVector *));
    do {
        printMenu();
        err = scanf("%d", &n);
        if (err <= 0 || n > 6 || n < 1) {
            printf("Неправильно введено число, повторите попытку: ");
            if (err <= 0) scanf("%s");
            continue;
        }
        if (n == 6) break;

        switch (n) {
            case 1: v = getVector(); break;
            case 2: writeVector(&arr, &len, &v); break;
            case 3: operationWithVector(arr, len, &v); break;
            case 4: printArrVector(&arr, len); break;
            case 5: removeArr(&arr, &len); break;
            default: break;
        }
    } while (1);

    for (int i = 0; i < len; i++) {
        arr[i]->remove(arr[i]);
    }
    free(arr);
    if (v != NULL) v->remove(v);
    /*
    complex k1 = {1.0, 2.0, 0},
            k2 = {3.0, 4.0, 0},
            *k3;
    //int *a = (int*) malloc(sizeof(int));
    //int b = 0, c = 1;
    int a;
    int err = scanf("%d", &a);
    printf("%d %d\n", err, a);
    err = scanf("%d", &a);
    printf("%d %d\n", err, a);*/
    return 0;
}
