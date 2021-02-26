//
// Created by Grisha on 26.02.2021.
//

#include "tests.h"


void tests() {
    srand(0);
    intTest();
}

void intTest() {
    printf("Проверка целочисленных векторов...\n");
    //TODO вручную написать 3-4 примера рассчётов векторов

    printf("Проверка на случайных числах...\n");
    int i, k = 10000;
    for (i = 0; i < k; i++) {
        int x1 = rand(), y1 = rand(), z1 = rand(),
            x2 = rand(), y2 = rand(), z2 = rand();

        myVector *v1 = newVector(&x1, &y1, &z1, sizeof(int), &intOperation);
        myVector *v2 = newVector(&x2, &y2, &z2, sizeof(int), &intOperation);
        
        myVector *v3 = v1->add(v1, v2);
        
        int x = x1 + x2;
        int y = y1 + y2;
        int z = z1 + z2;

        myVector *res = newVector(&x, &y, &z, sizeof(int), &intOperation);

        if (!(v1->isSame(v3, res))) {
            break;
        }

        free(v1);
        free(v2);
        free(v3);
        free(res);
    }
    printf("Проверка на %d случайных числах ", k);
    if (i == k) {
        printf("пройдена!\n");
    }
    else {
        printf("не пройдена!\n");
    }
}