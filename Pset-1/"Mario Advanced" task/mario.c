#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0;

    do{
        h = get_int("Please choose the height in integer: ");
        printf("\n");

    } while (h < 1 || h > 8);
    
    for (int j = 1; j <= h; j++) {
        
        for (int i = h; i > j; i--) {
            printf(" ");

        }
        for (int k = 1; k <= j; k++) {
            printf("#");

        }

        for (int z = 0; z <= 1; z++) {
            printf(" ");
        }

        for (int b = 1; b <= j; b++) {
            printf("#");
        }

        printf("\n");
    }

}
