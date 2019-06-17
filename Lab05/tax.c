#include <stdlib.h>
#include <stdio.h>

#define MAX_TAX 50000

float taxableIncome(float income, float deduction) {
    return income >= deduction ? income - deduction : 0;
}

char taxGroup(float taxable) {
    if(taxable >= 500000) return 'S';
    else if(taxable >= 200000) return 'Q';
    else if(taxable >= 100000) return 'M';
    else if(taxable >= 50000) return 'A';
    else if(taxable >= 20000) return 'R';
    else return 'P';
    }

float calcTax(char group, float taxable) {
    float tax;
    switch(group) {
    case 'S':
    case 'Q':
        tax = taxable * 0.25;
        break;
    case 'M':
        tax = taxable * 0.1;
        break;
    case 'A':
    case 'R':
        tax = taxable * 0.03;
        break;
    case 'P':
        tax = 0;
        break;
    default:
        printf("ERROR: INVALID TAX GROUP");
        return (EXIT_FAILURE);
    }
    return tax < MAX_TAX ? tax : MAX_TAX;
}

int main(void) {

    float val;
    float income;
    float deductions;
    float taxable_income;
    char tax_group;
    float tax;

    printf("\n");

    for(;;) {
        printf("Enter next amount: ");
        scanf("%f", &val);
        if(val == 0)
            break;
        if(val > 0) income += val;
            else deductions += abs(val);
    }

    taxable_income = taxableIncome(income, deductions);
    tax_group = taxGroup(taxable_income);
    tax = calcTax(tax_group, taxable_income);
    printf("\nIncome: $%.2f \nDeductions: $%.2f \n", income, deductions);
    printf("Taxable Income: $%.2f \n", taxable_income);
    printf("Tax Group: %c \n", tax_group);
    printf("Tax Owed: $%.2f \n\n", tax);

    return (EXIT_SUCCESS);
}
