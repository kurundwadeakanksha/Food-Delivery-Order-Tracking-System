**Food Delivery Order Tracking System**

A modular C-based Food Delivery Order Tracking System designed to manage food delivery orders across a city's delivery network.<br>

The system stores customer, restaurant, order, delivery agent, and delivery status information. It also supports automatic agent assignment, billing calculation, order searching, and restaurant-wise order analysis.

 **Project Overview**

The Food Delivery Order Tracking System uses C programming concepts such as:<br>

Structures<br>
Arrays<br>
Strings<br>
Functions<br>
Modular programming<br>
Searching<br>
Loops and conditional statements<br>
Arithmetic calculations<br>
Round-robin scheduling<br>

The project can store up to 500 food delivery orders using:<br>
struct Delivery orders[500];<br>

**Objectives**

The main objectives of this project are:<br>

Store and manage food delivery orders.<br>
Assign pending orders to delivery agents using round-robin scheduling.<br>
Calculate the platform fee and final payable amount.<br>
Track and update delivery status.<br>
Search orders using Order ID.<br>
Display all orders assigned to a particular delivery agent.<br>
Find the restaurant with the highest total order value.<br>

**Features**

1. Add New Order<br>

The system accepts:<br>

Order ID<br>
Customer name<br>
Restaurant name<br>
Items ordered<br>
Total food amount<br>

New orders are initially marked as: Pending<br>

2. Display All Orders<br>

Displays complete information about all stored orders, including:<br>

Customer<br>
Restaurant<br>
Items<br>
Food amount<br>
Platform fee<br>
Delivery charge<br>
Final amount<br>
Delivery agent<br>
Delivery status<br>
3. Round-Robin Agent Assignment<br>

Pending orders are automatically assigned to delivery agents in round-robin order.<br>

Example:<br>

Order 101 → Rahul<br>
Order 102 → Amit<br>
Order 103 → Sneha<br>
Order 104 → Priya<br>
Order 105 → Rohit<br>
Order 106 → Rahul<br>

The available agents are:<br>

Rahul<br>
Amit<br>
Sneha<br>
Priya<br>
Rohit<br>
4. Final Amount Calculation<br>

The system calculates:<br>

Platform Fee = 5% of Food Amount<br>

Final Amount =Food Amount + Platform Fee + ₹30 Delivery Charge<br>
Example<br>

For a food order of ₹500:<br>

Food Amount       = ₹500<br>
Platform Fee (5%) = ₹25<br>
Delivery Charge   = ₹30<br>
--------------------------------<br>
Final Amount      = ₹555<br>
5. Update Delivery Status<br>

The delivery status can be updated to:<br>

Pending<br>
Assigned<br>
Picked Up<br>
Out for Delivery<br>
Delivered<br>
Cancelled<br>
6. Search Order<br>

Users can search for a specific order using its Order ID.<br>

Example:<br>

Enter Order ID: 101<br>

The system displays the complete order details.<br>

7. Orders by Delivery Agent<br>

The system can display all orders assigned to a particular delivery agent.<br>

Example:<br>
Agent: Rahul<br>

Order 101 → Food Corner → Delivered<br>
Order 106 → Pizza Point → Out for Delivery<br>
8. Highest Order Value Restaurant<br>
The system calculates the total order value of each restaurant across all stored orders.<br>

Example:<br>

Food Corner  → ₹1100<br>
Pizza Point  → ₹1500<br>
Spice Hub    → ₹400<br>

The system identifies the restaurant with the highest total order value.<br>

 **Project Structure**
Food-Delivery-Order-Tracking-System/
│
├── main.c
│
├── delivery.c
├── delivery.h
│
├── agent.c
├── agent.h
│
├── restaurant.c
├── restaurant.h
│
└── README.md

 **System Workflow**
Start<br>
  ↓<br>
Main Menu<br>
  ↓<br>
Add Order<br>
  ↓<br>
Store Order<br>
  ↓<br>
Pending Order<br>
  ↓<br>
Assign Delivery Agent<br>
  ↓<br>
Round-Robin Assignment<br>
  ↓<br>
Calculate Final Amount<br>
  ↓<br>
Update Delivery Status<br>
  ↓<br>
Track / Search Order<br>
  ↓<br>
Analyze Restaurant Orders<br>
  ↓<br>
Exit<br>
**Technologies Used**
Programming Language: C<br>
Compiler: GCC / MinGW<br>
IDE: Visual Studio Code<br>
Version Control: Git<br>
Repository: GitHub<br>
**How to Run**
Step 1: Clone the repository<br>
git clone https://github.com/kurundwadeakanksha/Food-Delivery-Order-Tracking-System.git<br>
Step 2: Open the project folder<br>
cd Food-Delivery-Order-Tracking-System<br>
Step 3: Compile all C files<br>

Because this is a modular project, compile all .c files together:<br>

gcc main.c delivery.c agent.c restaurant.c -o food_delivery.exe<br>
Step 4: Run the program<br>

On Windows PowerShell:<br>

.\food_delivery.exe<br>
📋 Main Menu<br>
============================================<br>
      FOOD DELIVERY ORDER TRACKING SYSTEM<br>
============================================<br>
1. Add New Order<br>
2. Display All Orders<br>
3. Assign Delivery Agents<br>
4. Calculate Final Amount<br>
5. Update Delivery Status<br>
6. Search Order by ID<br>
7. List Orders by Delivery Agent<br>
8. Find Restaurant with Highest Order Value<br>
9. Display Pending Orders<br>
10. Exit<br>
🧠 C Concepts Used<br>

This project demonstrates the following C programming concepts:<br>

Structure<br>
struct Delivery<br>
Array of Structures<br>
struct Delivery orders[500];<br>
Character Arrays<br>

Used for:<br>

Customer Name<br>
Restaurant Name<br>
Items<br>
Delivery Agent<br>
Delivery Status<br>
Functions<br>

Different operations are separated into functions and files.<br>

String Handling<br>

Functions such as:<br>

strcmp()<br>
strcpy()<br>
strcspn()<br>

are used for string operations.<br>

Searching<br>

Order IDs and delivery agents are searched using loops.<br>

Round-Robin Scheduling<br>

Pending orders are distributed among delivery agents sequentially.<br>

Modular Programming<br>

The project is divided into multiple .c and .h files for better organization.<br>

Billing Formula<br>
Platform Fee = Total Amount × 5%<br>

Final Amount =Total Amount + Platform Fee + ₹30<br>
Delivery Agents<br>

The system currently uses five delivery agents:<br>

1. Rahul<br>
2. Amit<br>
3. Sneha<br>
4. Priya<br>
5. Rohit<br>

Orders are assigned using round-robin scheduling.<br>

**Future Enhancements**

The project can be extended with:<br>

File handling for permanent order storage<br>
Customer login<br>
Admin login<br>
Restaurant management<br>
More delivery agents<br>
Order cancellation and refund calculation<br>
Delivery time estimation<br>
Customer feedback and ratings<br>
Sorting orders by amount or status<br>
Database integration<br>
Graphical user interface<br>
