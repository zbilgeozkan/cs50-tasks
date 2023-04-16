#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) {
    float dollars = get_float("Change owed: ");
    int coins = round(dollars * 100);

    int num = 0;

    while (coins >= 25) {
        coins = coins - 25;
        num = num + 1;

    }
    while (coins >= 10) {
        coins = coins - 10;
        num = num + 1;

    }
    while (coins >= 5) {
        coins -= 5;
        num = num + 1;
    }
    while (coins >= 1) {
        coins -= 1;
        num++;
    }
    printf("Required amount of coins: %i \n", num);

}
