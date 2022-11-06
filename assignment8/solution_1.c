#include <stdio.h>
#include <string.h>
#define SIZE 3

typedef struct {
    char street[50];
    char city[50];
    char state[10];
    char zip[10];
} Address;

typedef struct {
    char name[25];
    double price;
} Product;

typedef struct {
    Product prod;
    int quantity;
} Items;

typedef struct {
    Items * items;
    Address address;
} Invoice;

Address createAddress(char * street, char * city, char * state, char * zip);
Product createProducts(char * name, double price);
Items createLineItem(Product prod, int quantity);
Invoice createInvoice(Items * items, Address Address);
void printInvoice(Invoice invoice);

int main(){
    
    Product product1 = createProducts("Toaster", 29.95);
    Product product2 = createProducts("Hair Dryer", 24.95);
    Product product3 = createProducts("Car Vacuum", 19.99);
    Items items[SIZE];

    items[0] = createLineItem(product1, 3);
    items[1] = createLineItem(product2, 1);
    items[2] = createLineItem(product3, 2);

    Address address = createAddress("100 Main Street", "Anytown", "CA", "98765");
    Invoice invoice = createInvoice(items, address);
    
    printInvoice(invoice);

    return 0;
}

Address createAddress(char * street, char * city, char * state, char * zip){
    Address inv;
    strcpy(inv.street, street);
    strcpy(inv.city, city);
    strcpy(inv.state, state);
    strcpy(inv.zip, zip);
    return inv;
}

Product createProducts(char * name, double price){
    Product inv;
    strcpy(inv.name, name);
    inv.price = price;
    return inv;
}

Items createLineItem(Product prod, int quantity){
    Items inv;
    inv.prod = prod;
    inv.quantity = quantity;
    return inv;
}

Invoice createInvoice(Items * items, Address Address){
    Invoice inv;  
    inv.items = items;
    inv.address = Address;
    return inv;
}

void printInvoice(Invoice invoice){

    printf("%17sI N V O I C E\n","");
    printf("\nSam's Small Appliances");
    printf("\n%s", invoice.address.street);
    printf("\n%s, %s %s\n\n", invoice.address.city, invoice.address.state, invoice.address.zip);
    printf("\nDesctiption \t\t%s", "Price Qty Total");

    double result = 0;

    for(int i = 0; i < SIZE; i++){
        double invPrice = invoice.items[i].prod.price;
        int invQty = invoice.items[i].quantity;
        double total = invPrice * invQty;

        printf("\n%s \t%7s %0.2f  %d  %0.2f", invoice.items[i].prod.name, "", invPrice, invQty, total);

        result += total;
    }

    printf("\n\nAMOUNT DUE:  $%0.2f", result);
}


