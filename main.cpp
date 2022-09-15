#include<iostream>
#include<iomanip>
#include"Account.h"

using namespace std;

void displaymenu()
{
	cout << "\n\n            MENU\n\n";
	cout << "1) Display the account balance\n";
	cout << "2) Display the number of transactions\n";
	cout << "3) Display interest earned for this period \n";
	cout << "4) make a Deposit\n";
	cout << "5) make a withdrawal\n";
	cout << "6) add interest for this period \n";
	cout << "7)exit \n\n";
	cout << "enter yor choice";
}

char getchoice(char maxx) {

	char choice = cin.get();
	cin.ignore();
	while (choice<'1' || choice>maxx)
	{
		cout << "choice must be beetwn 1 and " << maxx << " ."<<
		"please re-enter choice : ";
		choice = cin.get();
		cin.ignore();
	}

	return choice;
}


void makeDeposit(Account &account)
{
	double dollars;
	cout << "enter the amount of Deposit";
	cin >> dollars;
	cin.ignore();
	account.makeDeposit(dollars);
}

void withdrawal(Account& account)
{
	double dollars;
	cout << "enter the amount of withdrawal";
	cin >> dollars;
	cin.ignore();
	if (!account.withdrawal(dollars))
	{
		cout << "ERROR :withdrawal is to large .\n\n";
	}
}

int main()
{
	const char maxchoice = '7';
	Account savings;
	char choice;
	cout << fixed << showpoint << setprecision(2);
	do {
		displaymenu();
		choice = getchoice(maxchoice);
		switch (choice)
		{
		case '1':
			cout << "the current balance is $";
			cout << savings.getbalance() << endl;
			break;

		case '2':
			cout << "there have been ";
			cout <<savings.gettransactions()<<"transactions .\n "<< endl;
			break;

		case '3':
			cout<<"interest earned for this period : $";
			cout << savings.getinterest() << endl;
			break;

		case '4':
			makeDeposit(savings);
			break;

		case '5':
			withdrawal(savings);
			break;

		case '6':
			savings.calculateinterest();
			cout << "interest added. \n";
		}
	} while (choice != 7);

	return 0;
}