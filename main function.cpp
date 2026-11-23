#include <stdio.h>
#include "Function expenses.h"
#include "budget.h"

int main(){
    int choice;
    loadExpenses();
    loadIncome();
    loadBudget();

    do{
        printf("\n===== BUDGET TRACKER =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Search Expense by Category\n");
        printf("5. Search Expense by Month\n");
        printf("6. Add Income\n");
        printf("7. Set Budget\n");
        printf("8. Calculate Balance\n");
        printf("9. Generate Report\n");
        printf("10. Check Budget Alert\n");
        printf("0. Exit\n");
        
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                calculateTotalExpenses();
                break;

            case 4:
                searchByCategory();
                break;

            case 5:
                searchByMonth();
                break;

            case 6:
                addIncome();
                break;

            case 7:
                setBudget();
                break;

            case 8:
                calculateBalance();
                break;

            case 9:
                generateReport();
                break;

            case 10:
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


