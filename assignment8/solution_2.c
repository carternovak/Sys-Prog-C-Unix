#include <stdio.h>
#include <string.h>
#define ITEMS 9

typedef struct  {
    char * item;
    char * itemID;
    float price;
    int quantity;
} VendingMach;

float balance = 0;
float sales = 0;
void insertItem(const char * items[], const char * itemIDs[], char * item, float price);
int insertMoney();
int checkBal();
int checkSales();
int checkPrice(VendingMach bob[], char * label);
int purchaseItem(VendingMach bob[], char * label);
int addNewItem(VendingMach bob[], char * iName, float iPrice);
int restock(VendingMach bob[], char * label);
int checkQuantity(VendingMach bob[], char * label);
int takeDownItem(VendingMach bob[], char * label);
int returnChange();
int exitMenu();
void menu(VendingMach bob[]);

int main() {
    VendingMach bob[ITEMS];
    const char * items[] = {"Coke", "Orange Soda", "Root Beer", "Water", "Grape Soda", "Coke Zero", "Cream Soda", "Lemonade", "Lime Soda"};
    const char * itemIDs[] = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
    
    // Initialize itemIDs
    for(int i = 0; i < ITEMS - 4; i++){
        bob[i].itemID = itemIDs[i];
        bob[i].item = items[i];
        bob[i].price = 2.00;
        bob[i].quantity = 5;
        printf("%s: %s\n", bob[i].itemID, bob[i].item);
    }
    for(int i = ITEMS - 4; i < ITEMS; i++){
        bob[i].itemID = itemIDs[i];
        bob[i].item = "";
        printf("%s: %s\n", bob[i].itemID, bob[i].item);
    }
    menu(bob);
    return 0;
}

void menu(VendingMach bob[]){
    int answer;
    int ownerAns;
    printf("[1] Insert money\n");
    printf("[2] Check balance\n");
    printf("[3] Check price\n");
    printf("[4] Purchase\n");
    printf("[5] Return change\n");
    printf("[6] Owner menu\n");
    printf("[7] Exit\n");
    printf("Please select an option: ");
    scanf("%d", &answer);
    while(answer != 8){
        if(answer == 1){
            insertMoney();
        }
        if (answer == 2)
            checkBal();
        if (answer == 3){
            char label;
            printf("Label: ");
            scanf("%s", &label);
            checkPrice(bob, &label);
        }
        if (answer == 4){
            char label;
            printf("Label: ");
            scanf("%s", &label);
            purchaseItem(bob, &label);
        }
        if (answer == 5)
            returnChange();
        if (answer == 6){
            printf("[1] Add a new type of item\n");
            printf("[2] Restock\n");
            printf("[3] Check quantity\n");
            printf("[4] Take down a type of item\n");
            printf("[5] Check total sales\n");
            printf("[6] Exit owner menu\n");
            printf("Please select an option: ");
            scanf("%d", &ownerAns);
            while(ownerAns != 7){
                if(ownerAns == 1){
                    char itemName[25];
                    float itemPrice;
                    printf("Item name: ");
                    scanf("%s", &itemName);
                    printf("Item price: ");
                    scanf("%f", &itemPrice);
                    addNewItem(bob, &itemName, itemPrice);
                }
                if(ownerAns == 2){
                    char label;
                    printf("Label: ");
                    scanf("%s", &label);
                    restock(bob, &label);
                }
                if(ownerAns == 3){
                    char label;
                    printf("Label: ");
                    scanf("%s", &label);
                    checkQuantity(bob, &label);
                }
                if(ownerAns == 4){
                    char label;
                    printf("Label: ");
                    scanf("%s", &label);
                    takeDownItem(bob, &label);
                }
                if(ownerAns == 5)
                    checkSales();
                if(ownerAns == 6)
                    menu(bob);
                if(ownerAns != 6){
                    printf("Please select an option: ");
                    scanf("%d", &ownerAns);
                }
            }
        }
        if(answer == 7) {
            exitMenu();
            answer = 8;
            break;
        }
        if(answer != 8){
            printf("Please select an option: ");
            scanf("%d", &answer);
        }
    }
    
}

int insertMoney(){
    float amount;
    printf("Amount: ");
    scanf("%f", &amount);
    balance += amount;
    return 0;
}

int checkBal(){
    printf("$%.2f\n", balance);
    return 0;
}

int checkPrice(VendingMach bob[], char * label){
    for(int i = 0; i < ITEMS; i++){
        if(strcmp(bob[i].itemID, label) == 0)
            printf("%s is $%.2f\n", bob[i].item, bob[i].price);
    }
    return 0;
}

int purchaseItem(VendingMach bob[], char * label){
    for(int i = 0; i < ITEMS; i++){
        if(strcmp(bob[i].itemID, label) == 0){
            printf("You purchase a %s for $%.2f\n", bob[i].item, bob[i].price);
            balance -= bob[i].price;
            bob[i].quantity -= 1;
            sales += bob[i].price;
        }
    }
    return 0;
}

int returnChange(){
    printf("$%.2f is returned\n", balance);
    balance = 0;
}

int addNewItem(VendingMach bob[], char * iName, float iPrice){
    for(int i = 0; i < ITEMS; i++){
        if(bob[i].item == ""){
            bob[i].item = iName;
            bob[i].price = iPrice;
            bob[i].quantity = 0;
            printf("%s is added to %s with price of $%.2f\n", bob[i].item, bob[i].itemID, iPrice);
            i = ITEMS;
        }
    }
}

int restock(VendingMach bob[], char * label){
    int itemAmt;
    for(int i = 0; i < ITEMS; i++){
        if(strcmp(bob[i].itemID, label) == 0){
            if(bob[i].item == "")
                printf("%s is empty\n", bob[i].itemID);
            else{
                printf("Quantity: ");
                scanf("%d", &itemAmt);
                bob[i].quantity = itemAmt;
                printf("%d %s is restocked\n", itemAmt, bob[i].item);
            }
        }
    }
}

int checkQuantity(VendingMach bob[], char * label){
    for(int i = 0; i < ITEMS; i++){
        if(strcmp(bob[i].itemID, label) == 0){
            if(bob[i].item == "")
                printf("%s is empty\n", bob[i].itemID);
            else
                printf("The stock of %s is %d\n", bob[i].item, bob[i].quantity);
        }
    }
}

int takeDownItem(VendingMach bob[], char * label){
    for(int i = 0; i < ITEMS; i++){
        if(strcmp(bob[i].itemID, label) == 0){
            if(bob[i].item == "")
                printf("%s is empty\n", bob[i].itemID);
            else{
                printf("%s is taken down\n", bob[i].item);
                bob[i].item = "";
            }
        }
    }
}

int checkSales(){
    printf("$%.2f\n", sales);
}

int exitMenu(){
    printf("Program exited\n");
    exit(0);
}


