#pragma once
class Account {
	double balance, intrate, interest;
	int transactions;
public:
	//constractor
		Account(double rate = 0.045, double bal = 0)
	{
			intrate = rate;
			balance = bal;
			interest = 0;
			transactions = 0;
	}
		//make a mathod for deposit
		void makeDeposit(double amount)
		{
			balance += amount;
			transactions++;
		}
		//make a method for withdrawal
		bool withdrawal(double amount);

		void calculateinterest()
		{
			interest = balance + intrate;
			balance += interest;
		}

		double getbalance()
		{
			return balance;
		}
		///----------------
		double getinterest()
		{
			return interest;
		}
		///----------------
		double gettransactions()
		{
			return transactions;
		}
};