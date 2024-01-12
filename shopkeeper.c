#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

// Function prototypes
void addProduct();
void updateQuantity();
void updateCost();
void deleteProduct();

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
