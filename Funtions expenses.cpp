#include <stdio.h>
#include <string.h>

int id[100];
double amount[100];
char category[100][50];
char description[100][120];
char month[100][30];

int count=0;

void addExpense(){
    if(count>=100){
        printf("Expense limit reached! \n");
        return;
    }

    printf("Enter Expense ID: ");
    scanf("%d", &id[count]);

    printf("Enter amount: ");
    scanf("%lf", &amount[count]);

    printf("Enter category: ");
    scanf("%49s", category[count]);

    printf("Enter description: ");
    scanf(" %119[^\n]", description[count]);

    printf("Enter month name: ");
    scanf("%s", month[count]);

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
        printf("Amount: %lf\n", amount[i]);
        printf("Category: %s\n", category[i]);
        printf("Description: %s\n", description[i]);
        printf("Month: %s\n", month[i]);
    }
}

double calculateTotalExpenses(){
    int i;
    double total=0;

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
            printf("Amount: %lf\n", amount[i]);
            printf("Description: %s\n", description[i]);
            printf("Month: %s\n", month[i]);

            found=1;
        }
    }

    if(found==0){
        printf("No expense found in this category! \n");
    }
}

void searchByMonth(){
    int i,found=0;
    char searchMonth[20];

    printf("Enter month to search: ");
    scanf("%19s", searchMonth);

    for(i=0; i<count; i++){
        if(strcmp(month[i],searchMonth)==0){
        	printf("\n");
            printf("Expense ID: %d\n", id[i]);
            printf("Amount: %lf\n", amount[i]);
            printf("Category: %s\n", category[i]);
            printf("Description: %s\n", description[i]);

            found=1;
        }
    }

    if(found==0)
        printf("No expenses found for this month! \n");
    }
    
void saveExpenses(){
    int i;
    FILE *file;

    file=fopen("expenses.txt","w");

    if(file==NULL){
        printf("File could not be opened! \n");
        return;
    }

    for(i=0; i<count; i++){
        fprintf(file,"%d %.2f %s %s %s\n", id[i],amount[i],category[i],description[i],month[i]);
    }

    fclose(file);

    printf("Expenses saved successfully! \n");
}

void loadExpenses(){
    FILE *file;

    file=fopen("expenses.txt","r");

    if(file==NULL){
        printf("No saved expenses found! \n");
        return;
    }

    count=0;

    while(count<100 && fscanf(file,"%d %f %49s %119s %29s", &id[count],&amount[count],category[count],description[count],month[count])==5){
        count++;
    }

    fclose(file);

    printf("Expenses loaded successfully! \n");
}

