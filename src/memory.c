#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(4 * sizeof(int));
    if (!p) return 1;

    printf("Allocated at: %p\n", (void*)p);
    free(p);
    printf("Memory freed\n");
    return 0;
}
