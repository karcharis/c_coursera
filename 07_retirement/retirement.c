#include <stdlib.h>
#include <stdio.h>

typedef struct _retire_info {
	int months;
	double contribution;
	double rate_of_return;
} retire_info;

void printCurrentBalance(int currentAge, double currentBalance) {
	
	printf("Age %3d month %2d you have $%.2lf\n", currentAge/12, currentAge%12, currentBalance); 
}

double newBalance(double currentBalance, retire_info retirementPlan) {
	return currentBalance += currentBalance*retirementPlan.rate_of_return + retirementPlan.contribution;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired) {

//startAge = age in months,
//initial = initial savings in dollars,
//working info of retirement, 
//retired info of retirement 	

	//see newBalance(...)
	//compute retirement account balance 
		//for each month of working
		//this is done by 
		//1. computing the balance increase using balance*rate_of_return
		//2. balance += increase + monthly_deposite
	//see printCurrentBalance(...)
	//at the start of each month should print:
	//"Age %3d month %2d you have $%.2lf\n"
	//
	//repeat the above on the retire_info retired
	
	int age = startAge;
	double balance = initial;

	//calculate balance for each month during working years
	for (int monthIn = 0; monthIn < working.months; ++monthIn) {

		printCurrentBalance(age, balance);
		balance = newBalance(balance, working);
		
		++age;
	}

	//calculate balance for each month in retirement
	for (int monthIn = 0; monthIn < retired.months; ++monthIn) {

		printCurrentBalance(age, balance);
		balance = newBalance(balance, retired);
		
		++age;
	}			
}

int main(void) {

	retire_info working;
		working.months =  489;
		working.contribution = 1000;
		working.rate_of_return = 0.045/12;

	retire_info retired;
		retired.months = 384;
		retired.contribution = -4000;
		retired.rate_of_return = 0.01/12;

	int startAge = 327;
	double initial = 21345;

	retirement(startAge, initial, working, retired);

	return EXIT_SUCCESS;
}

