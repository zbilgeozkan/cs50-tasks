#include <stdio.h>
#include <cs50.h>

int main (void) {
    long number = get_long("Please enter your credit card number: ");
    long check = number;

    int first_two = 0;
    int counter = 0;
    
    while(check > 0) {
        if(check < 100 && check > 10) {
            first_two = check;
        }
        counter++;
        check /= 10;
    }

    if( (counter != 13) && (counter != 15) && (counter != 16) ) {
        printf("INVALID\n");
    }

    // Luhn's Algorithm
    else {
        int a = 0;  // un-underlined counter
        int b = 0;  // underlined counter
        int c = 0;

        while(number > 0) {
            a += number % 10;
            number /= 10;

            if(number > 0) {
                c = (number % 10) * 2;
                b += c / 10;
                b += c % 10;
                
                number /= 10;
            }
        }
        int remained = (a + b) % 10;    // if the last digit is 0 or not

        if (remained != 0) {
            printf("INVALID\n");
        }
        else if (remained == 0) {
            if ( (counter == 15) && ((first_two == 34) || (first_two == 37)) ) {
                printf("AMEX\n");
            }
            else if ( (counter == 16) && ((first_two == 51) || (first_two == 52) || (first_two == 53) || (first_two == 54) || (first_two == 55)) ) {
                printf("MASTERCARD\n");
            }
            else if( ((counter == 13) || (counter == 16)) && (first_two / 10 == 4) ) {
                printf("VISA\n");
            }
            else {
                printf("INVALID\n");
            }
        }
    }

}
