#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

// Function prototypes
void loadData();
void saveData();
void processOrder();
void generateReport();
void showInventory();

void saveData() {
    // Open files for writing
    FILE *productFile = fopen("products.txt", "w");
    FILE *orderFile = fopen("orders.txt", "w");

    // Check if files are opened successfully
    if (productFile == NULL || orderFile == NULL) {
        printf("\nError opening files for writing.\n");
        return;
    }

    // Write order data to the file
    for (int i = 0; i < orderCount; i++) {
        fprintf(orderFile, "%s %d %.2f\n", orders[i].username, orders[i].productCount, orders[i].totalAmount);

        // Write product details for each order
        for (int j = 0; j < orders[i].productCount; j++) {
            fprintf(orderFile, "%s %.2f %d\n", orders[i].products[j].name, orders[i].products[j].price, orders[i].products[j].quantity);
        }
    }
    // Write product data to the file
    for (int i = 0; i < productCount; i++) {
        fprintf(productFile, "%s %.2f %d\n", products[i].name, products[i].price, products[i].quantity);
    }

    // Close files
    fclose(productFile);
    fclose(orderFile);
}

void loadData() {
    // Open files for reading
    FILE *productFile = fopen("products.txt", "r");
    FILE *orderFile = fopen("orders.txt", "r");

    // Check if files are opened successfully
    if (productFile == NULL || orderFile == NULL) {
        printf("\nError opening files for reading. Starting with empty data.\n");
        return;
    }
        // Read order data from the file
        while (fscanf(orderFile, "%s %d %f", orders[orderCount].username, &orders[orderCount].productCount, &orders[orderCount].totalAmount) == 3) {
            // Read product details for each order
            for (int i = 0; i < orders[orderCount].productCount; i++) {
                fscanf(orderFile, "%s %f %d", orders[orderCount].products[i].name, &orders[orderCount].products[i].price, &orders[orderCount].products[i].quantity);
            }
            orderCount++;
        }

    // Read product data from the file
    while (fscanf(productFile, "%s %f %d", products[productCount].name, &products[productCount].price, &products[productCount].quantity) == 3) {
        productCount++;
    }

    // Close files
    fclose(productFile);
    fclose(orderFile);
}

void processOrder() {
    struct Order newOrder;

    printf("\nEnter your user-name: ");
    scanf("%s", newOrder.username);

    newOrder.productCount = 0;
    newOrder.totalAmount = 0;

    int continueAdding = 1;
    do {
        printf("\nEnter product name: ");
        scanf("%s", newOrder.products[newOrder.productCount].name);

        // Search for the product in the products array
        for (int i = 0; i < productCount; i++) {
            if (strcmp(newOrder.products[newOrder.productCount].name, products[i].name) == 0) {
                printf("Enter quantity for %s: ", newOrder.products[newOrder.productCount].name);
                scanf("%d", &newOrder.products[newOrder.productCount].quantity);

                // Check if there is enough quantity available
                if (newOrder.products[newOrder.productCount].quantity > products[i].quantity) {
                    printf("Insufficient quantity available. Order not processed.\n");
                    return;
                }
                // Update price for that product
                newOrder.products[newOrder.productCount].price = (newOrder.products[newOrder.productCount].quantity * products[i].price);
                // Update total amount for the order
                newOrder.totalAmount += (newOrder.products[newOrder.productCount].quantity * products[i].price);

                // Update product quantity in the products array
                products[i].quantity -= newOrder.products[newOrder.productCount].quantity;

                // Move to the next product in the order
                newOrder.productCount++;
                break;
            }
        }

        printf("\nDo you want to add another product to the order? (1 for Yes / 0 for No): ");
        scanf("%d", &continueAdding);
    } while (continueAdding);

    // Add the order to the orders array
    orders[orderCount] = newOrder;
    orderCount++;

    printf("\nOrder processed successfully. Total amount: $%.2f\n", newOrder.totalAmount);
}

void generateReport() {
    // Code for generating a report
    printf("\n************ E-Commerce Sales Report ************\n");
    printf("Order Count: %d\n", orderCount);

    for (int i = 0; i < orderCount; i++) {
        printf("\nOrder #%d\n", i + 1);
        printf("User-name: %s\n", orders[i].username);
        printf("Total Amount: $%.2f\n", orders[i].totalAmount);

        printf("\nProducts in the order:\n");
        for (int j = 0; j < orders[i].productCount; j++) {
            printf("%s - Quantity: %d - Price: %.2f\n", orders[i].products[j].name, orders[i].products[j].quantity, orders[i].products[j].price);
        }

        printf("\n-----------------------\n");
    }

    printf("\n*************************************************\n");
}

void showInventory() {
    printf("\n************ E-Commerce Inventory ************\n");
    printf("%-20s%-10s%-10s\n", "Product Name", "Price ($)", "Quantity");
    printf("------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        printf("%-20s%-10.2f%-10d\n", products[i].name, products[i].price, products[i].quantity);
    }

    printf("\n************************************************\n");
}
