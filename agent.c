#include <stdio.h>
#include <string.h>

#include "agent.h"
#include "delivery.h"


// Delivery agent list
char agents[MAX_AGENTS][50] =
{
    "Rahul",
    "Amit",
    "Sneha",
    "Priya",
    "Rohit"
};


// Index of next agent
int nextAgent = 0;


// Assign agents using Round-Robin
void assignAgents()
{
    int i;
    int assigned = 0;

    if (orderCount == 0)
    {
        printf("\nNo orders available.\n");
        return;
    }

    printf("\n------- AGENT ASSIGNMENT -------\n");

    for (i = 0; i < orderCount; i++)
    {
        if (strcmp(
            orders[i].deliveryStatus,
            "Pending"
        ) == 0)
        {
            strcpy(
                orders[i].deliveryAgent,
                agents[nextAgent]
            );

            printf(
                "Order %d -> %s\n",
                orders[i].orderId,
                orders[i].deliveryAgent
            );

            strcpy(
                orders[i].deliveryStatus,
                "Assigned"
            );

            nextAgent =
                (nextAgent + 1) % MAX_AGENTS;

            assigned++;
        }
    }

    if (assigned == 0)
    {
        printf("No pending orders found.\n");
    }
    else
    {
        printf("\nAgents assigned successfully!\n");
    }
}


// Display orders of a particular agent
void ordersByAgent()
{
    char agentName[50];
    int i;
    int found = 0;

    getchar();

    printf("\n-------- ORDERS BY AGENT --------\n");

    printf("Enter Agent Name: ");

    fgets(agentName, 50, stdin);

    agentName[
        strcspn(agentName, "\n")
    ] = '\0';

    printf("\nOrders assigned to %s:\n",
           agentName);

    for (i = 0; i < orderCount; i++)
    {
        if (strcmp(
            orders[i].deliveryAgent,
            agentName
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

            printf("\nStatus     : %s\n",
                   orders[i].deliveryStatus);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo orders found for this agent.\n");
    }
}