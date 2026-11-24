#include <stdio.h>
#include "expenses.h"
#include "budget.h"

int main(){
    int choice;
    loadExpenses();
    loadIncome();
    loadBudget();

    do{
        printf("\n===== BUDGET TRACKER =====\n");
        printf("1. Add User\n");
        printf("2. Add Income\n");
        printf("3. Add Expense\n");
        printf("4. View Expenses\n");
        printf("5. Calculate Total Expenses\n");
        printf("6. Search Expense by Category\n");
        printf("7. Search Expense by Month\n")
        printf("8. Set Budget\n");
        printf("9. Calculate Balance\n");
        printf("10. Generate Report\n");
        printf("11. Check Budget Alert\n");
        printf("0. Exit\n");
        
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                addUser();
                break;

            case 2:
                addIncome();
                break;

            case 3:
                addExpenses();
                break;

            case 4:
               viewExpenses();
                break;

            case 5:
                printf("\nTotal Expenses: %.2f\n", calculateTotalExpenses());
                break;

            case 6:
               searchByCategory();
                break;

            case 7:
               searchByMonth();
                break;
           
            case 8:
                setBudget();
                 break;

            case 9:
                calculateBalance();
                break;

            case 10:
                generateReport();
                break;

            case 11:
                checkBudgetAlert();
                break;

            case 0:
                saveExpenses();
                saveIncome();
                saveBudget();
                printf("Thank you for using Budget Tracker! \n");
                break;

            default:
                printf("Invalid choice!Try again\n");
        }

    }while(choice != 0);

    return 0;
}



