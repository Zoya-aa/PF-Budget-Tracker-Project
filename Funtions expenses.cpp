#include <stdio.h>
#include <string.h>

int id[100];
float amount[100];
char category[100][50];
char description[100][120];
char date[100][30];

int count=0;

void addExpense(){
    if(count>=100){
        printf("Expense limit reached! \n");
        return;
    }

    printf("Enter Expense ID: ");
    scanf("%d", &id[count]);

    printf("Enter amount: ");
    scanf("%f", &amount[count]);

    printf("Enter category: ");
    scanf("%49s", category[count]);

    printf("Enter description: ");
    scanf(" %119[^\n]", description[count]);

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%29s", date[count]);

    count++;

    printf("\n");
    printf("Expense added successfully!\n");
}

void viewExpenses(){
    int i;

    if(count==0){
        printf("No expenses found! \n");
        return;
    }

    for(i=0; i<count; i++){
    	printf("\n");
        printf("Expense ID: %d\n", id[i]);
        printf("Amount: %.2f\n", amount[i]);
        printf("Category: %s\n", category[i]);
        printf("Description: %s\n", description[i]);
        printf("Date: %s\n", date[i]);
    }
}

float calculateTotalExpenses(){
    int i;
    float total=0;

    for(i=0; i<count; i++){
        total=total+amount[i];
    }

    return total;
}

void searchByCategory(){
    int i,found=0;
    char searchCategory[50];

    printf("Enter category to search: ");
    scanf("%49s", searchCategory);

    for(i=0; i<count; i++){
        if(strcmp(category[i],searchCategory)==0){
        	printf("\n");
            printf("Expense ID: %d\n", id[i]);
            printf("Amount: %.2f\n", amount[i]);
            printf("Description: %s\n", description[i]);
            printf("Date: %s\n", date[i]);

            found=1;
        }
    }

    if(found==0){
        printf("No expense found in this category! \n");
    }
}


