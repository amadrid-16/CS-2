#pragma once// One of include guard
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream> // IO to files
#include <iomanip>
#include <sstream>
using namespace std;

class Mortgage{

private:
	int AccountNum;// Account Number
	string FirstName;//First Name of Borrower
	string LastName;

	double rate;//fixed annual interest only
	double cost;//cost of the houses bought
	double downPymnt;//down payment made by the buyer
	int year;//number of years the mortgage is taken
	double MonthlyPayment;//monthly payment
public:
//Default Constructor
Mortgage(){
	AccountNum = 0;
	FirstName = "First Name not set";
	LastName = "Last Name not set";
	rate = 0.0;
	cost = 0.0;
	downPymnt = 0.0;
	year = 0;
	MonthlyPayment = 0.0;
	

}
//Explicit Constructor
Mortgage(int AccountNum, string LastName, double rate, double cost, double downPymnt, int year){
	getMonthlyPayments();
	if (AccountNum){
		cout << "Account number cannot be negative"<<endl;
		AccountNum = 0;
	}
	if (rate <= 0){
		cout << "Rate is invalid" << endl;
		rate = 4.5;
	}
	if (cost <= 0){
		cout << "Cost is invalid" << endl;
		cost = 200000;
	}
	if (downPymnt >= cost){
		cout << "Down Payment is invalid" << endl;
		downPymnt = cost*.20;
	}
	if (year <= 0){
		cout << "The ammount of Years is invalid" << endl;
		year = 30;// need to use constructor member list
	}
}
static Mortgage getInstance(){
	fstream fin;


	return Mortgage();
}

};
#endif
