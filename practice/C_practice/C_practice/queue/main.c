//
//  main.c
//  Queue
//
//  Created by leon on 2017/12/6.
//  Copyright © 2017年 Leon. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "queue.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int size = 12;
    Queue Q = createQueue(size);
    for (int i = 0; i <size; i++) {
        int x = rand()%20;
        printf("%d ",x);
        Enqueue(Q, x);
    }
    printf("\ndequeue...\n");
    for (int i = 0; i < size; i++) {
        printf("%d ",Dequeue(Q));
    }
     printf("\n");
      printf("\nenqueue...\n");
    for (int i = 0; i < 4; i++) {
        int x = rand()%20;
        printf("%d ",x);
        Enqueue(Q, x);
    }
        printf("\ndequeue...\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ",Dequeue(Q));
    }
    
    return 0;
}
