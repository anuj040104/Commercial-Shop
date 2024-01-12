#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

// Function prototypes
void loadData();
void saveData();
void addProduct();
void updateQuantity();
void updateCost();
void showInventory();
void deleteProduct();

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

void addProduct() {
    products[productCount].id=productCount+1;
    printf("\nEnter product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter product price: ");
    scanf("%f", &products[productCount].price);
    printf("Enter initial quantity: ");
    scanf("%d", &products[productCount].quantity);
    productCount++;
    printf("Product added successfully.\n");
}

void updateQuantity() {
    char productName[50];
    int quantity;

    printf("\nEnter product name: ");
    scanf("%s", productName);
    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(productName, products[i].name) == 0) {
            products[i].quantity = quantity;
            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void updateCost() {
    char productName[50];
    int price;

    printf("\nEnter product name: ");
    scanf("%s", productName);
    printf("Enter new price: ");
    scanf("%d", &price);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(productName, products[i].name) == 0) {
            products[i].price = price;
            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
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

void deleteProduct()
{
    int productId, flag=0;
    int l=0;
    char name[100];
    printf("\nEnter Product Name to DELETE: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(name, products[i].name) == 0) {
            productId = products[i].id;
            flag = 1;
        }
    }

    if(flag)
    {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id != productId) {
                    newProducts[l] = products[i];
                    l++;
            }
        }
        for (int i = 0; i < productCount; i++) {
                products[i] = newProducts[i];
        }
        productCount = l;
        printf("\n\tItem Deleted successfully\n");
    }
    else
    {
        printf("\n Item NOT FOUND...");
    }
}
