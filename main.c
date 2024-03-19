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
    int numParticipants = 0;
    int points[] = {0, 1, 2, 3, 3};
    int highest_point = 0;
    int winners = 0;
    printf("--- Winners Eater V1 ---\n");
    printf("Enter Number of Participants: ");
    scanf("%d", &numParticipants);

    if (numParticipants < 2) {
        printf("Invalid number of participants.\nThere must be at least 2 "
               "participants\n");
    } else {
        for (int i = 0; i < numParticipants; i++) {
            printf("Participant %d\n", i + 1);
            printf("Enter Points: ");
            scanf("%d", &points[i]);
            if (i == 0 || (i > 0 && points[i] > points[i - 1])) {
                highest_point = points[i];
            }
        }
        // Calculate the winner's points
        for (int i = 0; i < numParticipants; i++) {
            if (points[i] == highest_point) {
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

// ----------------------------------------------------

void temperature_conversion() {
    int in_type;
    double in_value; // Inputs
    double celsius, fahrenheit, kelvin, rankine, reaumur; // Outputs
    printf("Index: 0 = C, 1 = F, 2 = K, 3 = Rankine, 4 = Reaumur\n");
    printf("Enter Input Temperature Type: ");
    scanf("%d", &in_type);
    printf("Enter Temperature: ");
    scanf("%lf", &in_value);

    switch (in_type) {
        case 0:
            celsius = in_value;
            break;
        case 1: // F to C
            celsius = (in_value - 32) * 5 / 9;
            break;
        case 2: // K to C
            celsius = in_value - 273.15;
            break;
        case 3: // kine to C
            celsius = (in_value - 491.67) * 5 / 9;
            break;
        case 4: // Rea
            celsius = in_value * 1.25;
            break;
        default:
            printf("Invalid Type %d", in_type);
            return;
    }

    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = celsius + 273.15;
    rankine = (celsius * 9 / 5) + 491.67;
    reaumur = celsius / 1.25;

    printf("--------- Temperature Table ------------\n");
    printf("Celsius: %5.2lf\n", celsius);
    printf("Fahrenheit: %5.2lf\n", fahrenheit);
    printf("Kelvin: %5.2lf\n", kelvin);
    printf("Rankine: %5.2lf\n", rankine);
    printf("Reaumur: %5.2lf\n", reaumur);

}

// ----------------------------------------------------

int padovan_term(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1 || n == 2) return 1;
    return padovan_term(n - 2) + padovan_term(n - 3);
}

void padovan_gen_limit(int limit) {
    for (int i = 0; i < limit; i++) {
        printf("%d ", padovan_term(i));
    }
}

// ----------------------------------------------------

void volume_calc() {
    int choice;
    double length, width, height, radius, base, side, a, b, c;

    printf("Select the shape to calculate volume:\n");
    printf("1. Rectangular Solid or Cuboid\n");
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
            printf("Enter length, width, and height: ");
            scanf("%lf, %lf, %lf", &length, &width, &height);
            printf("Volume: %.2f\n", length * width * height);
            break;
        case 2: // Cube
            printf("Enter length of side: ");
            scanf("%lf", &side);
            printf("Volume: %.2f\n", pow(side, 3));
            break;
        case 3: // Cylinder
            printf("Enter radius and height: ");
            scanf("%lf, %lf", &radius, &height);
            printf("Volume: %.2f\n", PI * pow(radius, 2) * height);
            break;
        case 4: // Prism
            printf("Enter base area and height: ");
            scanf("%lf, %lf", &base, &height);
            printf("Volume: %.2f\n", base * height);
            break;
        case 5: // Sphere
            printf("Enter radius: ");
            scanf("%lf", &radius);
            printf("Volume: %.2f\n", (4.0 / 3.0) * PI * pow(radius, 3));
            break;
        case 6: // Pyramid
            printf("Enter base area and height: ");
            scanf("%lf, %lf", &base, &height);
            printf("Volume: %.2f\n", (1.0 / 3.0) * base * height);
            break;
        case 7: // Right Circular Cone
            printf("Enter radius and height: ");
            scanf("%lf, %lf", &radius, &height);
            printf("Volume: %.2f\n", (1.0 / 3.0) * PI * pow(radius, 2) * height);
            break;
        case 8: // Square or Rectangular Pyramid
            printf("Enter length, width, and height: ");
            scanf("%lf, %lf, %lf", &length, &width, &height);
            printf("Volume: %.2f\n", (1.0 / 3.0) * length * width * height);
            break;
        case 9: // Ellipsoid
            printf("Enter semi-axes a, b, and c: ");
            scanf("%lf, %lf, %lf", &a, &b, &c);
            printf("Volume: %.2f\n", (4.0 / 3.0) * PI * a * b * c);
            break;
        case 10: // Tetrahedron
            printf("Enter length of edge: ");
            scanf("%lf", &side);
            printf("Volume: %.2f\n", pow(side, 3) / (6 * sqrt(2)));
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// ----------------------------------------------------

double f(double x) {
    return x * x;
}

void derivative_at_x(double x) {
    double h = 0.01;
    double der = (f(x + h) - f(x - h)) / (2.0 * h);
    printf("The Derivative is %f\n", der);
}

void definite_integration_trapezoidal() {
    double ret;
    int lower = 0, upper = 4;
    ret = (upper - lower) * (f(lower) + f(upper)) / 2;
    printf("The Definite Integral is: %f\n", ret);
}

void definite_integral_simpson_3_8() {
    int intervals = 99999;
    double lower = 0, upper = 4;
    double h = (upper - lower) / intervals;
    double ret = f(lower) + f(lower + intervals * h);
    for (int i = 1; i < intervals; i++) {
        if (i % 3 == 0) {
            ret += 2 * f(lower + i * h);
        }
        else {
            ret += 3 * f(lower + i * h);
        }
    }
    ret *= (3.0 * h) / 8.0;
    printf("The Definite Integral is: %f", ret);
}

// ----------------------------------------------------

void polar_rectangle_converter() {
    /* Converts polar form to rectangular form and vice a versa.
     * Auto Detects whether the input is in polar or rectangular form.*/
    char input[100 + 1];
    double real, imag, angle, magnitude;
    char operator;
    int flag, type;
    printf("This program will auto detect the expression as rectangular or polar form and convert to polar and rectangular forms respectively. \nEnter Expression to convert: ");
    fgets(input, sizeof(input), stdin);

    flag = sscanf(input, "%lf %c j%lf", &real, &operator, &imag);
    flag |= sscanf(input, "%lf %c %lfj", &real, &operator, &imag);

    if (flag == 3 && (operator == '+' || operator == '-')) {
        // Rectangular form
        type = 0;
        magnitude = sqrt(pow(real, 2) + pow(imag, 2));
        angle = atan2(imag, real) * (180 / PI);
    } else if (sscanf(input, "%lf < %lf", &magnitude, &angle) == 2) {
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
        arr[x] = x * x;
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
        printf("%d %d\n", arr[i], i);
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
    int factor = num_digits == 1 ? 1 : num_digits;
    for (int i = 1; i <= limit; i++) {
        printf("%*s", num_digits * (limit - i), "");
        // Print the numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
            printf("%*s", num_digits - digits_in_num(i) + factor, "");
        }
        printf("\n");
    }
}

// ----------------------------------------------------

int armstrong(int num) {
    float sum = 0;
    float numf = num;
    int digits = digits_in_num(num);
    while (num != 0) {
        sum += pow(num % 10, digits);
        num /= 10;
    }
    return sum == numf;
}

// ----------------------------------------------------

int factorial_recursion_loop(int num, int recursion) {
    int factorial = 1;
    if (recursion) { // Use Recursive method
        if (num == 1 || num == 0) return 1;
        return num * factorial_recursion_loop(num - 1, 1);
    } else { // Use loops
        while (num != 1) {
            factorial *= num;
            num--;
        }
        return factorial;
    }
}

// ----------------------------------------------------

void quadratic_eqn_solver(double a, double b, double c) {
    double discriminant;
    double roots[2];
    int complex_roots = 0;
    discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant < 0) {
        discriminant *= -1;
        complex_roots = 1;
    }
    discriminant = pow(discriminant, 0.5);

    if (complex_roots == 1) {
        roots[0] = (-b / 2 * a); // Real Part
        roots[1] = discriminant / (2 * a); // Imaginary Part
        printf("The roots of the equation %fx^2 + %fx + %f are %f + %f i and %f - %f i",
               a, b, c, roots[0], roots[1], roots[0], roots[1]);
    } else {
        roots[0] = (-b + discriminant) / (2 * a);
        roots[1] = (-b - discriminant) / (2 * a);
        printf("The roots of the equation %fx^2 + %fx + %f are %f and %f", a, b, c, roots[0], roots[1]);
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

void print_matrix(float *matrix, int m, int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "┌ " : (i == n - 1 ? "└ " : "| "));
        for (int j = 0; j < m; j++) {
            printf("%20.2f ", matrix[i * m + j]);
        }
        printf(i == 0 ? "┐\n" : (i == n - 1 ? "┘\n" : "| \n"));
    }
}

void matrix_multiplication() {
    // Get input
    int max_order = 5;
    int n, p, m;
    // Get Matrix Orders
    printf("Enter matrix order n, p, m: ");
    scanf("%d, %d, %d", &n, &p, &m);
    // Verify Orders
    if ((n > max_order || p > max_order || m > max_order) && (n != 0 || p != 0 || m != 0)) {
        printf("Invalid Orders! The Maximum order is %d!", max_order);
        return;
    }
    float matrix1[n][p];
    float matrix2[p][m];
    float product_matrix[n][m];

    // Matrix Input
    // Matrix A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("A%d%d: ", i + 1, j + 1);
            scanf("%f", &(matrix1[i][j]));
        }
    }
    printf("Matrix A is:\n");
    print_matrix((float *) matrix1, p, n);
    // Matrix B
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < m; j++) {
            printf("B%d%d: ", i + 1, j + 1);
            scanf("%f", &(matrix2[i][j]));
        }
    }
    printf("Matrix B is:\n");
    print_matrix((float *) matrix2, p, m);

    // Calculate Product
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            product_matrix[i][j] = 0;
            for (int k = 0; k < p; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print Matrix
    printf("The Product Matrix (A x B) is:\n");
    print_matrix((float *) product_matrix, m, n);
}

// ----------------------------------------------------

int binary_to_decimal(int bin_num) {
    int decimal = 0;
    int place = 0;
    while (bin_num != 0) {
        decimal += (bin_num % 10) * pow(2, place);
        bin_num /= 10;
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
    unsigned long len = strlen(string) - 1;
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
    int a = 1103515245, c = 12345, m = (int) powl(2, 31), seed, roll;

    printf("Enter any number: ");
    scanf("%d", &seed);
    seed = random_int(seed, m, a, c);
    roll = seed % 6;
    if (roll < 0) roll *= -1;
    roll++;
    printf("The Dice rolled a %d", roll);
}

// ---------------------------------------------------

int turn_eval(int p1, int p2) {
    /*
     * Rock : 0 Paper : 1 Scissors: 2
     * 0 + 2 = 2 -> 0
     * 1 + 0 = 1 -> 1
     * 2 + 1 = 3 -> 2
     * */
    int sum = p1 + p2;
    int win_type;
    if (p1 == p2) { // Draw
        return -1;
    }
    switch (sum) {
        case 1:
            win_type = 1;
            break;
        case 2:
            win_type = 0;
            break;
        case 3:
            win_type = 2;
            break;
        default:
            win_type = -1;
            break;
    }
    if (win_type == -1) {
        return -1;
    }
    return win_type == p1 ? 1 : 2;
}

int eval_player_choice(const char input[]) {
    if (strstr(input, "r") != NULL || strstr(input, "rock") != NULL) {
        return 0;
    }
    if (strstr(input, "p") != NULL || strstr(input, "paper") != NULL) {
        return 1;
    }
    if (strstr(input, "s") != NULL || strstr(input, "scissors") != NULL) {
        return 2;
    }
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
    char player_name[100], p_choice_input[100];
    int a = 1103515245, c = 12345, m = (int) powl(2, 31), seed, best_of;
    int score_ai = 0, score_player = 0;
    int ai_choice, player_choice;
    // Input Game Options
    printf("Please Enter Your Name (Max 100 characters): ");
    scanf("%99s", player_name);
    printf("Score at which a player wins: ");
    scanf("%d", &best_of);

    // Calculate Seed
    seed = ((int) strlen(player_name)) * (best_of);

    // Play game
    while (score_player < best_of && score_ai < best_of) {
        printf("Enter Your Choice (Rock/Paper/Scissors): ");
        scanf("%99s", p_choice_input);
        player_choice = eval_player_choice(p_choice_input);
        if (player_choice == -1) {
            printf("Please Enter A Valid Move.\n");
            continue;
        }

        seed = random_int(seed, m, a, c);
        ai_choice = seed % 3;
        if (ai_choice < 0) {
            ai_choice *= -1;
        }
        printf("Computer Chose: ");
        print_choice_name(ai_choice);
        printf("\n");
        switch (turn_eval(player_choice, ai_choice)) {
            case 1:
                score_player++;
                printf("%s Won!\n", player_name);
                break;
            case 2:
                score_ai++;
                printf("Computer WON!\n");
                break;
            default:
                printf("Draw\n");
                break;
        }
    }

    // Display Results

    printf("The Scores are:\n Player: %d \tLCG: %d\n", score_player, score_ai);
    if (score_ai > score_player) {
        printf("Computer Won with %d point(s)!", score_ai);
    } else {
        printf("%s Won with %d point(s)!", player_name, score_player);
    }
}

// ----------------------------------------------------

int greatest_common_factor(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int gcf_array(int *nums) {
    int gcf = nums[0], size = sizeof(&nums) / sizeof(nums[0]);
    for (int i = 1; i < size; i++) {
        gcf = greatest_common_factor(gcf, nums[i]);
    }
    return gcf;
}

// ----------------------------------------------------

void fraction_representation(double decimal) {
    int numerator, denominator, whole, order = 7, diff;
    printf("Fractional Representation of %f is \n", decimal);
    denominator = pow(10, order);
    decimal *= denominator;
    numerator = (int) decimal;
    diff = greatest_common_factor(numerator, denominator);
    numerator /= diff;
    denominator /= diff;
    whole = numerator / denominator;
    numerator -= denominator * whole;
    printf("%*c %d\n", digits_in_num(whole) + 1, ' ', numerator);
    printf("%d %*c", whole, digits_in_num(whole), ' ');
    for (int i = 0; i < (digits_in_num(numerator) + digits_in_num(denominator)) / 2; i++) printf("-");
    printf("\n%*c %d", digits_in_num(whole) + 1, ' ', denominator);
}

// ----------------------------------------------------

#define BOARD_SIZE 4

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_board(int (*board)[BOARD_SIZE]) {
    clearScreen();
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

int evaluate_board(int (*board)[BOARD_SIZE]) {
    int hsum = 0, vsum = 0, dsum = 0, turn_eval;
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
            return -1; // Player 2 wins
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

int evaluate_action(int (*board)[BOARD_SIZE], int turn) {
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

const char *get_number_suffix(int num) {
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


int main() {
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
//   digits_in_num(num);

//   printf("%d\n", armstrong(93084));
//   printf("%d\n", factorial_recursion_loop(5, 0));
//    quadratic_eqn_solver(1, -4, 4);

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

//    fraction_representation(1.32);
//    tic_tac_toe();
//    day_from_date(17, 3, 2024);

//dice_roller();

//    temperature_conversion();
//    padovan_gen_limit(50);

//    volume_calc();

//    derivative_at_x(2);
//    definite_integration_trapezoidal();
//    definite_integral_simpson_3_8();

    return 0;
}
