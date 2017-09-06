/*
Angel Madrid
CSci 2
Section 0146
Assignment 1
8/30/17
Grade: 10/10
*/

//Algorithm
/*
Input
Get user data from file
Check for validity
Name
First
No checks required
Last
No checks required
Employee ID
Make sure the input is not less than 0
Make sure the input is not greater than 9999
Employee Code
Make sure the input is of char variable type
Make sure the char is 'S', 'O', or 'M'
Must be capital
Other value is invalid, print error
set salary to 0
Job Classification
Must be 1, 2, or 3
Other value is invalid, print error
set
Years of Service
Must be under 50
Must be >= 0
Other value is invalid, print error
set salary to 0
Education
Must be 1, 2, 3, or 4
Other value is invalid, print error
set salary to 0

Put user data into respective variables

Process
Calculate salary
First
No calculation
Last
No calculation
Employee Code
S base pay = 800.0
O base pay = 1000.0
M base pay = 1500.0
Invalid:
salary = 0
+= Error:Employee Code
Job Classification

IF SALARY is NOT -1
1 = add 5% base
2 = add 10% base
3 = add 20% base
Invalid:
salary = 0
+= Error:Job Classification
Years of Service
IF SALARY is NOT -1
0-10 = add 5% to base
10+ = add 1%/year
Invalid:
salary = 0
+= Error:Years of Service
Education
IF SALARY is NOT -1
1 = add 0% base
2 = add 5% base
3 = add 12% base
4 = add 20% base
Invalid:
salary = 0
+= Error:Education Code
Output
Print in table format
If salary = 0 print error message


*/

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define MAX 30

using namespace std;

struct Employee{
	string fName = "", lName = "", jobType = "";
	char empCode = 'I';
	int empID = -1, jobCode = -1, yearsServ = -1, edCode = -1;
	double gsal = 0, basePay;
	string errorStat = "No Errors\n";
};
struct Office{
	Employee emp1[MAX];
	string officeName = "";
	int numEmps = 0;
};

void getArrData(Employee Arr[]);
void getData(Employee & emp1);
void getEmp(Employee & emp1, fstream & fin, int index);
void checkID(Employee & emp1);
void checkEmpCode(Employee & emp1);
void checkJobClassi(Employee & emp1);
void checkYOS(Employee & emp1);
void checkEd(Employee & emp1);
void calcSal(Employee & emp1);

void printHeader();
void printEmp(Employee & emp1);
void checkData(Employee & emp1);

void sortMenu();
void sortList(Employee Arr[MAX]);
void searchMenu();
void searchList(Employee Arr[MAX]);

void runStuff(Employee Arr[MAX], char selection);
void printMenu();
char makeSelect();
void sortByName();
void sortByID();
void sortBySal();

void exitProgram();

int main(){
	Employee Arr[MAX];

	cout << left << showpoint << fixed << setprecision(2);
	cout << endl << "Welcome to the Badwater Brewery Salary Calculator" << endl;
	getArrData(Arr);
	
	/*getData(Arr[0]);
	checkData(Arr[0]);
	calcSal(Arr[0]);
	cout << endl << endl << Arr[0].errorStat << endl;
	printHeader();
	printEmp(Arr[0]);
	*/
	char selection = 'x';

	do{
		printMenu();
		selection = makeSelect();
		system("cls");
		runStuff(Arr, selection);
		

	} while (selection != 'X' && selection != 'x');
	

	return 0;


}
void getArrData(Employee Arr[]){
	
	fstream fin;
	string inputFileName;
	int i = 0;
	cout << endl << "Please enter an input file name: ";
	getline(cin, inputFileName);;
	fin.open(inputFileName);
	if (fin.fail()){
		cout << "Error: Bad Filename" << endl;
		exit(0);
	}
	
	getEmp(Arr[i], fin,i);

	while (!fin.eof()&& i != MAX-1){
		
		i++;
		cout << i << endl;
		getEmp(Arr[i],fin, i);

		if (i == MAX-1){
			cout << "Error: Reached Max number of employees";
		}

	}
}
void getData(Employee & emp1){
	fstream fin;
	string inputFileName;
	int i = 0;
	cout << endl << "Please enter an input file name: ";
	getline(cin, inputFileName);;
	fin.open(inputFileName);
	if (fin.fail()){
		cout << "Error: Bad Filename" << endl;
		exit(0);
	}
	getEmp(emp1, fin,0);

}
void getEmp(Employee & emp1, fstream & fin,int index){

	getline(fin, emp1.fName, ' ');
	if (fin.eof()&& index == 0){
		cout << "Error: Empty File" << endl;
		exit(0);
	}
	else if (fin.eof()){
		cout << "End of File" << endl;
	}
	else if (!fin){
		cout << "Error: Bad Data Type" << endl;
		exit(0);
	
	}
	else{
		cout << "Employee First Name: " << emp1.fName << endl;

		getline(fin, emp1.lName, '\n');
		if (fin.eof()){
			cout << "Error: Missing Data, Last Name" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		cout << "Employee Last Name: " << emp1.lName << endl;

		fin >> emp1.empCode;
		if (fin.eof()){
			cout << "Error: Missing Data, Employee Code" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		cout << "Employee Code: " << emp1.empCode << endl;

		fin >> emp1.empID;
		if (fin.eof()){
			cout << "Error: Missing Data, Employee ID" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		cout << "Employee ID: " << emp1.empID << endl;

		fin >> emp1.jobCode;
		if (fin.eof()){
			cout << "Error: Missing Data, Job Code" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		cout << "Employee Job Code: " << emp1.jobCode << endl;

		fin >> emp1.yearsServ;
		if (fin.eof()){
			cout << "Error: Missing Data, Years Served" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		cout << "Employee Years Served: " << emp1.yearsServ << endl;

		fin >> emp1.edCode;
		if (fin.eof()){
			cout << "Error: Missing Data, Educational Code" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		cout << "Employee Education Code: " << emp1.edCode << endl;
		checkData(emp1);
		calcSal(emp1);
		cout << endl << endl << " " << emp1.errorStat << endl;
		fin.ignore();
	}
}
void checkID(Employee & emp1){
	if (emp1.empID<0 || emp1.empID>9999){
		cout << "Error: Invalid Employee ID" << endl;
		emp1.errorStat = "Error: Invalid Employee ID\n";
		emp1.empID = -1;
	}
	else{
		cout << "emp ID good" << endl;
	}
}
void checkEmpCode(Employee & emp1) {

	/*Employee Code

	Make sure the char is 'S', 'O', or 'M'
	Must be capital
	Other value is invalid, print error
	set salary to 0
	*/
	if (emp1.gsal == -1){
		if (!(emp1.empCode == 'S') && !(emp1.empCode == 'O') && !(emp1.empCode == 'M')){
			cout << "Error: Invalid Employee Code" << endl;
			emp1.errorStat = "Error: Invalid Employee Code\n";
		}
		else{
			cout << "emp code good" << endl;
		}
	}
	else{
		if (!(emp1.empCode == 'S') && !(emp1.empCode == 'O') && !(emp1.empCode == 'M')){
			cout << "Error: Invalid Employee Code" << endl;
			emp1.errorStat = "Error: Invalid Employee Code\n";
			emp1.gsal = -1;
		}
		else{
			cout << "emp code good" << endl;
		}
	}




}
void checkJobClassi(Employee & emp1){
	/*Job Classification
	Must be 1, 2, or 3
	Other value is invalid, print error
	set*/
	if (emp1.gsal == -1){
		if (!(emp1.jobCode == 1) && !(emp1.jobCode == 2) && !(emp1.jobCode == 3)){
			cout << "Error: Invalid Job Code" << endl;
			emp1.errorStat += "Error: Invalid Job Code\n";
		}
		else{
			cout << "job code good" << endl;
		}
	}
	else{
		if (!(emp1.jobCode == 1) && !(emp1.jobCode == 2) && !(emp1.jobCode == 3)){
			cout << "Error: Invalid Job Code" << endl;
			emp1.errorStat = "Error: Invalid Job Code\n";
			emp1.gsal = -1;
		}
		else{
			cout << "job code good" << endl;
		}
	}
}
void checkYOS(Employee & emp1){
	/*Years of Service
	Must be under 50
	Must be >= 0
	Other value is invalid, print error
	set salary to 0*/
	if (emp1.gsal == -1){

		if ((emp1.yearsServ < 0) || (emp1.yearsServ>  50)){
			cout << "Error: Invalid YOS" << endl;
			emp1.errorStat += "Error: Invalid YOS\n";
		}
		else{
			cout << "yos good" << endl;
		}
	}
	else{
		if ((emp1.yearsServ < 0) || (emp1.yearsServ>  50)){
			cout << "Error: Invalid YOS" << endl;
			emp1.errorStat = "Error: Invalid YOS\n";
			emp1.gsal = -1;
		}
		else{
			cout << "yos good" << endl;
		}
	}

}
void checkEd(Employee & emp1){
	/*
	Education
	Must be 1, 2, 3, or 4
	Other value is invalid, print error
	set salary to 0*/
	if (emp1.gsal == -1){
		if (!(emp1.edCode == 1) && !(emp1.edCode == 2) && !(emp1.edCode == 3) && !(emp1.edCode == 4)){
			cout << "Error: Invalid Ed Code" << endl;
			emp1.errorStat += "Error: Invalid Ed Code\n";
		}
		else{
			cout << "Ed good" << endl;
		}
	}
	else{
		if (!(emp1.edCode == 1) && !(emp1.edCode == 2) && !(emp1.edCode == 3) && !(emp1.edCode == 4)){
			cout << "Error: Invalid Ed Code" << endl;
			emp1.errorStat = "Error: Invalid Ed Code\n";
			emp1.gsal = -1;
		}
		else{
			cout << "Ed good" << endl;
		}
	}

}
void calcSal(Employee & emp1){

	if (emp1.empCode == 'S'){
		emp1.jobType = "Factory Worker";
	}
	else if (emp1.empCode == 'O'){
		emp1.jobType = "Office Worker";

	}
	else if (emp1.empCode == 'M'){
		emp1.jobType = "Management";
	}
	else{
		emp1.jobType = "Job Type Not Found";
	}
	if (emp1.gsal != -1){
		/*Employee Code
		S base pay = 800.0
		O base pay = 1000.0
		M base pay = 1500.0*/
		if (emp1.empCode == 'S'){
			emp1.basePay = 800;
			emp1.gsal = 800;
		}
		else if (emp1.empCode == 'O'){
			emp1.basePay = 1000;
			emp1.gsal = 1000;

		}
		else if (emp1.empCode == 'M'){
			emp1.basePay = 1500;
			emp1.gsal = 1500;
		}

		/*Job Classification

		IF SALARY is NOT - 1
		1 = add 5 % base
		2 = add 10 % base
		3 = add 20 % base*/
		if (emp1.jobCode == 1){
			emp1.gsal += emp1.basePay*.05;
		}
		else if (emp1.jobCode == 2){
			emp1.gsal += emp1.basePay*.1;
		}
		else if (emp1.jobCode == 3){
			emp1.gsal += emp1.basePay*.2;
		}
		/*Years of Service
		IF SALARY is NOT - 1
		0 - 10 = add 5 % to base
		10 + = add 1 % / year*/
		if (emp1.yearsServ <= 10){
			emp1.gsal += emp1.basePay*.05;
		}
		else if (emp1.yearsServ > 10){

			emp1.gsal += emp1.basePay*(.01*(emp1.yearsServ - 10) + 0.05);
		}
		/*Education
		IF SALARY is NOT - 1
		1 = add 0 % base
		2 = add 5 % base
		3 = add 12 % base
		4 = add 20 % base*/

		if (emp1.edCode == 1){

		}
		else if (emp1.edCode == 2){
			emp1.gsal += emp1.basePay*.05;
		}
		else if (emp1.edCode == 3){
			emp1.gsal += emp1.basePay*.12;
		}
		else if (emp1.edCode == 4){
			emp1.gsal += emp1.basePay*.20;
		}

	}
	else{}



}

void printHeader(){
	cout << setw(20) << "Name" << setw(20) << "ID Number" << setw(20) << "Job Type" << setw(20) << "Gross Salary" << endl;
}
void printEmp(Employee & emp1){
	string name = emp1.fName + " " + emp1.lName;

	cout << setw(20) << name;
	if (emp1.empID != -1){
		cout << setw(20) << emp1.empID;
	}
	else{
		cout << setw(20) << "Employee ID Invalid";
	}

	cout << setw(20) << emp1.jobType;

	if (emp1.gsal != -1){
		cout << setw(20) << emp1.gsal << endl;
	}
	else{
		cout << setw(20) << "Salary could not be computed" << endl;
	}

}
void checkData(Employee & emp1){
	checkEmpCode(emp1);
	checkID(emp1);
	checkJobClassi(emp1);
	checkYOS(emp1);
	checkEd(emp1);
}

void sortMenu(){
	cout << endl << "Sort Menu" << endl;
	cout << "'N' - Sort by Last names" << endl;
	cout << "'I' - Sort by ID" << endl;
	cout << "'S' - Sort by Salary" << endl;

}
void sortList(Employee Arr[MAX]){
	char selection;
	sortMenu();
	selection = makeSelect();
	switch (selection){
	case'N':
	case 'n':
		sortByName();
		break;
	case 'I':
	case'i':
		sortByID();
		break;
	case 'S':
	case 's':
		sortBySal();
		break;
	default:
		cout << endl << "Error: thats not an option" << endl;

	}


}
void searchMenu(){
	cout << endl << "Search Menu" << endl;
	cout << "'N' - Search by Last names" << endl;
	cout << "'I' - Search by ID" << endl;
	cout << "'S' - Search by Salary" << endl;
}
void searchList(Employee Arr[MAX]){
	char selection;
	searchMenu();
	selection = makeSelect();
	switch (selection){
	case'N':
	case 'n':
		sortByName();
		break;
	case 'I':
	case'i':
		sortByID();
		break;
	case 'S':
	case 's':
		sortBySal();
		break;
	default:
		cout << endl << "Error: thats not an option" << endl;

	}
}

void runStuff(Employee Arr[MAX], char selection){
	switch (selection){

	case 'S':
	case 's':
		searchList(Arr);
		break;
	case 'O':
	case 'o':
		sortList(Arr);
		break;

	case 'X':
	case 'x':

		exitProgram();

	default:
		cout << endl << "Error: Thats not an option" << endl;
	}
}
void printMenu(){
	cout << endl << "MENU" << endl;
	cout << "'S' - Search" << endl;
	cout << "'O' - Sort" << endl;
	cout << "'X' - Exit Program" << endl;

}
char makeSelect(){

	char selection;
	cin >> selection;
	cin.ignore(10, '\n');

	return selection;
}

void sortByName(){
	cout << "Sorting by Name" << endl;
}
void sortByID(){
	cout << "Sorting by ID" << endl;
}
void sortBySal(){
	cout << "Sorting by Salary" << endl;
}

void searchByName(){
	cout << "Searching by Name" << endl;
}
void searchByID(){
	cout << "Searching by ID" << endl;
}
void searchBySal(){
	cout << "Searching by Salary" << endl;
}

void exitProgram(){

	cout << "Goodbye" << endl;
	exit(0);
}
