#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX_ENTRIES 100
	char userName[50];
	char incomeSource[MAX_ENTRIES][50];
	double incomeAmount[MAX_ENTRIES];
	int incomeCount=0;
	double budget=0;
	char incomeFile[]="income.txt";
	char budgetFile[]="budget.txt";
	

void addUser(){
	printf("Enter user name: ");
	scanf(" %49[^\n]", userName);
	printf("\n");
	printf("User %s is registered successfully! \n", userName);
}

void addIncome(){
	if(incomeCount>=100){
		printf("\nIncome limit reached!");
		return;
	}
	printf("\nEnter income source(e.g:Salary or Buisness): ");
	if(scanf("%49s", incomeSource[incomeCount]) != 1){
		printf("\nInvalid Source!!\n");
		int c;
		while((c = getchar()) != '\n' && c != EOF){}
		return;
	}
	printf("\nEnter income amount: ");
	if(scanf("%lf", &incomeAmount[incomeCount]) !=1){
		printf("\nInvalid!\n");
		int c;
		while((c = getchar()) != '\n' && c!=EOF){}
		return;
	}
	incomeCount++;
	printf("\n");
	printf("Income record added successfully! ");
}

void saveIncome(){
	FILE *file = fopen(incomeFile,"w");
	if(file == NULL){
		printf("\nError Opening Income File! \n");
		return;
	}
	fprintf(file, "%d\n", incomeCount);
	for(int i=0; i<incomeCount; i++){
		fprintf(file, "%s %lf\n", incomeSource[i], incomeAmount[i]);
	}
		fclose(file);
		printf("\nIncome Data Saved to Income File Successfully! ");
}

void loadIncome(){
	FILE *file = fopen(incomeFile,"r");
	if(file == NULL){
		printf("\nNo Saved Income File Found!! \n");
		return;
	}
	if(fscanf(file, "%d", &incomeCount) !=1){
		incomeCount = 0;
		fclose(file);
		printf("\nIncome file is empty.\n");
		return;
	}
	if(incomeCount < 0){
		incomeCount = 0;
	}
	if(incomeCount>100){
		incomeCount = 100;
	}
	for(int i=0; i<incomeCount; i++){
		if(fscanf(file, "%49s %lf", incomeSource[i], &incomeAmount[i]) !=2){
			incomeCount = i;
			break;
		}
		printf("\nLoaded Income -> Source: %s, Amount: $%.2f\n", incomeSource[i],incomeAmount[i]);
}
	fclose(file);
}

void setBudget(){
	printf("\n");
	printf("Enter monthly budget limit: ");
	if(scanf("%lf", &budget) !=1){
		printf("\nInvalid budget amount!!\n");
		int c;
		while((c=getchar()) !='\n' && c!= EOF){}
		return;
	}
	printf("\nMonthly budget successfully set to $%.2f", budget);
}

void saveBudget(){
	FILE *file = fopen(budgetFile,"w");
	if(file == NULL){
	    printf("\nError Opening Budget File for Writing.\n");
		return;
}
	fprintf(file,"%lf",budget);
	fclose(file);
	printf("\nBudget Information saved to file successfully!! \n");
}

void loadBudget(){
	FILE *file = fopen(budgetFile,"r");
	if(file == NULL){
		printf("\nNo saved budget file found.\n");
		return;
	}
	if(fscanf(file,"%lf", &budget) != 1){
		budget = 0;
		fclose(file);
		printf("\nBudget file is empty.\n");
		return;
	}
	fclose(file);
	printf("\nLoaded Monthly Budget: $%.2f\n", budget);
}

double calculateTotalIncome(){
	double totalIncome = 0;
	for(int i=0; i<incomeCount; i++){
		totalIncome+=incomeAmount[i];
	}
	return totalIncome;
}

void calculateBalance(){
	double totalIncome = calculateTotalIncome();
	double totalExpensesSum = calculateTotalExpenses();
	double balance = totalIncome - totalExpensesSum;
	
	printf("\nTotal Income: $%.2f", totalIncome);
	printf("\nTotal Expenses: $%.2f", totalExpensesSum);
	printf("\nRemaining Balance: $%.2f", balance);
}

void generateReport(){
	double totalIncome = calculateTotalIncome();
	double totalExpensesSum = calculateTotalExpenses();
	double balance = totalIncome - totalExpensesSum;
	
	printf("\n----- FINANCIAL SUMMARY -----\n");
	printf("User: %s\n", userName);
	printf("\nIncome Source:\n");
	for(int i=0; i<incomeCount; i++){
		printf(" -%s: %.2f\n", incomeSource[i], incomeAmount[i]);
	}
	printf("\nTotal Income: $%.2f",totalIncome);
	printf("\nTotal Expenses: $%.2f",totalExpensesSum);
	printf("\nMonthly Budget: $%.2f", budget);
	printf("\nBalance: $%.2f",balance);
	printf("\n--------------------------------------\n");
}

void checkBudgetAlert(){
	printf("\nChecking Budget Status...\n");
	if(budget == 0.0){
		printf("Budget has not been set! \n");
		return;
	}
	double totalExpensesSum = calculateTotalExpenses();
	
	if(totalExpensesSum>=budget){
		printf("\nWARNING: YOU HAVE REACHED YOUR BUDGET LIMIT OF %.2f!(Current Expenses = %.2f)\n", budget, totalExpensesSum);
	}
	else{
		printf("STATUS: You are within your budget. Remaining budget = $%.2f.", budget - totalExpensesSum);
	}
}
