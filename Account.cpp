#include"Account.h"



bool Account:: withdrawal(double amount)
{
	if (balance < amount)
	{
		return false;
	}
	else
	{
		balance -= amount;
		transactions++;
	}

}