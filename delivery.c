#include <stdio.h>
#include <string.h>
#include "delivery.h"

struct Delivery orders[MAX_ORDERS];
int orderCount = 0;


// Find order by ID
int findOrderById(int id)
{
    int i;

    for (i = 0; i < orderCount; i++)
    {
        if (orders[i].orderId == id)
        {
            return i;
        }
    }

    return -1;
}


// Add new order
void addOrder()
{
    if (orderCount >= MAX_ORDERS)
    {
        printf("\nMaximum order limit reached!\n");
        return;
    }

    printf("\n========== ADD NEW ORDER ==========\n");

    printf("Enter Order ID: ");
    scanf("%d", &orders[orderCount].orderId);

    if (findOrderById(orders[orderCount].orderId) != -1)
    {
        printf("Order ID already exists!\n");
        return;
    }

    getchar();

    printf("Enter Customer Name: ");
    fgets(orders[orderCount].customerName, 50, stdin);
    orders[orderCount].customerName[
        strcspn(orders[orderCount].customerName, "\n")
    ] = '\0';

    printf("Enter Restaurant Name: ");
    fgets(orders[orderCount].restaurantName, 50, stdin);
    orders[orderCount].restaurantName[
        strcspn(orders[orderCount].restaurantName, "\n")
    ] = '\0';

    printf("Enter Items Ordered: ");
    fgets(orders[orderCount].items, 200, stdin);
    orders[orderCount].items[
        strcspn(orders[orderCount].items, "\n")
    ] = '\0';

    printf("Enter Total Amount: Rs. ");
    scanf("%f", &orders[orderCount].totalAmount);

    strcpy(orders[orderCount].deliveryAgent, "Not Assigned");
    strcpy(orders[orderCount].deliveryStatus, "Pending");

    orderCount++;

    printf("\nOrder added successfully!\n");
}


// Display one order
void displayOrder(int index)
{
    float platformFee;
    float finalAmount;

    platformFee = orders[index].totalAmount * 0.05;

    finalAmount =
        orders[index].totalAmount
        + platformFee
        + DELIVERY_CHARGE;

    printf("\n----------------------------------------\n");

    printf("Order ID        : %d\n",
           orders[index].orderId);

    printf("Customer        : %s\n",
           orders[index].customerName);

    printf("Restaurant      : %s\n",
           orders[index].restaurantName);

    printf("Items           : %s\n",
           orders[index].items);

    printf("Food Amount     : Rs. %.2f\n",
           orders[index].totalAmount);

    printf("Platform Fee    : Rs. %.2f\n",
           platformFee);

    printf("Delivery Charge : Rs. %.2f\n",
           DELIVERY_CHARGE);

    printf("Final Amount    : Rs. %.2f\n",
           finalAmount);

    printf("Agent           : %s\n",
           orders[index].deliveryAgent);

    printf("Status          : %s\n",
           orders[index].deliveryStatus);

    printf("----------------------------------------\n");
}


// Display all orders
void displayAllOrders()
{
    int i;

    if (orderCount == 0)
    {
        printf("\nNo orders available.\n");
        return;
    }

    printf("\n========== ALL ORDERS ==========\n");

    for (i = 0; i < orderCount; i++)
    {
        displayOrder(i);
    }
}


// Search order
void searchOrder()
{
    int id;
    int index;

    printf("\n========== SEARCH ORDER ==========\n");

    printf("Enter Order ID: ");
    scanf("%d", &id);

    index = findOrderById(id);

    if (index == -1)
    {
        printf("\nOrder not found!\n");
    }
    else
    {
        displayOrder(index);
    }
}


// Calculate final amount
void calculateAmount()
{
    int id;
    int index;
    float platformFee;
    float finalAmount;

    printf("\n========== FINAL AMOUNT ==========\n");

    printf("Enter Order ID: ");
    scanf("%d", &id);

    index = findOrderById(id);

    if (index == -1)
    {
        printf("\nOrder not found!\n");
        return;
    }

    platformFee =
        orders[index].totalAmount * 0.05;

    finalAmount =
        orders[index].totalAmount
        + platformFee
        + DELIVERY_CHARGE;

    printf("\nFood Amount     : Rs. %.2f",
           orders[index].totalAmount);

    printf("\nPlatform Fee    : Rs. %.2f",
           platformFee);

    printf("\nDelivery Charge : Rs. %.2f",
           DELIVERY_CHARGE);

    printf("\n--------------------------------");

    printf("\nFinal Amount    : Rs. %.2f\n",
           finalAmount);
}


// Update delivery status
void updateStatus()
{
    int id;
    int index;
    int choice;

    printf("\n========== UPDATE STATUS ==========\n");

    printf("Enter Order ID: ");
    scanf("%d", &id);

    index = findOrderById(id);

    if (index == -1)
    {
        printf("Order not found!\n");
        return;
    }

    printf("\nCurrent Status: %s\n",
           orders[index].deliveryStatus);

    printf("\n1. Pending");
    printf("\n2. Assigned");
    printf("\n3. Picked Up");
    printf("\n4. Out for Delivery");
    printf("\n5. Delivered");
    printf("\n6. Cancelled");

    printf("\nEnter new status: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            strcpy(orders[index].deliveryStatus,
                   "Pending");
            break;

        case 2:
            strcpy(orders[index].deliveryStatus,
                   "Assigned");
            break;

        case 3:
            strcpy(orders[index].deliveryStatus,
                   "Picked Up");
            break;

        case 4:
            strcpy(orders[index].deliveryStatus,
                   "Out for Delivery");
            break;

        case 5:
            strcpy(orders[index].deliveryStatus,
                   "Delivered");
            break;

        case 6:
            strcpy(orders[index].deliveryStatus,
                   "Cancelled");
            break;

        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("\nStatus updated successfully!\n");
}


// Display pending orders
void displayPendingOrders()
{
    int i;
    int found = 0;

    printf("\n========== PENDING ORDERS ==========\n");

    for (i = 0; i < orderCount; i++)
    {
        if (strcmp(
            orders[i].deliveryStatus,
            "Pending"
        ) == 0)
        {
            printf("\nOrder ID   : %d",
                   orders[i].orderId);

            printf("\nCustomer   : %s",
                   orders[i].customerName);

            printf("\nRestaurant : %s",
                   orders[i].restaurantName);

            printf("\nAmount     : Rs. %.2f",
                   orders[i].totalAmount);

            printf("\nAgent      : %s\n",
                   orders[i].deliveryAgent);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo pending orders.\n");
    }
}