#ifndef DELIVERY_H
#define DELIVERY_H

#define MAX_ORDERS 500
#define MAX_AGENTS 5
#define DELIVERY_CHARGE 30.0

struct Delivery
{
    int orderId;
    char customerName[50];
    char restaurantName[50];
    char items[200];
    float totalAmount;
    char deliveryAgent[50];
    char deliveryStatus[30];
};

// Global order array
extern struct Delivery orders[MAX_ORDERS];
extern int orderCount;

// Delivery functions
void addOrder();
void displayAllOrders();
void displayOrder(int index);
int findOrderById(int id);
void searchOrder();
void calculateAmount();
void updateStatus();
void displayPendingOrders();

#endif