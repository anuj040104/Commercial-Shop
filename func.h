#ifndef FUNC_H
#define FUNC_H
void loadData();
void saveData();
void addProduct();
void updateQuantity();
void updateCost();
void processOrder();
void generateReport();
void showInventory();
void deleteProduct();

// Structure for storing product details
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Structure for storing order details
struct Order {
    char username[50];
    struct Product products[100];
    int productCount;
    float totalAmount;
};

// Global variables
struct Product products[100];
struct Product newProducts[100];
int productCount;

struct Order orders[100];
int orderCount;
#endif
