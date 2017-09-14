#include "BankAccount.h"
int main(){
	BankAccount Acct1;
	BankAccount Acct2;
	bool done = false;
	bool flag = false;
	double amount;
	ofstream fout;
	while (!done)
	{
		cout << left << showpoint << fixed << setprecision(2);
		cout<< endl << "**************Main Menu**************" << endl
			<< "1. Create an account from keyboard data entry. " << endl
			<< "2. Create an account from input file data entry." << endl
			<< "3. Print account balance to console." << endl
			<< "4. Withdraw money" << endl
			<< "5. Deposit Money" << endl
			<< "6. Print account details to console" << endl
			<< "7. Print account details to an output file" << endl
			<< "8. Print full name of account holder to console" << endl
			<< "9. Print account number only of the account holder to console" << endl
			<< "10. Exit." << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{//keyboard entry
			Acct1.getInstance(Acct1);
			Acct1.print();
			flag = true;
		}
		else if (choice == 2)
		{//file input
			ifstream fin;
			string iFile;
			cin.ignore();
			cout << "What file?:"<< endl;
			getline(cin, iFile);
			fin.open(iFile);

			Acct1.getInstance(Acct1, fin);
			Acct1.print();
			flag = true;
		}
		else if (((choice >= 3) && (choice <= 9)) && (flag == true)){
			
			if (choice == 3)
			{//print acct balance to console
				cout << "Balance: $" << Acct1.getBalance()<< endl;
			}
			else if (choice == 4)
			{//withdraw money
				cout << "What amount to withdraw?: " << endl;
				cin >> amount;
				Acct1.withdraw(amount);
			}
			else if (choice == 5)
			{//deposit money
				cout << "What amount to deposit?: " << endl;
				cin >> amount;
				Acct1.deposit(amount);
			}
			else if (choice == 6)
			{//print acct details console
				Acct1.print();
			}
			else if (choice == 7)
			{//print acct details to file
				string oFile;
				cin.ignore();
				cout << "What file to output to?: " << endl;
				getline(cin, oFile);
				fout.open(oFile);
				fout << Acct1.toString();
			}
			else if (choice == 8)
			{//print full name of acct holder to console
				cout << "Name: " << Acct1.getFullName()<< endl;
			}
			else if (choice == 9)
			{//print account number only of acct holder to console
				cout << "Acct Num: " << Acct1.getAccountNumber() << endl;
			}
		}
		else if (choice == 10)
		{//exit
			done = true;
		}
		else if (flag == false){
			cout << "Account has not yet been inputted." << endl;
		}
		else
		{
			cout << "This menu option is not yet implemented" << endl;
		}
	}// loop
}