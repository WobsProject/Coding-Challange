#include <stdio.h>

#define ledPin 13

char *alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
int x, y;

void app_main(void) {
    while(1){
        for(x=0; x<10; x++){
            for(y=x; y<26 ; y++){
                printf(alphabet[y]);
            }
            for(y=0; y<x ; y++){
                printf(alphabet[y]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
    }
}
