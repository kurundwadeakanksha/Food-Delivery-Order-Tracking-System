#include <stdio.h>

#include "delivery.h"
#include "agent.h"
#include "restaurant.h"


int main()
{
    int choice;


    do
    {
        printf("\n\n");
        printf("============================================\n");
        printf("      FOOD DELIVERY ORDER TRACKING SYSTEM\n");
        printf("============================================\n");

        printf("1. Add New Order\n");
        printf("2. Display All Orders\n");
        printf("3. Assign Delivery Agents\n");
        printf("4. Calculate Final Amount\n");
        printf("5. Update Delivery Status\n");
        printf("6. Search Order by ID\n");
        printf("7. List Orders by Delivery Agent\n");
        printf("8. Find Restaurant with Highest Order Value\n");
        printf("9. Display Pending Orders\n");
        printf("10. Exit\n");

        printf("--------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
                addOrder();
                break;


            case 2:
                displayAllOrders();
                break;


            case 3:
                assignAgents();
                break;


            case 4:
                calculateAmount();
                break;


            case 5:
                updateStatus();
                break;


            case 6:
                searchOrder();
                break;


            case 7:
                ordersByAgent();
                break;


            case 8:
                findTopRestaurant();
                break;


            case 9:
                displayPendingOrders();
                break;


            case 10:
                printf("\nThank you!\n");
                break;


            default:
                printf("\nInvalid choice!\n");
        }


    } while (choice != 10);


    return 0;
}