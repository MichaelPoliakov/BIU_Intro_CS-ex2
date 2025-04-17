/******************
Name: Michael Poliakov
ID: 315940791
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
        char i = 0;
        printf("Choose an option:\n");
        jump_here:
          printf("\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n"
                 "\t4. Circle Of Joy\n\t5. Happy Numbers\n"
                 "\t6. Festival Of Laughter\n\t7. Exit\n");
        if(scanf(" %d", &i) < 1) return 0;
        if(i<1 || i>7){
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
        case 1:
          char eye, nose, mouth;
          int n = 0;
          printf("Enter symbols for the eyes, nose, and mouth:\n");
          if(scanf(" %c %c %c", &eye, &nose, &mouth) < 3) return 1;
          printf("Enter face size:\n");
          if(scanf(" %d", &n) <  1) return 1;
          while((n <= 0) || (n % 2 == 0)){
            printf("The face's size must be an odd and positive number,"
                   " please try again:\n");
            if(scanf(" %d", &n) <  1) return 0;
          }
          printf("%c%*c\n", eye, n + 1, eye);
          printf("%*c\n", (n + 1) / 2 + 1, nose);
          printf("\\");
          for(int j=0; j < n; j++) printf("%c", mouth);
          printf("/\n");
          break;

          // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
          // and the sum of all digits to the right of the middle digit(s) are equal
          /* Examples:
          Balanced: 1533, 450810, 99
          Not blanced: 1552, 34
          Please notice: the number has to be bigger than 0.
          */
        case 2:
          printf("Enter a number:\n");
          int i, tmp;
          if(scanf(" %d", &i) < 1) return 1;
          for(int j)
          printf("This number is balanced and brings harmony!\n");


        }


    



	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}
