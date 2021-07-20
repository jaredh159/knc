#include <stdio.h>

int main(void) {
  float loan_amount, interest_rate, monthly_payment;
  float balance, monthly_interest_rate, month_interest;
  printf("Enter amount of loan: ");
  scanf("%f", &loan_amount);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
 
  balance = loan_amount;
  monthly_interest_rate = interest_rate / 100.0f / 12.0f;

  month_interest = balance * monthly_interest_rate;
  balance = loan_amount + month_interest - monthly_payment;
  printf("Balance remaining after first payment: $%.2f\n", balance);

  month_interest = balance * monthly_interest_rate;
  balance = balance + month_interest - monthly_payment;
  printf("Balance remaining after second payment: $%.2f\n", balance);

  month_interest = balance * monthly_interest_rate;
  balance = balance + month_interest - monthly_payment;
  printf("Balance remaining after third payment: $%.2f\n", balance);

  return 0;
}
