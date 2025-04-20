/******************
Name: Michael Poliakov
ID: 315940791
Assignment: ex2
*******************/
#define LEN 1000

#include <stdio.h>


int main() {
        int i = 0, n = 0;
        jump_here:
          printf("Choose an option:\n");
          printf("\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n"
                 "\t4. Circle Of Joy\n\t5. Happy Numbers\n"
                 "\t6. Festival Of Laughter\n\t7. Exit\n");
          if(scanf(" %d", &i) < 1) return 1;
          if(i < 1 || i > 7) {
            printf("This option is not available, please try again.\n");
            goto jump_here;
          }
        switch (i) {
        case 7:
          printf("Thank you for your journey through Numeria!\n");
          return 0;


        // Case 1: Draw Happy Face with given symbols for eyes, nose and mouth
        /* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
         */
        case 1: {
          char eye, nose, mouth;
          printf("Enter symbols for the eyes, nose, and mouth:\n");
          if (scanf(" %c %c %c", &eye, &nose, &mouth) < 3)
            return 1;
          printf("Enter face size:\n");
          if (scanf(" %d", &n) < 1)
            return 1;
          while ((n <= 0) || (n % 2 == 0)) {
            printf("The face's size must be an odd and positive number,"
                   " please try again:\n");
            if (scanf(" %d", &n) < 1)
              return 1;
          }
          printf("%c%*c\n", eye, n + 1, eye);
          printf("%*c\n", (n + 1) / 2 + 1, nose);
          printf("\\");
          for (int j = 0; j < n; j++)
            printf("%c", mouth);
          printf("/\n");
        } break;

          // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
          // and the sum of all digits to the right of the middle digit(s) are equal
          /* Examples:
          Balanced: 1533, 450810, 99
          Not blanced: 1552, 34
          Please notice: the number has to be bigger than 0.
          */
        case 2:
          printf("Enter a number:\n");
          while(1) {
            if (scanf(" %d", &n) < 1) return 1;
            if (n > 0) break;
            printf("Only positive number is allowed, please try again:\n");
          }
          {
            int reversed = 0, original = n;
            while (n > 0) {
              reversed = reversed * 10 + n % 10;
              n /= 10;
            }
            if(reversed == original)
              printf("This number is balanced and brings harmony!\n");
            else
              printf("This number isn't balanced and destroys harmony.\n");
          }
          break;

          // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
          /* Examples:
          Abudant: 12, 20, 24
          Not Abudant: 3, 7, 10
          Please notice: the number has to be bigger than 0.
          */
        case 3:
          printf("Enter a number:\n");
          while(1) {
            if (scanf(" %d", &n) < 1) return 1;
            if (n > 0) break;
            printf("Only positive number is allowed, please try again:\n");
          }
          {
            int sum = 0;
            for (int d = 1; d <= n / 2; d++) {
              if (n % d == 0)
                sum += d;
            }

            if (sum > n)
              printf("This number is generous!\n");
            else
              printf("This number does not share.\n");
          }
          break;

        case 4: {
          printf("Enter a number:\n");
          while (1) {
            if (scanf(" %d", &n) < 1)
              return 1;
            if (n > 0)
              break;
            printf("Only positive number is allowed, please try again:\n");
          }
          int reversed = 0, original = n;
          while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
          }
          int success;
          if (original == 1)
            success = 0;
          else {
            success = 1;
            for (int j = 2; j * j <= original && j * j <= reversed; j++) {
              if ((original % j) == 0 || (reversed % j) == 0) {
                success = 0;
                break;
              }
            }
          }
          if (success)
            printf("This number completes the circle of joy!\n");
          else
            printf("The circle remains incomplete.\n");

        } break;

          // Happy numbers: Print all the happy numbers between 1 to the given number.
          // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
          /* Examples:
          Happy :) : 7, 10
          Not Happy :( : 5, 9
          Please notice: the number has to be bigger than 0.
          */

        case 5:
          printf("Enter a number:\n");
          n = 0;
          while (!(n > 0)) {
            if (scanf(" %d", &n) < 1) return 1;
            if (n > 0)
              continue;
            printf("Only positive number is allowed, please try again:\n");
          }
          printf("Between 1 and %d only these numbers bring happiness:", n);

          for (int j = 1; j <= n; j++) {
            int seen[LEN] = {0}, tmp = j;
            while (!seen[tmp] && tmp != 1) {
              seen[tmp] = 1;
              int sum = 0;
              while (tmp > 0) {
                int d = tmp % 10;
                sum += d * d;
                tmp /= 10;
              }
              tmp = sum;
            }
            if (tmp == 1)
              printf(" %d", j);
          }
          printf("\n");
          break;

        case 6:
          printf("Enter a smile and cheer number:\n");
          int cheerNumber, smileNumber;
          while(1) {
            while (getchar() != '\n'); // clean STDIN buffer
            int flag = scanf("smile: %d , cheer: %d", &smileNumber, &cheerNumber);
            if (0 < smileNumber && 0 < cheerNumber && flag == 2)
              break;
            printf("Only 2 different positive numbers in the given format are "
                   "allowed for the festival, please try again:\n");
          }
          printf("Enter maximum number for the festival:\n");
          while(1) {
            if (scanf(" %d", &n) < 1) return 1;
            if (n > 0) break;
            printf("Only positive maximum number is allowed, please try again:\n");
          }
          for (int j = 1; j <= n; j++) {
            if (j % smileNumber == 0) {
              if (j % cheerNumber == 0)
                printf("Festival!\n");
              else
                printf("Smile!\n");
            }
            else {
              if (j % cheerNumber == 0)
                printf("Cheer!\n");
              else
                printf("%d\n", j);
              }
            }
            break;
          }
          goto jump_here;

          return 0;
}
