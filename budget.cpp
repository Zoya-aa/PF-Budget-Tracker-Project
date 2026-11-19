#include<stdio.h>
#include<stdlib.h>
	
	char userName[50];
	char incomeSource[50];
	float incomeAmount;
	int incomeCount = 0;
	float budget  = 0;
	char incomeFile[]="income.txt";
	char  budgetFile[]="budget.txt";
	

void addUser(){
	printf("Enter user name:");
	scanf("%[^\n]", userName);
	printf("\nUser %s is registered successfully!\n", userName);
}

void addIncome(){
	printf("\nEnter income source(e.g:Salary or Buisness):");
	scanf("%s", incomeSource);
	printf("\nEnter income amount:");
	scanf("%lf", &incomeAmount);
	printf("\nIncome record added successfully!");
}

void saveIncome(){
	FILE *file = fopen("income.txt","w");
	if(file==NULL){
	printf("\nError Opening Income File!\n");
	return;
	}
	fprintf(file, "%s %.2f\n", incomeSource, incomeAmount);
	fclose(file);
	printf("\nIncome Data Saved to Income File Successfully!");
}

void loadIncome(){
	FILE *file = fopen("income.txt","r");
	if(file==NULL){
		printf("\nNo Saved Income File Found!!\n");
		return;
	}
	fscanf(file, "%s %lf", incomeSource, &incomeAmount);
	fclose(file);
	printf("\nLoaded Income -> Source: %s, Amount: $%.2f\n",incomeSource, incomeAmount);
}

void setBudget(){
	printf("\nEnter monthly budget limit:");
	scanf("%lf", &budget);
	printf("\nMonthly budget successfully set to $%lf",budget);
}

void saveBudget(){
	FILE *file = fopen("budget.txt","w");
if(file==NULL){
printf("\nError Opening Budget File for Writing.\n"):
	retrun;
}
fprintf("file,"%lf",budget);
fclose(file);
printf("Budget Information saved to file successfully!!\n");
}



