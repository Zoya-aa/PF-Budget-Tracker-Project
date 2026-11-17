#include<stdio.h>
#include<string.h>


char user_Name[50];
char income_Source[50];
float total_Income = 0.0;
float monthly_Budget = 0.0;

void manageIncome(){
	printf("\n------- Manage Income and User Information ------\n ");
	printf("Enter user name:");
	scanf("%[^\n]", user_Name);

	printf("Enter income source:");
	scanf("%[^\n]", income_Source);
	
	printf("Enter monthly income:");
	scanf("%f", &total_Income);
	
	printf("User and Income Information stored successfully.");
}

void setBudget(){
	printf("\n---- Set Monthly Budget ----\n");
	printf("Enter your monthly spending limit:");
	scanf("%f", &monthly_Budget);
	printf("Monthly Budget set to Rs. %.2f\n", monthly_Budget);
}
