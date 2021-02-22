#include <stdio.h>

#include "menu.h"

int main() {
    system("chcp 65001");
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
