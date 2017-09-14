#include "BankAccount.h"



int main(){
	//CONSTRUCTOR
	BankAccount Acct1("A4321" , "Angel", "Madrid", 1500.50);
	BankAccount Acct2;
	//TOSTRING
	cout << "INTIAL" << endl;
	cout << Acct1.toString();
	cout << endl;
	//DEPOSIT
	Acct1.deposit(30);
	cout << "After DEPOSIT"<< endl;
	cout << Acct1.toString();
	cout << endl;
	//WITHDRAW
	cout << "After WITHDRAW" << endl;
	Acct1.withdraw(60);
	cout << Acct1.toString();
	cout << endl;
	//SET ACCOUNT NUMBER
	cout << "After SET ACCOUNT NUMBER" << endl;
	Acct1.setAccountNumber("A1234");
	cout << Acct1.toString();
	cout << endl;
	//SET LAST NAME
	cout << "After SET LAST NAME" << endl;
	Acct1.setLastName("Barcelona");
	cout << Acct1.toString();
	cout << endl;
	//PRINT
	cout << "After PRINT" << endl;
	Acct1.print();
	cout << endl;
	//GET ACCOUNT
	cout << "After GET ACCOUNT" << endl;
	cout << Acct1.getAccountNumber() << endl;
	cout << endl;
	//GET BALANCE
	cout << "After GET BALANCE" << endl;
	cout << Acct1.getBalance() << endl;
	cout << endl;
	//GET FNAME
	cout << "After GET FNAME" << endl;
	cout << Acct1.getFirstName() << endl;
	cout << endl;
	//GET FULLNAME
	cout << "After GET FULLNAME" << endl;
	cout << Acct1.getFullName() << endl;
	cout << endl;
	//GET LASTNAME
	cout << "After GET LASTNAME" << endl;
	cout << Acct1.getLastName() << endl;
	cout << endl;
	//GET INSTANCE 1
	cout << "GET INSTANCE 1" << endl;
	Acct2.getInstance(Acct2);
	Acct2.print();
	cout << endl;
	//GET INSTANCE 2
	cout << "GET INSTANCE 2" << endl;
	ifstream fin;
	fin.open("input.txt");

	Acct2.getInstance(Acct2, fin);
	Acct2.print();
	cout << endl;



	return 0;
}

