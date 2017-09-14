#pragma once// One of include guard
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
#include <sstream>
using namespace std;

class BankAccount{
private:
	string ActNum;//account number for this account
	double balance;//money in dollars in the account
	string FirstName;//first name of the account holder
	string LastName;//last name of the account holder

public:
	//DEFAULT CONSTRUCTOR
	BankAccount(){
		ActNum = "Account number not set";
		balance = 0;
		FirstName = "First Name not set";
		LastName = "Last Name not set";

	}

	//EXPLICIT CONSTRUCTOR
	BankAccount(const string & actN, const string & fname, const string & lname, double bal);
	
	//TO STRING
	const string toString() const;
	
	//SETTERS (MUTATORS)
	void deposit(double money);
	void withdraw(double money);
	void setAccountNumber(const string & actN);
	void setLastName(const string & lname);

	//GETTERS (ACCESSORS)
	void print(ostream & out = cout) const;
	string getAccountNumber() const;
	double getBalance() const;
	const string getFirstName() const;
	const string getFullName() const;
	const string getLastName() const;
	static void getInstance(BankAccount & BA);
	static void getInstance(BankAccount & BA, ifstream & in);


};

#endif