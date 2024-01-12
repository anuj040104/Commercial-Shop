#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main() {
    loadData();
    int choice;
    int type;
    while (1) {
        printf("\n***** E-Commerce Application Menu *****\n");
        printf("1 - USER\n");
        printf("2 - SHOPKEEPER\n");
        printf("3 - EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &type);
        switch (type) {
            case 1:
                while(1) {
                printf("USER\n");
                printf("1. Order\n");
                printf("2. Generate Report\n");
                printf("3. Show All Products\n");
                printf("4. Exit\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    processOrder();
                    break;
                case 2:
                    generateReport();
                    break;
                case 3:
                    showInventory();
                    break;
                case 4:
                    saveData();
                    printf("\nExiting the application.\n");
                    exit(0);
                default:
                    printf("\nInvalid choice. Please try again.\n");
                }
                }
                break;
            case 2:
                while(1) {
                printf("SHOPKEEPER\n");
                printf("1. Add Product\n");
                printf("2. Update Product Quantity\n");
                printf("3. Update Product Cost\n");
                printf("4. Delete Product\n");
                printf("5. Show All Products\n");
                printf("6. Exit\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    addProduct();
                    break;
                case 2:
                    updateQuantity();
                    break;
                case 3:
                    updateCost();
                    break;
                case 4:
                    deleteProduct();
                    break;
                case 5:
                    showInventory();
                    break;
                case 6:
                    saveData();
                    printf("\nExiting the application.\n");
                    exit(0);
                default:
                    printf("\nInvalid choice. Please try again.\n");
                }
                }
                break;
            case 3:
                saveData();
                printf("\nExiting the application.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
