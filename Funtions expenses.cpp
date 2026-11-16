#include <stdio.h>
#include <string.h>

struct expense{
	int id;
	float amount;
	char category[50];
	char description[120];
	int date[30];
};

struct expense expense;
void addExpense (){
	printf("Enter Expense ID: ");
	scanf("%d", &expense.id);
	printf("Enter an amount: ");
	scanf("%f", &expense.amount);
	printf("Enter category: ");
	scanf("%s", expense.category);
	printf("Enter description: ");
	scanf("%s", expense.description);
	printf("Enter date: ");
	scanf("%s", expense.date);
	
	printf("Expense added successfully.");
}

int main (){
	addExpense();
	
	return 0;
}
