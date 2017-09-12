/*
Angel Madrid
CSci 2
Section 0146
Assignment 1
8/30/17
Grade: 10/10
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
/////////////////////////////////////////
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

void printHeaderTF(ofstream & fout);
void printEmpTF(Employee emp1, ofstream & fout);

void printAllEmp(Employee Arr[MAX]);
void printAllEmpTF(Employee Arr[MAX], ofstream & fout);


void checkData(Employee & emp1);

void sortMenu();
void sortList(Employee Arr[MAX]);
void searchMenu();
void searchList(Employee Arr[MAX]);

void runStuff(Employee Arr[MAX], char selection);
void printMenu();
char makeSelect();

void sortString(Employee Arr[MAX], int index);
void sortByName(Employee Arr[MAX]);
int checkNameOrder(Employee Arr[MAX]);

int searchByName(Employee Arr[MAX], string sName);
int searchByID(Employee Arr[MAX], int sID);


void sortByID(Employee Arr[MAX]);
int checkIDOrder(Employee Arr[MAX]);


void sortBySal(Employee Arr[MAX]);
int checkSalOrder(Employee Arr[MAX]);

void printSubMenu();
void subList(Employee Arr[MAX]);

void exitProgram();



///////////////////////////////////
//MAIN FUNCTION
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

///////////////////////////////////
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
		//cout << i << endl;
		getEmp(Arr[i],fin, i);
		

		if (i == MAX-1){
			cout << "Error: Reached Max number of employees";
		}

	}
	string filename;
	ofstream fout;
	
	cout << endl << "Please give an output file name: ";
	getline(cin, filename);
	fout.open(filename);
	fout << left << showpoint << fixed << setprecision(2);
	
	fout << "Unsorted" << endl;
	printHeaderTF(fout);
	
	for (int i = 0; i < MAX; i++){
			
		if (Arr[i].lName == ""){

		}
		else{
			printEmpTF(Arr[i], fout);
		}

	
	}

	fout << endl << endl;
	sortByID(Arr);
	fout << "Sorted by ID" << endl;
	printHeaderTF(fout);

	for (int i = 0; i < MAX; i++){

		if (Arr[i].lName == ""){

		}
		else{
			printEmpTF(Arr[i], fout);
		}


	}
	fout << endl << endl;
	sortByName(Arr);
	fout << "Sorted by Name" << endl;
	printHeaderTF(fout);

	for (int i = 0; i < MAX; i++){

		if (Arr[i].lName == ""){

		}
		else{
			printEmpTF(Arr[i], fout);
		}


	}
	fout << endl<<endl;
	
	sortBySal(Arr);
	fout << "Sorted by Salary" << endl;
	printHeaderTF(fout);

	for (int i = 0; i < MAX; i++){

		if (Arr[i].lName == ""){

		}
		else{
			printEmpTF(Arr[i], fout);
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
		//cout << "Employee First Name: " << emp1.fName << endl;

		getline(fin, emp1.lName, '\n');
		if (fin.eof()){
			cout << "Error: Missing Data, Last Name" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		//cout << "Employee Last Name: " << emp1.lName << endl;

		fin >> emp1.empCode;
		if (fin.eof()){
			cout << "Error: Missing Data, Employee Code" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		//cout << "Employee Code: " << emp1.empCode << endl;

		fin >> emp1.empID;
		if (fin.eof()){
			cout << "Error: Missing Data, Employee ID" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		//cout << "Employee ID: " << emp1.empID << endl;

		fin >> emp1.jobCode;
		if (fin.eof()){
			cout << "Error: Missing Data, Job Code" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		//cout << "Employee Job Code: " << emp1.jobCode << endl;

		fin >> emp1.yearsServ;
		if (fin.eof()){
			cout << "Error: Missing Data, Years Served" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		//cout << "Employee Years Served: " << emp1.yearsServ << endl;

		fin >> emp1.edCode;
		if (fin.eof()){
			cout << "Error: Missing Data, Educational Code" << endl;
			exit(0);
		}
		else if (!fin){
			cout << "Error: Bad Data Type" << endl;
			exit(0);

		}
		//cout << "Employee Education Code: " << emp1.edCode << endl;
		checkData(emp1);
		calcSal(emp1);
		fin.ignore();
		printEmp(emp1);
		cout << endl << endl << " " << emp1.errorStat << endl;
	}
	
}
void checkID(Employee & emp1){
	if (emp1.empID<0 || emp1.empID>9999){
		//cout << "Error: Invalid Employee ID" << endl;
		emp1.errorStat = "Error: Invalid Employee ID\n";
		emp1.empID = -1;
	}
	else{
		//cout << "emp ID good" << endl;
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
			//cout << "Error: Invalid Employee Code" << endl;
			emp1.errorStat = "Error: Invalid Employee Code\n";
		}
		else{
			//cout << "emp code good" << endl;
		}
	}
	else{
		if (!(emp1.empCode == 'S') && !(emp1.empCode == 'O') && !(emp1.empCode == 'M')){
			//cout << "Error: Invalid Employee Code" << endl;
			emp1.errorStat = "Error: Invalid Employee Code\n";
			emp1.gsal = -1;
		}
		else{
			//cout << "emp code good" << endl;
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
			//cout << "Error: Invalid Job Code" << endl;
			emp1.errorStat += "Error: Invalid Job Code\n";
		}
		else{
			//cout << "job code good" << endl;
		}
	}
	else{
		if (!(emp1.jobCode == 1) && !(emp1.jobCode == 2) && !(emp1.jobCode == 3)){
			//cout << "Error: Invalid Job Code" << endl;
			emp1.errorStat = "Error: Invalid Job Code\n";
			emp1.gsal = -1;
		}
		else{
			//cout << "job code good" << endl;
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
			//cout << "Error: Invalid YOS" << endl;
			emp1.errorStat += "Error: Invalid YOS\n";
		}
		else{
			//cout << "yos good" << endl;
		}
	}
	else{
		if ((emp1.yearsServ < 0) || (emp1.yearsServ>  50)){
			//cout << "Error: Invalid YOS" << endl;
			emp1.errorStat = "Error: Invalid YOS\n";
			emp1.gsal = -1;
		}
		else{
			//cout << "yos good" << endl;
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
			//cout << "Error: Invalid Ed Code" << endl;
			emp1.errorStat += "Error: Invalid Ed Code\n";
		}
		else{
			//cout << "Ed good" << endl;
		}
	}
	else{
		if (!(emp1.edCode == 1) && !(emp1.edCode == 2) && !(emp1.edCode == 3) && !(emp1.edCode == 4)){
			//cout << "Error: Invalid Ed Code" << endl;
			emp1.errorStat = "Error: Invalid Ed Code\n";
			emp1.gsal = -1;
		}
		else{
			//cout << "Ed good" << endl;
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
//PRINTING
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

void printHeaderTF(ofstream & fout){
	
	fout << setw(20) << "Name" << setw(20) << "ID Number" << setw(20) << "Job Type" << setw(20) << "Gross Salary" << endl;
}
void printEmpTF(Employee emp1, ofstream & fout){
	string name = emp1.fName + " " + emp1.lName;

	fout << setw(20) << name;
	if (emp1.empID != -1){
		fout << setw(20) << emp1.empID;
	}
	else{
		fout << setw(20) << "Employee ID Invalid";
	}

	fout << setw(20) << emp1.jobType;

	if (emp1.gsal != -1){
		fout << setw(20) << emp1.gsal << endl;
	}
	else{
		fout << setw(20) << "Salary could not be computed" << endl;
	}
}

void printAllEmp(Employee Arr[MAX]){
	printHeader();
	for (int i = 0; i < MAX; i++){
		if (Arr[i].gsal == 0 || Arr[i].gsal == -1){

		}
		else{
			printEmp(Arr[i]);
		}
	}
}
void printAllEmpTF(Employee Arr[MAX], ofstream & fout){
	printHeaderTF(fout);
	for (int i = 0; i < MAX; i++){
		if (Arr[i].gsal == 0 || Arr[i].gsal == -1){

		}
		else{
			printEmpTF(Arr[i], fout);
		}
	}
}

void checkData(Employee & emp1){
	checkEmpCode(emp1);
	checkID(emp1);
	checkJobClassi(emp1);
	checkYOS(emp1);
	checkEd(emp1);
}
//SORT MENU
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
	case 'N':
	case 'n':
		//cout << "sortbyname" << endl;
		sortByName(Arr);

		break;
	case 'I':
	case 'i':
		sortByID(Arr);
		break;
	case 'S':
	case 's':
		sortBySal(Arr);
		break;
	default:
		cout << endl << "Error: thats not an option" << endl;

	}


}
//SEARCH MENU
void searchMenu(){
	cout << endl << "Search Menu" << endl;
	cout << "'N' - Search by Last names" << endl;
	cout << "'I' - Search by ID" << endl;
	//cout << "'S' - Search by Salary" << endl;
}
void searchList(Employee Arr[MAX]){
	char selection;
	string sName;
	int sID;
	searchMenu();
	selection = makeSelect();
	switch (selection){
	case'N':
	case 'n':
		
		cout << "What name would you like to search?" << endl;
		cin >> sName;
		if (searchByName(Arr, sName) >= 0){
			printHeader();
			printEmp(Arr[searchByName(Arr, sName)]);
			
		}
		else{
			cout << "That person does not exist in the system" << endl;
		}
		
		break;
	case 'I':
	case'i':
		

		cout << "What name ID you like to search?" << endl;
		cin >> sID;
		if (searchByID(Arr, sID) >= 0){
			printHeader();
			printEmp(Arr[searchByID(Arr, sID)]);

		}
		else{
			cout << "That person does not exist in the system" << endl;
		}
		break;
	case 'S':
	case 's':
		//searchBySal();
		break;
	default:
		cout << endl << "Error: thats not an option" << endl;

	}
}
//MAIN MENU
void runStuff(Employee Arr[MAX], char selection){
	
	switch (selection){

	case 'S':
	case 's':
		searchList(Arr);
		break;
	case 'O':
	case 'o':
		//cout << "sortlist" << endl;
		sortList(Arr);
		break;
	case 'P':
	case 'p':
		
		subList(Arr);
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
	cout << "'P' - Print" << endl;
	cout << "'X' - Exit Program" << endl;

}
char makeSelect(){

	char selection;
	cin >> selection;
	cin.ignore(10, '\n');

	return selection;
}
// SORT BY NAME
void sortByName(Employee Arr[MAX]){
	
	int i = 0;
	int index;
	Employee currEmp;
	while (checkNameOrder(Arr) >= 0){
		index = checkNameOrder(Arr);
		currEmp = Arr[index];
		Arr[index] = Arr[index + 1];
		Arr[index + 1] = currEmp;
	}
	
}
void sortString(Employee Arr[MAX], int index){
	//if first letter of last names are equal move to next character
	//then switch them around in the array
	//otherwise just switch the two array members
	Employee currEmp;
	int i = 0;
	if (Arr[index].lName.substr(0, 1) == Arr[index + 1].lName.substr(0, 1)){
		while (Arr[index].lName.substr(i, 1) == Arr[index + 1].lName.substr(i, 1)){

			if (Arr[index].lName.substr(i + 1, 1) > Arr[index + 1].lName.substr(i + 1, 1)){

				currEmp = Arr[index];
				Arr[index] = Arr[index + 1];
				Arr[index + 1] = currEmp;
			}
			i++;
		}

	}
	else if (Arr[index].lName.substr(0, 1) > Arr[index + 1].lName.substr(0, 1)){
		currEmp = Arr[index];
		Arr[index] = Arr[index + 1];
		Arr[index + 1] = currEmp;
	}
	
	
	
}
int checkNameOrder(Employee Arr[MAX]){
	//check name order and return index where there is an out of order part
	int index = -1;
	for (int i = 0; i < MAX-1; i++){
		if (Arr[i].lName==""){

		}
		else if (Arr[i].lName.substr(0, 1) == Arr[i + 1].lName.substr(0, 1)){
			sortString(Arr,i);

		}
		else if (Arr[i].lName.substr(0, 1) > Arr[i + 1].lName.substr(0, 1)){
			index = i;
			return index;
		}
	}
	return index;
}

//SORT BY ID
void sortByID(Employee Arr[MAX]){
	/*for (int i = 0; i < MAX - 1; i++){
		cout << Arr[i].empID << endl;
	}*/
	int i = 0;
	int index;
	Employee currEmp;
	while (checkIDOrder(Arr) >= 0){
		index = checkIDOrder(Arr);
		currEmp = Arr[index];
		Arr[index] = Arr[index + 1];
		Arr[index + 1] = currEmp;
	}
	/*for (int i = 0; i < MAX ; i++){
		if (Arr[i].empID == -1){

		}
		else{
			cout << Arr[i].empID << endl;
		}
	}*/
}
int checkIDOrder(Employee Arr[MAX]){
	int index = -1;
	for (int i = 0; i < MAX - 1; i++){
		if (Arr[i].empID == -1){

		}
		else if (Arr[i].empID == Arr[i + 1].empID){
			sortString(Arr, i);

		}
		else if (Arr[i].empID > Arr[i + 1].empID){
			index = i;
			return index;
		}
	}
	return index;
}

//SORT BY SALARY
void sortBySal(Employee Arr[MAX]){
	int i = 0;
	int index;
	Employee currEmp;
	
	while (checkSalOrder(Arr) >= 0){
		//cout << "boi";
		index = checkSalOrder(Arr);
		//printHeader();
		//printEmp(Arr[index]);
		currEmp = Arr[index];
		Arr[index] = Arr[index + 1];
		Arr[index + 1] = currEmp;
	}
	/*for (int i = 0; i < MAX; i++){
		if (Arr[i].gsal == 0 || Arr[i].gsal==-1){

		}
		else{
			cout << Arr[i].gsal << endl;
		}
	}*/
}
int checkSalOrder(Employee Arr[MAX]){
	int index = -1;
	
	for (int i = 0; i < MAX - 1; i++){
		
		if (Arr[i].gsal == -1 || Arr[i].gsal == 0){
			
		}
		else if (Arr[i].gsal == Arr[i + 1].gsal){
			
			sortString(Arr, i);
			

		}
		else if (Arr[i].gsal > Arr[i + 1].gsal){
			index = i;
			
			return index;
		}
		
	}
	return index;
}

//SEARCH
int searchByName(Employee Arr[MAX], string sName){
	
	
	for (int i = 0; i < MAX; i++){
		if (Arr[i].lName == sName){
			return i;
		}
	}
	return -1;
}
int searchByID(Employee Arr[MAX], int sID){
	for (int i = 0; i < MAX; i++){
		if (Arr[i].empID == sID){
			return i;
		}
	}
	return -1;
}

//PRINT SUB MENU
void printSubMenu(){
	cout << "'F' - Print to file" << endl;
	cout << "'C' - Print to Console" << endl;
}
void subList(Employee Arr[MAX]){
	string filename;
	ofstream fout;
	char selection2;
	printSubMenu();
	selection2 = makeSelect();

	switch (selection2){
		case 'F':
		case 'f':
		
			cout << endl << "Please give an output file name: ";
			getline(cin, filename);
			fout.open(filename);
			fout << left << showpoint << fixed << setprecision(2);
			printAllEmpTF(Arr,fout);

			break;
		case 'C':
		case 'c':
			printAllEmp(Arr);
			break;
	
		default:
			cout << endl << "Error: thats not an option" << endl;

		}
}

void exitProgram(){

	cout << "Goodbye" << endl;
	exit(0);
}
