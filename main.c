#include <endian.h>
#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PI 3.14

int revenue_eater() {
  int apple_qty;
  int orange_qty;
  int orange_price;
  int apple_price;
  int revenue;
  printf("--- Revenue Eater V1 ---\n");
  printf("Apples --\n");
  printf("Enter Apple Quantity: ");
  scanf("%d", &apple_qty);
  printf("Enter Apple Price: $");
  scanf("%d", &apple_price);
  printf("Oranges --\n");
  printf("Enter Orange Quantity: ");
  scanf("%d", &orange_qty);
  printf("Enter Orange Price: $");
  scanf("%d", &orange_price);
  revenue = apple_qty * apple_price + orange_qty * orange_price;
  printf("Total Revenue: $%d\n", revenue);
  return 0;
}

void winners_eater() {
  int numParticipants = 0;
  int points[] = {0, 1, 2, 3, 3};
  int hightest_point = 0;
  int winners = 0;
  printf("--- Winners Eater V1 ---\n");
  printf("Enter Number of Participants: ");
  scanf("%d", &numParticipants);

  if (numParticipants <= 1) {
    printf("Invalid number of participants.\nThere must be at least 2 "
           "participants\n");
  } else {
    for (int i = 0; i < numParticipants; i++) {
      printf("Participant %d\n", i + 1);
      printf("Enter Points: ");
      scanf("%d", &points[i]);
      if (i == 0 || (i > 0 && points[i] > points[i - 1])) {
        hightest_point = points[i];
      }
    }
    // Calculate the winner's points
    for (int i = 0; i < numParticipants; i++) {
      if (points[i] == hightest_point) {
        winners += 1;
        printf("The Winner is Participant: %d\n", i+1);
      }
      if (winners > 1) {
        printf("\nThere is a TIE!\n");
      }
    }
  }
}

void simple_calculator() {
  int num1;
  int num2;
  char operation;
  printf("--- Simple Calculator V1 ---\n");
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  printf("Enter an operation: \n");
  scanf(" %c", &operation);
  switch (operation) {
    case '+':
      printf("%d + %d = %d\n", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%d - %d = %d\n", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%d * %d = %d\n", num1, num2, num1 * num2);
      break;
    case '/':
      printf("%d / %d = %d\n", num1, num2, num1 / num2);
      break;
    default:
      printf("Invalid operation\n");
  }
}

void sum_of_evens() {
  int limit = 100;
  int sum = 0;
  printf("--- Sum of Even Numbers V1 ---\n");
  for (int i = 1; i <= limit; i++) {
    if (i % 2 == 0) {
      sum += i;
    }
  }
  printf("Sum of Even Numbers: %d\n", sum);
}

void grade_system() {
  char grade;
  float avg_score = 0;
  char subjects[][100] = {"Math", "Science", "English"};
  for (int i = 0; i < 3; i++) {
    int score = 0;
    printf("Enter Score for %s: ", subjects[i]);
    scanf(" %d", &score);
    avg_score += score;
  }
  avg_score /= 3;
  if (avg_score >= 90) {
      grade = 'A';
    } else if (avg_score >= 80 && avg_score < 90) {
      grade = 'B';
    } else if (avg_score >= 70 && avg_score < 80) {
      grade = 'C';
    } else {
      grade = 'F';
    }
  printf("Score: %.2f\n", avg_score);
  printf("Grade: %c\n", grade);
}

void polar_rectangle_converter() {
  /* Converts polar form to rectangular form and vice a versa */
  char input[100+1];
  float real, imag, angle, magnitude;
  char operator;
  int flag, type;
  printf("This program will auto detect the expression as rectangular or polar form and convert to polar and rectangular forms respectively. \nEnter Expression to convert: ");
  fgets(input, sizeof(input), stdin);

  flag = sscanf(input, "%f %c j%f", &real, &operator, & imag);

  if (flag == 3 && (operator== '+' || operator== '-')) {
      // Rectangular form
      type = 0;
      magnitude = sqrt(pow(real, 2) + pow(imag, 2));
      angle = atan2(imag, real) * (180/PI);
  } else if (sscanf(input, "%f < %f", &magnitude, &angle) == 2) {
      // Polar form
      type = 1;
      angle *= PI / 180;
      real = magnitude * cos(angle);
      imag = magnitude * sin(angle);
      operator = imag >= 0 ? '+' : '-';
      imag *= imag >= 0 ? 1 : -1;
  } else {
      type = -1;
  }

  if (type == 1) { // Print the rectangular form from polar form
      printf("Rectangular form: %.3f %c j%.3f\n", real, operator, imag);
  } else if (type == 0) { // Print the polar form from rectangular form
      printf("Radius: %.3f Angle: %.3f\n", magnitude, angle);
  }
  printf("Press Any Key To Continue");
  getchar();
}

void fibbonachi(int limit) {
  int a = 0;
  int b = 1;
  printf("%d %d", a, b);
  while (limit > 0) {
      int c = a + b;
      printf(" %d", c);
      a = b;
      b = c;
      limit--;
  }
  printf("\n");
}

int is_prime(int num) {
  for (int i = 2; i < num; i++) {
      if (num % i == 0) return 0;
  }
  return 1;
}

void primegen(int limit) {
  int prev = 1;
  for (int i = 0; i < limit; i++) {
      for (int j = 2; j < prev; j++) {
      if (prev % j == 0)
        prev++;
      }
    printf("%d ", prev);
    prev++;
  }
  printf("\n");
}

void array_reverse() {
  int arr_len = 6;
  int arr[arr_len];
  int temp, pivot;
  // Create a new array
  for (int x = 0; x < arr_len; x++) {
    arr[x] = x * x;
  }

  // Reverse it
  pivot = arr_len/2;
  for (int i = 0; i < pivot; i++) {
    temp = arr[arr_len - i - 1];
    arr[arr_len - i - 1] = arr[i];
    arr[i] = temp;
  }

  // Print it
  for (int i = 0; i < arr_len; i++) {
    printf("%d %d\n", arr[i], i);
  }
}

// TODO
void concat(char *a, char *b) { printf("%s", a); }

int digits_in_num(int num) {
  /*Return the number of digits in the number*/
  // Handle Negative numbers
  if (num < 0) {
    num *= -1;
  }
  int digits = 1;
  while (num / 10 != 0) {
    digits++;
    num /= 10;
  }
  return digits;
}

void number_tree(int limit) {
  int num_digits;
  num_digits = digits_in_num(limit);
  for (int i = 1; i <= limit; i++) {
    // Add spaces
    for (int k = 0; k < limit - i; k++) {
      for (int m = 0; m < num_digits; m++) {
        printf(" ");
      }
    }
    // Print the numbers
    for (int j = 1; j <= i; j++) {
      printf("%d  ", i);
      // Print Extra Gaps
      for (int m = 0; m < num_digits-digits_in_num(i); m++) {
        printf(" ");
      }
    }
    printf("\n");
  }
}


int main() {
  // revenue_eater();
  // winners_eater();
  // simple_calculator();
  // sum_of_evens();
  // grade_system();
  // polar_rectangle_converter();
  // fibbonachi(50);
  // primegen(50);
  // array_reverse();
  // char str[] = "";

  // concat("Sup", "Nerds"); // Not Needed Hopefully
  number_tree(30);
  // 
  // int num;
  // scanf("%d", &num);
  // digits_in_num(num);

  return 0;
}
