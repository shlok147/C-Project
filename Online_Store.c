#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int orderNO = 101;
struct Order {
    int orderID;
    char customerName[50];
    char product[50];
    float price;
    char status[20];
    struct Order* next;
};

struct Order* front = NULL;
struct Order* rear = NULL;
struct Order* deliver = NULL;

void addOrder() {
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
    if (!newOrder) {
        printf("Memory allocation failed!\n");
        return;
    }

//    printf("Enter Order ID: ");
//    scanf("%d", &newOrder->orderID);
    newOrder->orderID=orderNO++;
	getchar();

    printf("Enter Customer Name: ");
    fgets(newOrder->customerName, 50, stdin);
    newOrder->customerName[strcspn(newOrder->customerName, "\n")] = '\0';

    printf("Enter Product Name: ");
    fgets(newOrder->product, 50, stdin);
    newOrder->product[strcspn(newOrder->product, "\n")] = '\0';

    printf("Enter Product Price: ");
    scanf("%f", &newOrder->price);
    getchar();

    strcpy(newOrder->status, "Pending");
    newOrder->next = NULL;

    if (front == NULL) {
        front = rear = deliver =newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }

    printf("Order %d added successfully!\n",orderNO-1);
	printf("------------------------\n");
}

void processOrder() {
    if (deliver == NULL) {
        printf("------------------------\n");
		printf("No orders to process.\n");
        printf("------------------------\n");
		return;
    }

    struct Order* processedOrder = deliver;
    printf("------------------------\n");
	printf("\nProcessing Order ID: %d\n", processedOrder->orderID);
    printf("Customer: %s\n", processedOrder->customerName);
    printf("Product: %s\n", processedOrder->product);
    printf("Price: %.2f\n", processedOrder->price);
    strcpy(processedOrder->status,"Processed");
    printf("Status: %s\n", processedOrder->status);
    printf("------------------------\n");
	deliver = deliver->next;

}

void displayOrders() {
    if (front == NULL) {
        printf("------------------------\n");
        printf("No orders.\n");
		printf("------------------------\n");
	    return;
    }

    struct Order* current = front;
    printf("------------------------\n");
//    printf("Pending Orders:\n");
    while (current != NULL) {
        printf("Order ID: %d\n", current->orderID);
        printf("Customer: %s\n", current->customerName);
        printf("Product: %s\n", current->product);
        printf("Price: %.2f\n", current->price);
        printf("Status: %s\n", current->status);
        printf("------------------------\n");
        current = current->next;
    }
}

void searchOrder() {
    int searchID;
    printf("Enter Order ID to search: ");
    scanf("%d", &searchID);

    struct Order* current = front;
    int found = 0;
    while (current != NULL) {
        if (current->orderID == searchID) {
            printf("------------------------\n");

            printf("Order ID: %d\n", current->orderID);
            printf("Customer: %s\n", current->customerName);
            printf("Product: %s\n", current->product);
            printf("Price: %.2f\n", current->price);
            printf("Status: %s\n", current->status);
            printf("------------------------\n");
			found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("------------------------\n");
        printf("Order with ID %d not found.\n", searchID);
    	printf("------------------------\n");
    }
}


void main() {
    int choice;

    while (1) {
        printf("\nOnline Store Order Management System\n");
        printf("0. Exit\n");
		printf("1. Add Order\n");
        printf("2. Process Order\n");
        printf("3. Display Orders\n");
        printf("4. Search Order\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thankyou Visit Again.\n");
                return ;
			case 1:
                addOrder();
                break;
            case 2:
                processOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                searchOrder();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

