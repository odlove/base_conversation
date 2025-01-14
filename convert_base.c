#include <stdio.h>
#include <stdlib.h>


void usage() {
    printf("Usage: <command> <num>\n");
    printf("'xtb ff1f' to convert hex to bin\n");
    printf("'dtb 123' to convert decimal to bin\n");
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

    long number;

    switch (argv[0][0]) {
        case 'x':
            number = strtol(argv[1], NULL, 16);
            // printf("%ld\n", number);
            break;
        case 'd':
            number = strtol(argv[1], NULL, 10);
            // printf("%ld\n", number);
            break;
    }

    switch (argv[0][2]) {
        case 'b':
            printBinary(number);
            break;
    }

}
