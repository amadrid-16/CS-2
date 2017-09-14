#include "BankAccount.h"

//EXPLICIT CONSTRUCTOR
BankAccount::BankAccount(const string & actN, const string & fname, const string & lname, double bal){
	ActNum = actN;
	
	FirstName = fname;
	LastName = lname;
	if (bal < 0){
		cout << "Error: balance cannot be less than 0" << endl;
		bal = 0;
	}
	else if (bal >= 0){
		balance = bal;
	}
}

//TO STRING
const string BankAccount::toString() const{
	ostringstream oss;

	oss << left << showpoint << fixed << setprecision(2);
	oss << ActNum << ", "<< FirstName << ", " << LastName << ", $" << balance << endl;

	return oss.str();
}

//SETTERS (MUTATORS)
void BankAccount::deposit(double money){
	if (money > 0){//value is not greater than or equal to zero
		//add value to current balance
		balance += money;
	}
	else if (money <=0){//value is zero or negative
		cout << "Deposit must be greater than 0. Balance is unchanged" << endl;
	}

}
void BankAccount::withdraw(double money){
	double nbal;
	nbal = balance - money;
	if (nbal > 0){//value is greater than zero
		//subtract value from current balance
		balance -= money;
	}
	else if (nbal <= 0){//value is zero or negative
		cout << "Withdraw must less than current balance. Balance is unchanged" << endl;
	}
}
void BankAccount::setAccountNumber(const string & actN){
	ActNum = actN;
}
void BankAccount::setLastName(const string & lname){
	LastName = lname;
}

//GETTERS (ACCESSORS)
void BankAccount::print(ostream & out) const{
	cout << toString();
}
string BankAccount::getAccountNumber() const{
	return ActNum;
}
double BankAccount::getBalance() const{
	return balance;
}
const string BankAccount::getFirstName() const{
	return FirstName;
}
const string BankAccount::getFullName() const{
	return FirstName + " " + LastName;
}
const string BankAccount::getLastName() const{
	return LastName;
}
void BankAccount::getInstance(BankAccount & BA){
	cin.ignore();
	cout << "Please enter the account number for the account: " << endl;
	getline(cin, BA.ActNum);
	cout << "Please enter the First Name for the account" << endl;
	getline(cin, BA.FirstName);
	cout << "Please enter the Last Name for the account" << endl;
	getline(cin, BA.LastName);
	cout << "Please enter the starting Balance for the account" << endl;
	cin >> BA.balance;
	cin.ignore();
}
void BankAccount::getInstance(BankAccount & BA, ifstream & in){
	
	getline(in, BA.ActNum);
	
	getline(in, BA.FirstName);
	
	getline(in, BA.LastName);
	
	in >> BA.balance;
}

