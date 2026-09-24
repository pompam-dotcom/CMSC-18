#include <stdio.h>

int main() {
    // Variables for the customer's grocery
    char product[100];
    int quantity;
    float price;
    float total = 0.0;
    int status;
    float discount = 0.0;

    printf("====== GROCERY NI MANG KANOR ======\n");

    // Ask for product details
    printf("Enter product name: ");
    scanf(" %99[^\n]", product);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    // Calculate grocery total
    total = quantity * price;

    printf("\n====== ORDER SUMMARY ======\n");
    printf("Product: %s\n", product);
    printf("Quantity: %d\n", quantity);
    printf("Total price: PHP %.2f\n", total);

    // Keep asking until a valid status is entered
    do {
        printf("\n====== CUSTOMER STATUS ======\n");
        printf("1. PWD\n");
        printf("2. Senior Citizen\n");
        printf("3. Pregnant\n");
        printf("4. None of the above\n");
        printf("Input your status (1-4): ");

        // Check if the user entered a number
        if (scanf("%d", &status) != 1) {
            printf("\nInvalid STATUS. Please enter a number from 1 to 4.\n");

            // Clear invalid input from the keyboard buffer
            while (getchar() != '\n');

            status = 0;
            continue;
        }

        if (status < 1 || status > 4) {
            printf("\nInvalid option. Please choose from 1 to 4.\n");
        }

    } while (status < 1 || status > 4);

    // Determine discount
    if (status == 1) {
        // PWD discount: 5%
        printf("\nCustomer status: PWD\n");
        discount = total * 0.05;

    } else if (status == 2) {
        // Senior Citizen discount: 20%
        printf("\nCustomer status: Senior Citizen\n");
        discount = total * 0.20;

    } else if (status == 3) {
        // Pregnant discount: 30
        printf("\nCustomer status: Pregnant\n");
        discount = total - 30;

    } else {
        // No discount
        printf("\nCustomer status: None of the above\n");
        discount = 0.0;
    }

    printf("Discount: PHP %.2f\n", discount);

    // Subtract discount from total
    total = total - discount;

    printf("Total amount to pay: PHP %.2f\n", total);
    printf("\nThank you for shopping with us!\n");

    return 0;
}