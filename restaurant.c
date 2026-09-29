#include <stdio.h>
#include <string.h>

#include "restaurant.h"
#include "delivery.h"


void findTopRestaurant()
{
    char restaurantNames[MAX_ORDERS][50];
    float restaurantTotals[MAX_ORDERS];

    int restaurantCount = 0;

    int i;
    int j;
    int found;
    int maxIndex;


    if (orderCount == 0)
    {
        printf("\nNo orders available.\n");
        return;
    }


    // Initialize totals
    for (i = 0; i < MAX_ORDERS; i++)
    {
        restaurantTotals[i] = 0;
    }


    // Process every order
    for (i = 0; i < orderCount; i++)
    {
        found = -1;


        // Check whether restaurant already exists
        for (j = 0; j < restaurantCount; j++)
        {
            if (strcmp(
                restaurantNames[j],
                orders[i].restaurantName
            ) == 0)
            {
                found = j;
                break;
            }
        }


        // Existing restaurant
        if (found != -1)
        {
            restaurantTotals[found]
                += orders[i].totalAmount;
        }


        // New restaurant
        else
        {
            strcpy(
                restaurantNames[restaurantCount],
                orders[i].restaurantName
            );

            restaurantTotals[restaurantCount]
                = orders[i].totalAmount;

            restaurantCount++;
        }
    }


    // Find maximum total
    maxIndex = 0;

    for (i = 1; i < restaurantCount; i++)
    {
        if (restaurantTotals[i]
            > restaurantTotals[maxIndex])
        {
            maxIndex = i;
        }
    }


    printf("\n========== TOP RESTAURANT ==========\n");

    printf("Restaurant Name   : %s\n",
           restaurantNames[maxIndex]);

    printf("Total Order Value : Rs. %.2f\n",
           restaurantTotals[maxIndex]);
}