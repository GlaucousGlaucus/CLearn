#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

// ----------------------------------------------------

void winners_eater() {
    int players = 0;
    int highest = 0;
    int winners = 0;
    printf("Enter Number of Participants: ");
    scanf("%d", &players);
    int points[players];

    if (players < 2) {
        printf("Invalid number of participants.\nThere must be at least 2 "
               "participants\n");
    } else {
        for (int i = 0; i < players; i++) {
            printf("Participant %d\n", i + 1);
            printf("Enter Points: ");
            scanf("%d", &points[i]);
            if (i == 0 || (i > 0 && points[i] > points[i - 1])) {
                highest = points[i];
            }
        }
        // Calculate the winner's points
        for (int i = 0; i < players; i++) {
            if (points[i] == highest) {
                winners += 1;
                printf("The Winner is Participant: %d\n", i + 1);
            }
            if (winners > 1) {
                printf("\nThere is a TIE!\n");
            }
        }
    }
}

// ----------------------------------------------------

void simple_calculator() {
    int num1, num2, result;
    char operation;
    printf("--- Simple Calculator V1 ---\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter an operation: \n");
    scanf(" %c", &operation);
    switch (operation) {
        case '+':
            result =  num1 + num2;
            break;
        case '-':
            result =  num1 - num2;
            break;
        case '*':
            result =  num1 * num2;
            break;
        case '/':
            result =  num1 / num2;
            break;
        default:
            printf("Invalid operation\n");
            return;
    }
    printf("%d %c %d = %d\n", num1, operation, num2, result);
}

// ----------------------------------------------------

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

// ----------------------------------------------------

void grade_system() {
    char grade;
    float avg_score = 0;
    char subjects[][100] = {"Math", "Science", "English"};
    for (int i = 0; i < 3; i++) {
        int score = 0;
        printf("Score in %s: ", subjects[i]);
        scanf(" %d", &score);
        avg_score += score;
    }
    avg_score /= 3;
    if (avg_score >= 90) {
        grade = 'A';
    } else if (avg_score >= 80) {
        grade = 'B';
    } else if (avg_score >= 70) {
        grade = 'C';
    } else {
        grade = 'F';
    }
    printf("Score: %.2f\n", avg_score);
    printf("Grade: %c\n", grade);
}

// ----------------------------------------------------

void temperature_conversion() {
    int in_type;
    double in_value, celsius;
    printf("Index: 0 = C, 1 = F, 2 = K, 3 = Rankine, 4 = Reaumur\n");
    printf("Enter Input Temperature Type: ");
    scanf("%d", &in_type);
    printf("Enter Temperature: ");
    scanf("%lf", &in_value);

    printf("--------- Temperature Table ------------\n");

    switch (in_type) {
        case 0: celsius = in_value; break;
        case 1: celsius = (in_value - 32) * 5 / 9; break;
        case 2: celsius = in_value - 273.15; break;
        case 3: celsius = (in_value - 491.67) * 5 / 9; break;
        case 4: celsius = in_value * 1.25; break;
        default: printf("Invalid Type %d", in_type); return;
    }

    printf("Celsius: %5.2lf\n", celsius);
    printf("Fahrenheit: %5.2lf\n", (celsius * 9 / 5) + 32);
    printf("Kelvin: %5.2lf\n", celsius + 273.15);
    printf("Rankine: %5.2lf\n", (celsius * 9 / 5) + 491.67);
    printf("Reaumur: %5.2lf\n", celsius / 1.25);

}

// ----------------------------------------------------

int padovan_term(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1 || n == 2) return 1;
    return padovan_term(n - 2) + padovan_term(n - 3);
}

void padovan_gen_limit() {
    int limit, sum = 0, term;
    printf("Enter Limit: ");
    scanf("%d", &limit);
    for (int i = 0; i < limit; i++) {
        term = padovan_term(i);
        printf("%d ", term);
        sum += term;
    }
    printf("Sum of sequence upto %d is %d", limit, sum);
}

// ----------------------------------------------------

void volume_calc() {
    int choice;
    double l, w, h, r, base, side, a, b, c;

    printf("Select the shape:\n");
    printf("1. Cuboid\n");
    printf("2. Cube\n");
    printf("3. Cylinder\n");
    printf("4. Prism\n");
    printf("5. Sphere\n");
    printf("6. Pyramid\n");
    printf("7. Right Circular Cone\n");
    printf("8. Square or Rectangular Pyramid\n");
    printf("9. Ellipsoid\n");
    printf("10. Tetrahedron\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Rectangular Solid or Cuboid
            printf("Enter l, w, and h: ");
            scanf("%lf, %lf, %lf", &l, &w, &h);
            printf("Volume: %.2f\n", l * w * h);
            break;
        case 2: // Cube
            printf("Enter l of side: ");
            scanf("%lf", &side);
            printf("Volume: %.2f\n", pow(side, 3));
            break;
        case 3: // Cylinder
            printf("Enter r and h: ");
            scanf("%lf, %lf", &r, &h);
            printf("Volume: %.2f\n", PI * pow(r, 2) * h);
            break;
        case 4: // Prism
            printf("Enter base area and h: ");
            scanf("%lf, %lf", &base, &h);
            printf("Volume: %.2f\n", base * h);
            break;
        case 5: // Sphere
            printf("Enter r: ");
            scanf("%lf", &r);
            printf("Volume: %.2f\n", (4.0 / 3.0) * PI * pow(r, 3));
            break;
        case 6: // Pyramid
            printf("Enter base area and h: ");
            scanf("%lf, %lf", &base, &h);
            printf("Volume: %.2f\n", (1.0 / 3.0) * base * h);
            break;
        case 7: // Right Circular Cone
            printf("Enter r and h: ");
            scanf("%lf, %lf", &r, &h);
            printf("Volume: %.2f\n", (1.0 / 3.0) * PI * pow(r, 2) * h);
            break;
        case 8: // Square or Rectangular Pyramid
            printf("Enter l, w, and h: ");
            scanf("%lf, %lf, %lf", &l, &w, &h);
            printf("Volume: %.2f\n", (1.0 / 3.0) * l * w * h);
            break;
        case 9: // Ellipsoid
            printf("Enter semi-axes a, b, and c: ");
            scanf("%lf, %lf, %lf", &a, &b, &c);
            printf("Volume: %.2f\n", (4.0 / 3.0) * PI * a * b * c);
            break;
        case 10: // Tetrahedron
            printf("Enter l of edge: ");
            scanf("%lf", &side);
            printf("Volume: %.2f\n", pow(side, 3) * 0.11785);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// ----------------------------------------------------

double f(double x) { return 1 / (x * x * x); }

void derivative_at_x(double x) {
    double h = 0.01;
    double der = (f(x + h) - f(x - h)) / (2.0 * h);
    printf("f'(%.2f) = %.2f\n", x, der);
}

void definite_integration_trapezoidal() {
    double ret;
    double lower = 0, upper = 4;
    ret = (upper - lower) * (f(lower) + f(upper)) / 2;
    printf("The Definite Integral is: %.3f\n", ret);
}

void definite_integral_simpson_3_8() {
    int intervals = 99999;
    double lower = 0, upper = 4;
    double h = (upper - lower) / intervals;
    double ret = f(lower) + f(lower + intervals * h);
    for (int i = 1; i < intervals; i++) {
        if (i % 3 == 0) ret += 2 * f(lower + i * h);
        else ret += 3 * f(lower + i * h);
    }
    ret *= (3.0 * h) / 8.0;
    printf("The Definite Integral is: %f", ret);
}

// ----------------------------------------------------

void polar_rectangle_converter() {
    /* Converts polar form to rectangular form and vice a versa.
     * Auto Detects whether the input is in polar or rectangular form.*/
    char input[100 + 1], operator;
    double real, imag, angle, magnitude;
    int flag, type;
    printf("Enter Expression to convert: ");
    fgets(input, sizeof(input), stdin);

    flag = sscanf(input, "%lf %c j%lf", &real, &operator, &imag);
    flag |= sscanf(input, "%lf %c %lfj", &real, &operator, &imag);

    if (flag == 3 && (operator == '+' || operator == '-')) {
        // Rectangular form
        type = 0;
        magnitude = sqrt(pow(real, 2) + pow(imag, 2));
        angle = atan2(imag, real) * (180 / PI);
        printf("Radius: %.3f Angle: %.3f\n", magnitude, angle);
    } else if (sscanf(input, "%lf < %lf", &magnitude, &angle) == 2) {
        // Polar form
        type = 1;
        angle *= PI / 180;
        real = magnitude * cos(angle);
        imag = magnitude * sin(angle);
        operator = imag >= 0 ? '+' : '-';
        imag *= imag >= 0 ? 1 : -1;
        printf("Rectangular form: %.3f %c j%.3f\n", real, operator, imag);
    } else {
        printf("Invalid Expression\n");
    }
    printf("Press Any Key To Continue");
    getchar();
}

// ----------------------------------------------------

void fibonacci_gen_limit(int limit) {
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

// ----------------------------------------------------

int is_prime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void prime_gen(int limit) {
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

// ----------------------------------------------------

void array_reverse() {
    int arr_len = 6;
    int arr[arr_len];
    int temp, pivot;
    // Create a new array
    for (int x = 0; x < arr_len; x++) {
        printf("E%d: ", x);
        scanf("%d", &arr[x]);
    }

    // Reverse it
    pivot = arr_len / 2;
    for (int i = 0; i < pivot; i++) {
        temp = arr[arr_len - i - 1];
        arr[arr_len - i - 1] = arr[i];
        arr[i] = temp;
    }

    // Print it
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }
}

// ----------------------------------------------------

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

// ----------------------------------------------------

void number_tree(int limit) {
    int num_digits = digits_in_num(limit);
    for (int i = 1; i <= limit; i++) {
        printf("%*s", num_digits * (limit - i), "");
        // Print the numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
            printf("%*s", num_digits - digits_in_num(i) + num_digits, "");
        }
        printf("\n");
    }
}

// ----------------------------------------------------

int armstrong(int num) {
    int sum = 0, numf = num, digits = digits_in_num(num);
    while (num != 0) {
        sum += (int) powl(num % 10, digits);
        num /= 10;
    }
    return sum == numf;
}

// ----------------------------------------------------

int factorial_loop(int num) {
    int factorial = 1;
    while (num != 1) {
        factorial *= num;
        num--;
    }
    return factorial;
}

int factorial_recursion(int num) {
    if (num == 1 || num == 0) return 1;
    return num * factorial_recursion(num - 1);
}

// ----------------------------------------------------

void quadratic_eqn_solver() {
    double a, b, c, D, roots[2];
    printf("Enter a, b and c: ");
    scanf("%lf, %lf, %lf", &a, &b, &c);
    int complex_roots = 0;
    D = pow(b, 2) - 4 * a * c;
    if (D < 0) {
        D *= -1;
        complex_roots = 1;
    }
    D = pow(D, 0.5);

    printf("Roots of %.2fx^2 + %.2fx + %.2f are ", a, b, c);

    if (complex_roots == 1) {
        roots[0] = (-b / 2 * a); // Real Part
        roots[1] = D / (2 * a); // Imaginary Part
        printf("%.2f + %.2f i and %.2f - %.2f i", roots[0], roots[1], roots[0], roots[1]);
    } else {
        roots[0] = (-b + D) / (2 * a);
        roots[1] = (-b - D) / (2 * a);
        printf("%.2f and %.2f", roots[0], roots[1]);
    }
}

// ----------------------------------------------------

double arithmetic_series_sum(double a, double d, int n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

// ----------------------------------------------------

double geometric_series_sum(double a, double r, int n) {
    if (n != -1) {
        if (r < 1) {
            return a * (1 - pow(r, n)) / (1 - r);
        } else if (r > 1) {
            return a * (pow(r, n) - 1) / (r - 1);
        } else {
            return n * a;
        }
    } else {
        if (r >= 1) {
            printf("The series does not converge and does not have a sum!");
        } else {
            return a / (1 - r);
        }
    }
    return NAN;
}

// ----------------------------------------------------

//int helper_2d1d(int row, int column, int columns) {
//    return row * columns + column;
//}
//
//double determinant(double *matrix, int n) {
//    int det;
//    if (n == 2) {
//        return matrix[0] * matrix[3] - matrix[1] * matrix[2];
//    } else {
//
//        return det;
//    }
//}
//
//void matrix_determinant() {
//    int n;
//    printf("Enter The Matrix Order: ");
//    scanf("%d", &n);
//    if (n < 2) {
//        printf("Please Enter a Valid Matrix order");
//        return;
//    }
//    double matrix[n][n];
//    double det;
//    // Matrix Input
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("A%d%d: ", i+1, j+1);
//            scanf("%lf", &(matrix[i][j]));
//        }
//    }
//
//    // Determinant
//    det = determinant((double *) matrix, n);
//    printf("The determinant of matrix is: %f", det);
//}

// ----------------------------------------------------

//void print_matrix(float *matrix, int m, int n) {
//    for (int i = 0; i < n; i++) {
//        printf(i == 0 ? "┌ " : (i == n - 1 ? "└ " : "| "));
//        for (int j = 0; j < m; j++) {
//            printf("%20.2f ", matrix[i * m + j]);
//        }
//        printf(i == 0 ? "┐\n" : (i == n - 1 ? "┘\n" : "| \n"));
//    }
//}

void print_matrix(float matrix[], int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        printf(i == 0 || i == rows - 1 ? "+ " : "| ");
        for (int j = 0; j < cols; j++) {
            printf("%20.2f ", matrix[i * cols + j]);
        }
        printf(i == 0 || i == rows - 1 ? "+\n" : "| \n");
    }
}

void matrix_multiplication() {
    // Get input
    int n, p, m;
    // Get Matrix Orders
    printf("Enter matrix order n, p, m: ");
    scanf("%d, %d, %d", &n, &p, &m);
    // Verify Orders
    if (!(n > 0 && p > 0 & m > 0)) {
        printf("Invalid Orders!");
        return;
    }
    float matrix1[n * p];
    float matrix2[p * m];
    float product_matrix[n * m];

    // Matrix Input
    // Matrix A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("A%d%d: ", i + 1, j + 1);
            scanf("%f", &(matrix1[i * p + j]));
        }
    }
    printf("Matrix A is:\n");
    print_matrix(matrix1, p, n);
    // Matrix B
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < m; j++) {
            printf("B%d%d: ", i + 1, j + 1);
            scanf("%f", &(matrix2[i * m + j]));
        }
    }
    printf("Matrix B is:\n");
    print_matrix(matrix2, p, m);

    // Calculate Product
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            product_matrix[i * m + j] = 0;
            for (int k = 0; k < p; k++) {
                product_matrix[i * m + j] += matrix1[i * p + k] * matrix2[k * m + j];
            }
        }
    }

    // Print Matrix
    printf("The Product Matrix (A x B) is:\n");
    print_matrix(product_matrix, m, n);
}

// ----------------------------------------------------

int binary_to_decimal(int num) {
    int decimal = 0;
    int place = 0;
    while (num != 0) {
        decimal += (num % 10) * powl(2, place);
        num /= 10;
        place++;
    }
    printf("deci: %d", decimal);
    return decimal;
}

// ----------------------------------------------------

int leap_year(int year) {
    return year % 4 == 0;
}

// ----------------------------------------------------

void max_array() {
    // Input array
    int size, max_ind;
    double max;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    double array[size];

    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &array[i]);
        if (array[i] >= max) {
            max = array[i];
            max_ind = i;
        }
    }

    printf("The Largest value in the array is %lf at index %d", max, max_ind);
}

// ----------------------------------------------------

int palindrome_check(char string[]) {
    long len = strlen(string) - 1;
    for (int i = 0; i <= len; i++) {
        if (string[i] != string[len - i]) {
            return 0;
        }
    }
    return 1;
}

// ----------------------------------------------------

int random_int(int seed, int m, int a, int c) {
    /*This is a Linear Congruential (Pseudo) Random Number Generator*/
    return (a * seed + c) % m;
}

// ---------------------------------------------------

void dice_roller() {
    int a = 1103515245, c = 12345, m = (int) powl(2, 31), seed;
    printf("Enter any number: ");
    scanf("%d", &seed);

    // Simplify the roll calculations
    seed = random_int(seed, m, a, c);
    int roll = (abs(seed) % 6) + 1;
    int target_roll = (abs(random_int(seed, m, a, c)) % 6) + 1;

    printf("The Dice rolled a %d. The Target was %d\n", roll, target_roll);

    // Output result
    if (roll == target_roll) {
        printf("You Won!");
    } else {
        printf("You Lost :(");
    }
}

// ---------------------------------------------------

int turn_eval(int p1, int p2) {
    if (p1 == p2) return -1; // Draw
    return (p1 == (p2 + 1) % 3) ? 1 : 2;
}

int eval_player_choice(int input) {
    if (input < 3 && input >= 0) return input;
    return -1;
}

void print_choice_name(int choice) {
    switch (choice) {
        case 0:
            printf("Rock");
            break;
        case 1:
            printf("Paper");
            break;
        case 2:
            printf("Scissors");
            break;
        default:
            break;
    }
}

void rock_paper_scissors() {
    char player_name[100];
    int a = 1103515245, c = 12345, m = (int) powl(2, 31), seed, best_of, p_choice_in;
    int score_player_2 = 0, score_player_1 = 0;
    int p2_choice, p1_choice;
    // Input Game Options
    printf("Please Enter Your Name (Max 100 characters): ");
    scanf("%99s", player_name);
    printf("Score at which a player wins: ");
    scanf("%d", &best_of);

    // Calculate Seed
    seed = ((int) strlen(player_name)) * (best_of);

    // Play game
    while (score_player_1 < best_of && score_player_2 < best_of) {
        printf("Enter Your Choice (0 = Rock/ 1 = Paper/ 2 = Scissors): ");
        scanf("%d", &p_choice_in);
        p1_choice = eval_player_choice(p_choice_in);
        if (p1_choice == -1) {
            printf("Please Enter A Valid Move.\n");
            continue;
        }

        seed = random_int(seed, m, a, c);
        p2_choice = abs(seed) % 3;
        printf("Computer Chose: ");
        print_choice_name(p2_choice);
        printf("\n");
        switch (turn_eval(p1_choice, p2_choice)) {
            case 1:
                score_player_1++;
                break;
            case 2:
                score_player_2++;
                break;
            default:
                break;
        }
    }

    // Display Results

    printf("The Scores are:\n Player: %d \tLCG: %d\n", score_player_1, score_player_2);
    if (score_player_2 > score_player_1) {
        printf("Computer Won with %d point(s)!", score_player_2);
    } else {
        printf("%s Won with %d point(s)!", player_name, score_player_1);
    }
}

// ----------------------------------------------------

int gcf(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void gcf_array() {
    int size, ret, i;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    int nums[size];
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
        if (i == 0) ret = nums[0];
        else ret = gcf(ret, nums[i]);
    }
    printf("GCF is %d", ret);
}

// ----------------------------------------------------

void fraction_representation(double decimal) {
    int numtr, dentr, whole, order = 7, diff;
    printf("Fractional Representation of %f is \n", decimal);
    dentr = (int) powl(10, order);
    decimal *= dentr;
    numtr = (int) decimal;
    diff = gcf(abs(numtr), abs(dentr));
    numtr /= diff;
    dentr /= diff;
    whole = numtr / dentr;
    numtr -= dentr * whole;
    if (numtr == 0) printf("%d", whole);
    else {
        numtr = abs(numtr);
        if (whole == 0) printf("%d/%d", numtr, dentr);
        else printf("%d %d/%d", whole, numtr, dentr);
    }
}

// ----------------------------------------------------

#define BOARD_SIZE 3

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Print the Guides
    char col_headings[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%*c|", BOARD_SIZE, ' ');

    for (int c = 0; c < BOARD_SIZE; c++) {
        printf("  %c  ", col_headings[c]);
    }

    printf("\n%.*s\n", BOARD_SIZE * (1 + 4 + 1), "----------------------");

    // Print the Board
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Print Row Number
        printf("%d  ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == 0) {
                printf("|");
            }
            if (board[i][j] == 1) {
                printf("  X  ");
            } else if (board[i][j] == -1) {
                printf("  O  ");
            } else {
                printf("     ");
            }
        }
        printf("\n");
        if (i >= 0 && i < BOARD_SIZE - 1) {
            printf("---\n");
        }
    }
}

int evaluate_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int hsum = 0, vsum = 0, dsum = 0;
    // Check Horizontal
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            hsum += board[i][j];
            vsum += board[j][i];
        }
        // Check Win
        if (hsum == BOARD_SIZE || vsum == BOARD_SIZE) {
            return 1; // Player 1 wins
        } else if (hsum == -BOARD_SIZE || vsum == -BOARD_SIZE) {
            return 2; // Player 2 wins
        }
        hsum = 0;
        vsum = 0;
    }

    // Check Diagonal
    for (int dir = 0; dir < 2; dir++) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            dsum += board[i][dir == 0 ? i : BOARD_SIZE - i - 1];
        }
        // Check Win
        if (dsum == BOARD_SIZE) {
            return 1; // Player 1 wins
        } else if (dsum == -BOARD_SIZE) {
            return 2; // Player 2 wins
        }
        dsum = 0;
    }
    // Check Draw by checking if the board is full
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) return 0; // Next Turn
        }
    }
    return -1; // Draw
}

int evaluate_action(int board[BOARD_SIZE][BOARD_SIZE], int turn) {
    /*Returns if turn was successful or not*/
    int i, j;
    char temp_j[2];
    scanf("%1s%d", temp_j, &i);
    j = toupper(temp_j[0]) - 'A';
    i--;
    if (i >= BOARD_SIZE || j >= BOARD_SIZE || i < 0 || j < 0 || board[i][j] != 0) return 0;
    // Set Value depending upon turn
    board[i][j] = turn;
    return 1;
}

void tic_tac_toe() {
    int board[BOARD_SIZE][BOARD_SIZE], turn = -1, winner = 0, turn_success;

    // Set Board Values to prevent any garbage values
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (winner == 0) {
        // Input Move
        print_board(board);
        printf("\nPlayer %d's turn\nSelect Cell: ", turn);
        turn_success = evaluate_action(board, turn);
        winner = evaluate_board(board);
        printf("\n");
        if (turn_success) {
            turn = -turn;
        } else {
            printf("Please enter a valid move\n");
            getchar();
            getchar();
        }
    }
    print_board(board);
    switch (winner) {
        case 1:
        case 2:
            printf("Player %d is the winner!\n", winner);
            break;
        default:
            printf("Game Draw\n");
    }
}

// ----------------------------------------------------

char *get_number_suffix(int num) {
    if (num % 100 / 10 == 1) return "th";
    switch (num % 10) {
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}

const char *get_month_from_int(int month) {
    switch (month) {
        case 0:
            return "Jan";
        case 1:
            return "Feb";
        case 2:
            return "Mar";
        case 3:
            return "Apr";
        case 4:
            return "May";
        case 5:
            return "Jun";
        case 6:
            return "Jul";
        case 7:
            return "Aug";
        case 8:
            return "Sep";
        case 9:
            return "Oct";
        case 10:
            return "Nov";
        case 11:
            return "Dec";
        default:
            return "Invalid Month";
    }
}

void print_pretty_date(int day, int month, int year) {
    printf("On %d%s of %s %d it was ", day, get_number_suffix(day),
           get_month_from_int(month), year);
}

void day_from_date(int day, int month, int year) {
    /*Prints the day that was on the given date*/
    int j = year / 100;

    if (month < 3) {
        month += 12;
        year--;
    }

    int weekday = (day + (13 * (month + 1) / 5) + (year % 100) +
                   ((year % 100) / 4) + (j / 4) + 5 * j) % 7;

    print_pretty_date(day, month, year);

    switch (weekday) {
        case 0:
            printf("Saturday\n");
            break;
        case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        default:
            printf("Error: Invalid day of the week\n");
            break;
    }
}

// -----------------------------------------------------

void reverse_num() {
    int num, ret = 0, place;
    printf("Enter Number: ");
    scanf("%d", &num);
    place = powl(10, digits_in_num(num) - 1);
    printf("Reversed Number:");
    while (num != 0) {
        ret += (num % 10) * place;
        num /= 10;
        place /= 10;
    }
    printf("%d", ret);
}

// -----------------------------------------------------

int lcm(int a, int b) {
    int lcm = a > b ? a:b;
    while (1) {
        if ((lcm % a == 0) && (lcm % b == 0)) {
            return lcm;
        }
        lcm++;
    }
}

int lcm_gcd(int a, int b) {
    int lcm = abs(a*b)/gcf(a, b);
    return lcm;
}

void lcm_array() {
    int size, ret, i;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    int nums[size];
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
        if (i == 0) ret = nums[0];
        else ret = lcm(ret, nums[i]);
    }
    printf("LCM is %d", ret);
}

// -----------------------------------------------------

int map_matrix_index(int i, int j, int cols) {
    return i * cols + j;
}

float determinant(float matrix[], int order) {
    int det = 0.0;
    if (order == 1) return matrix[0];
    if (order == 2) return (matrix[0] * matrix[3] - matrix[1] * matrix[2]);
    for (int n = 0; n < order; n++) {
        float minor[order - 1][order - 1];
        // Slice matrix
        for (int i = 1; i < order; i++) {
            int colIndex = 0;
            for (int j = 0; j < order; j++) {
                if (j == n) continue; // Skip the current column
                minor[i - 1][colIndex] = matrix[i * order + j];
                colIndex++;
            }
        }

        float minorDet = determinant((float *) minor, order - 1);

        // Add to the determinant with alternating signs
        if (n % 2 == 0)
            det += matrix[n] * minorDet;
        else
            det -= matrix[n] * minorDet;
    }
    return det;
}

void matrix_determinant() {
    // Get input
    int n;
    // Get Matrix Orders
    printf("Enter matrix order: ");
    scanf("%d", &n);
    // Verify Orders
    if (n <= 0) {
        printf("Invalid Order!");
        return;
    }
    float matrix[n * n], factor;

    // Matrix Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A(%d, %d): ", i + 1, j + 1);
            scanf("%f", &(matrix[i * n + j]));
        }
    }
    printf("Matrix is:\n");
    print_matrix(matrix, n, n);

    printf("Determinant: %.2f", determinant(matrix, n));
}

// -----------------------------------------------------

void bubble_sort() {
    int n = 10, arr[n], element;
    int a = 1103515245, c = 12345, m = (int) powl(2, 31), seed;
    printf("Enter Seed: ");
    scanf("%d", &seed);
    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        element = random_int(seed, m, a, c);
        seed = element;
        arr[i] = element % 51;
        printf("%d ", arr[i]);
    }

    // Sorting
    int i, j, temp;

    for (i = 0 ; i < n - 1; i++) {
        for (j = 0 ; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    // Display mental

    printf("\n");
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    bubble_sort();
//    matrix_determinant();
//    lcm_array();
//    printf("%d", lcm_gcd(5, 7));
//    reverse_num();

//   revenue_eater();
//   winners_eater();
//   simple_calculator();
//   sum_of_evens();
//   grade_system();
//   polar_rectangle_converter();
//   fibonacci_gen_limit(50);
//   prime_gen(50);
//   array_reverse();
//   char str[] = "";
//   number_tree(30);

//   int num;
//   scanf("%d", &num);
//    printf("%d", digits_in_num(-10));

//   printf("%d\n", armstrong(153));
//   printf("%d\n", factorial_loop(5));
//    quadratic_eqn_solver(1, 1, 1);

//    printf("%f\n", arithmetic_series_sum(8, 1, 5));
//    printf("%f\n", geometric_series_sum(8, 1, 5));

//    matrix_multiplication();
//    matrix_determinant();

//    binary_to_decimal(111000);

//    printf("%d leap", leapYear(2024));
//    max_array();
//    printf("%d\n", palindrome_check("madam")); // True
//    printf("%d\n", palindrome_check("madm")); // False

//    printf("%d", random_int(123));
//    rock_paper_scissors();

//    fraction_representation(-1.23);
//    tic_tac_toe();
//    day_from_date(17, 3, 2024);

//    dice_roller();

//    temperature_conversion();
//    padovan_gen_limit();

//    volume_calc();

//    derivative_at_x(2);
//    definite_integration_trapezoidal();
//    definite_integral_simpson_3_8();

//    gcf_array();

    return 0;
}
