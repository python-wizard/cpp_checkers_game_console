

#include "../include/other.h"
void clean_array(int *array) {
    int i;
    for (i=0; i<10; i++) {
        int size = sizeof array / sizeof *array;
        memset(array, 0, size);
    }
}


//void clean_array(char *array) {
//    int i;
//    for (i=0; i<10; i++) {
//        memset(array, 0, strlen(array));
//    }
//}
