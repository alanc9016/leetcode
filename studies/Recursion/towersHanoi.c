#include <stdio.h>

void towersHanoi(int,char,char,char);

main() {
    towersHanoi(3, 'a', 'b', 'c');
}


void towersHanoi(int n, char src, char dest, char temp) {
    if (n == 0)
        return;
    towersHanoi(n - 1, src, temp, dest);
    printf("%c to %c\n", src, dest);
    towersHanoi(n - 1, temp, dest, src);
}

