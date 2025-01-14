#include <stdio.h>
#include <stdlib.h>


void usage() {
    printf("Usage: <command> <num>\n");
    printf("Example: 'xtb ff1f' to convert binary to hexadecimal\n");
    exit(1);
}

void printBinary(unsigned int num) {
    int count = 0;
    for (int i = sizeof(int)*8-1; i>=0; i--) {
        printf("%d", (num >> i) & 1);
        count++;
        if (count % 4 == 0 && i!=0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

int main(int argc, char** argv) {
    if(argc != 2)
        usage();

    long number = strtol(argv[1], NULL, 16);
    printBinary(number);
}
