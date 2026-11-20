#include<stdio.h>
#include<stdlib.h>
	
	char userName[50];
	char incomeSource[100][50];
	double incomeAmount[100];
	int incomeCount=0;
	double budget=0;
	char incomeFile[]="income.txt";
	char  budgetFile[]="budget.txt";
	

void addUser(){
	printf("Enter user name: ");
	scanf("%[^\n]", userName);
	printf("\n");
	printf("User %s is registered successfully! \n", userName);
}

void addIncome(){
	printf("\nEnter income source(e.g:Salary or Buisness): ");
	scanf("%s", incomeSource[incomeCount]);
	printf("\n");
	printf("Enter income amount: ");
	scanf("%lf", &incomeAmount[incomeCount]);
	printf("\n");
	printf("Income record added successfully! ");
}

void saveIncome(){
	FILE *file = fopen(incomeFile,"w");
	if(file==NULL){
		printf("\nError Opening Income File! \n");
	return;
	}
	fprintf(file, "%d\n", incomeCount);
	for(int i=0; i<incomeCount; i++){
		fprintf(\nfile, "%s %lf", incomeSource[i], incomeAmount[i]);
	}
		fclose(file);
		printf("\nIncome Data Saved to Income File Successfully! ");
}

void loadIncome(){
	FILE *file = fopen(incomeFile,"r");
	if(file==NULL){
		printf("\nNo Saved Income File Found!! \n");
		return;
	}
	fscanf(file, "%d\n", &incomeCount);
	for(int i=0; i<incomeCount; i++){
		fscanf(file, "%s %lf", incomeSource[i], &incomeAmount[i]);
		printf("\nLoaded Income -> Source: %s, Amount: $%lf\n", incomeSource[i],incomeAmount[i]);
}
	fclose(file);
}

void setBudget(){
	printf("\n");
	printf("Enter monthly budget limit: ");
	scanf("%lf", &budget);
	printf("\nMonthly budget successfully set to $%lf", budget);
}

void saveBudget(){
	FILE *file = fopen(budgetFile,"w");
	if(file==NULL){
	    printf("\nError Opening Budget File for Writing.\n"):
		return;
}
	fprintf(file,"%lf\n",budget);
	fclose(file);
	printf("Budget Information saved to file successfully!! \n");
}

void loadBudget(){
	FILE *file = fopen(budgetFile,"r");
	if(file==NULL){
		printf("\nNo saved budget file found.\n");
	return;
	}
	fscanf(file,"%lf", &budget);
	fclose(file);
	printf("\nLoaded Monthly Budget: $%lf\n", budget);
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

	double totalExpensesSum = 0;
	for(int i=0; i<count; i++){
		totalExpensesSum += totalExpenses[i];
	}
	double balance = totalIncome - totalExpensesSum;
	printf("\nTotal Income: $%lf", totalIncome);
	printf("\nTotal Expenses: $%lf", totalExpensesSum);
	printf("\nRemaining Balance: $%lf", balance);
}

void generateReport(){
	double totalIncome = calculateTotalIncome();
	
	double totalExpensesSum = 0;
	for(int i=0; i<count; i++){
		totalExpensesSum += totalExpenses[i];
	}
	double balance = totalIncome - totalExpensesSum;
	
	printf("\n----- FINANCIAL SUMMARY -----\n");
	printf("User: %[^\n]", userName);
	printf("\nIncome Source:\n");
	for(int i=0; i<incomeCount; i++){
		printf(" -%s: %lf\n", incomeSource[i], incomeAmount[i]);
	}
	printf("\nTotal Income: $%lf",totalIncome);
	printf("\nTotal Expenses: $%lf",totalExpensesSum);
	printf("\nMonthly Budget: $%lf", budget);
	printf("\nBalance: $%lf",balance);
	printf("\n--------------------------------------\n");
}

void checkBudgetAlert(){
	printf("\nChecking Budget Status...\n");
	if(budget==0.0){
		printf("Budget has not been set! \n");
	return;
	}
	double totalIncome = calculateTotalIncome();
	double totalExpensesSum = 0;
	for(int i=0; i<count; i++){
		totalExpensesSum += totalExpenses[i];
	}
	if(totalExpensesSum>=budget){
		printf("\nWARNING: YOU HAVE REACHED YOUR BUDGET LIMIT OF %lf!(Current Expenses = %lf)\n", budget, totalExpensesSum);
	}
	else{
		printf("STATUS: You are within your budget. Remaining budget = $%lf.", budget - totalExpensesSum);
	}
}





