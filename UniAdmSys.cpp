#include <iostream>
#include <fstream> 
using namespace std;

struct UniAdm {
	string name;
	string course;
	int matrix;
	string phone;
	string village;
	string nationality;
};

UniAdm student[100];

void inputRec();
void deleteRec();
void searchRec();
void editRec();
void displayRec();
void displayAllRec();
void displayTOscreen(int i, int k);
void readFROMfile(int &j);	//j is total number of student
void writeTOfile(int j);

int main(){
	
	int option;
	
    do {
	 system("CLS");
	 cout << "\n\n\n\t*** University admission System ***" << endl;
	 cout << "\t1. INPUT NEW RECORD" << endl;
	 cout << "\t2. DELETE A RECORD" << endl;
	 cout << "\t3. SEARCH RECORD" << endl;
	 cout << "\t4. EDIT RECORD" << endl;
	 cout << "\t5. DISPLAY A RECORD" << endl;
	 cout << "\t6. DISPLAY ALL RECORDS" << endl;
     cout << "\t7. QUIT" << endl << endl;
	 cout << endl;
	 cout << "\tEnter option : ";
	 cin >> option;	
	 
     switch (option){
	 case 1 : inputRec();		break;
	 case 2 : deleteRec();		break;
	 case 3 : searchRec();		break;
	 case 4 : editRec ();		break;
	 case 5 : displayRec();		break;
	 case 6 : displayAllRec();	break;
	 case 7 : cout << "\n\tProgram ends" << endl; }
    } while (option != 7);
	
	return 0;
}

void inputRec (){ 			/********************************************************************************/
	
	UniAdm newRec;
	system("CLS");
	
	// open a file in write mode.
	ofstream outfile;
	outfile.open("UniAdmSys.txt", ios::app );
	
	// get data
	cout << "\n\n\n\tEnter the following details: " << endl;
	cout << "\t1. Name : ";			cin >> newRec.name;
	cout << "\t2. Course : ";		cin >> newRec.course;
	cout << "\t3. ID Matrix : ";	cin >> newRec.matrix;
	cout << "\t4. Phone no. : ";	cin >> newRec.phone;
	cout << "\t5. Village : ";		cin >> newRec.village;
	cout << "\t6. Nationality : ";	cin >> newRec.nationality;
	
	// write inputted data into the file.
	outfile << endl << newRec.name << "\t\t";
	outfile << newRec.course << "\t\t";
	outfile << newRec.matrix << "\t\t";
	outfile << newRec.phone << "\t\t";
	outfile << newRec.village << "\t\t";
	outfile << newRec.nationality;
	
	// close the opened file.
	outfile.close();
}
void deleteRec(){ 			/********************************************************************************/
	
	int i, j, k=-1, search, option;
	
	system("CLS");
	readFROMfile(j);
	
	cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	
	for (i=0; i<=j; i++)
		displayTOscreen(i,i+1);
	
	do {
		cout << "\n\tEnter ID which data to delete : ";
		cin >> search;
		
		for(i=0;i<=j;i++){
	 		if (search == student[i].matrix)
	 		k = i;
	 	}
		
    } while (k<0 || (k>j+1));
	
	for (i=k; i<j; i++){
		student[i].name = student[i+1].name;
		student[i].course = student[i+1].course;
		student[i].matrix = student[i+1].matrix;
		student[i].phone = student[i+1].phone;
		student[i].village = student[i+1].village;
		student[i].nationality = student[i+1].nationality;
	}
	
	j--;
	writeTOfile(j);
}
void searchRec(){ 			/********************************************************************************/
	
	int i, j, k=0, option;
	UniAdm search;
	
	readFROMfile(j);
	
	do {
	 system("CLS");
	 cout << "\n\n\n\tPlease choose either one method for searching" << endl;
	 cout << "\t1. Name" << endl;
	 cout << "\t2. Course" << endl;
	 cout << "\t3. ID Matrix" << endl;
	 cout << "\t4. Phone no." << endl;
	 cout << "\t5. Village" << endl;
	 cout << "\t6. Nationality" << endl << endl;
	 cout << endl;
	 cout << "\tEnter option : ";
	 cin >> option;
	 
	 //system("CLS");
	 cout << "\n\tEnter the information" << endl;
	 
	 do {
     switch (option){
	 case 1 :	cout << "\tName : ";
	 			cin >> search.name;
	 			
	 			system("CLS");
	 			cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	 			
	 			for(i=0;i<=j;i++){
	 				if (search.name == student[i].name){
	 					k++;
	 					displayTOscreen(i, k);
					 }
				 }
	 			break;
	 case 2 : 	cout << "\tCourse : ";
	 			cin >> search.course;
	 			
	 			system("CLS");
	 			cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	 			
	 			for(i=0;i<=j;i++){
	 				if (search.course == student[i].course){
	 					k++;
	 					displayTOscreen(i, k);
	 				 }
				 }
	 			break;
	 case 3 : 	cout << "\tID Matrix : ";
	 			cin >> search.matrix;
	 			
	 			system("CLS");
	 			cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	 			
	 			for(i=0;i<=j;i++){
	 				if (search.matrix == student[i].matrix){
	 					k++;
	 					displayTOscreen(i, k);
	 				 }
				 }
	 			break;
	 case 4 : 	cout << "\tPhone no. : ";
	 			cin >> search.phone;
	 			
	 			system("CLS");
	 			cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	 			
	 			for(i=0;i<=j;i++){
	 				if (search.phone == student[i].phone){
	 					k++;
	 					displayTOscreen(i, k);
	 				 }
				 }
	 			break;
	 case 5 : 	cout << "\tVillage : ";
	 			cin >> search.village;
	 			
	 			system("CLS");
	 			cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	 			
	 			for(i=0;i<=j;i++){
	 				if (search.village == student[i].village){
	 					k++;
	 					displayTOscreen(i, k);
	 				 }
				 }
	 			break;
	 case 6 :  	cout << "\tNationality : ";
	 			cin >> search.nationality;
	 			
	 			system("CLS");
	 			cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	 			
	 			for(i=0;i<=j;i++){
	 				if (search.nationality == student[i].nationality){
	 					k++;
	 					displayTOscreen(i, k);
	 				 }
				 }
	 			break;}
	 if (k==0){
	 	system("CLS");
	 	cout << "\n\tNo such data, enter the information again.\n";
	 }
	 	
		} while (1<=option && option<=6 && (k==0));
    } while (option<1 || option>6);
	
	int opt;
	cout << "\n\n\n\tEnter any number to back to main menu : ";
	cin >> opt;
	
}
void editRec (){ 			/********************************************************************************/
	
	int i, j, k=-1, option;
	UniAdm search;
	
	readFROMfile(j);
	
	system("CLS");
	cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	
	for (i=0; i<=j; i++)
		displayTOscreen(i,i+1);
	
	do {
		cout << "\n\n\tWhich one do want to edit: ";
		cin >> k;
    } while (k<1 || (k>j+1));
	k--;
	
	system("CLS");
	do {
	 cout << "\n\n\tEnter which one do want to edit:" << endl;
	 cout << "\n\t1. Name		: " << student[k].name;
	 cout << "\n\t2. Course	: " << student[k].course;
	 cout << "\n\t3. ID Matrix 	: " << student[k].matrix;
	 cout << "\n\t4. Phone no.	: " << student[k].phone;
	 cout << "\n\t5. Village	: " << student[k].village;
	 cout << "\n\t6. Nationality	: " << student[k].nationality;
	 cout << "\n\n\tEnter option : ";
	 cin >> option;
	 
	 system("CLS");
	 cout << "\n\n\tOld data : ";
	 
     switch (option){
	 case 1 :	cout << student[k].name << endl;
	 			cout << "\tNew data : ";
	 			cin >> student[k].name;
	 			break;
	 case 2 :	cout << student[k].course << endl;
	 			cout << "\tNew data : ";
	 			cin >> student[k].course;
	 			break;
	 case 3 : 	cout << student[k].matrix << endl;
	 			cout << "\tNew data : ";
	 			cin >> student[k].matrix;
	 			break;
	 case 4 : 	cout << student[k].phone << endl;
	 			cout << "\tNew data : ";
	 			cin >> student[k].phone;
	 			break;
	 case 5 : 	cout << student[k].village << endl;
	 			cout << "\tNew data : ";
	 			cin >> student[k].village;
	 			break;
	 case 6 :  	cout << student[k].nationality << endl;
	 			cout << "\tNew data : ";
	 			cin >> student[k].nationality;
	 			break;}
	 	
    } while (option<1 || option>6);
	
	writeTOfile(j);
}
void displayRec (){ 		/********************************************************************************/
	
	int i, j, k=-1, option;
	int search;
	
	readFROMfile(j);
	
	do {
	 system("CLS");
	 cout << "\n\n\tEnter ID : ";
	 cin >> search;
	 			
	 for(i=0;i<=j;i++){
	 	if (search == student[i].matrix)
	 	k = i;
	 }
	 	
    } while (k==-1);
	
	system("CLS");
	cout << "\n\n\n\tName		: " << student[k].name;
	cout << "\n\tCourse		: " << student[k].course;
	cout << "\n\tID Matrix 	: " << student[k].matrix;
	cout << "\n\tNationality	: " << student[k].nationality;
	cout << "\n\tPhone no.	: " << student[k].phone;
	cout << "\n\tVillage		: " << student[k].village;
	
	int opt;
	cout << "\n\n\n\tEnter any number to back to main menu : ";
	cin >> opt;
}
void displayAllRec (){ 		/********************************************************************************/
	
	int i=0, j=-1;
	
	system("CLS");
	readFROMfile(j);
	
	cout << "No.\t>Name \t>Course >ID \t>Phone no. \t>Village \t>Nationality" << endl;
	
	for (i=0; i<=j; i++)
		displayTOscreen(i,i+1);
	
	int opt;
	cout << "\n\n\n\tEnter any number to back to main menu : ";
	cin >> opt;
	
}
void displayTOscreen(int i, int k){	/************************************************************************/
	
	// display data at the screen
	cout << k << ".\t" << student[i].name;
	cout << "\t" << student[i].course;
	cout << "\t" << student[i].matrix;
	cout << "\t" << student[i].phone;
	cout << "\t" << student[i].village;
	cout << "\t\t" << student[i].nationality << endl;
	
}
void readFROMfile(int &j){ 	/********************************************************************************/
	
	int i=0;
	ifstream infile; 
	infile.open("UniAdmSys.txt"); 
	if (!(infile.is_open()))
		cout << "\n\n\tFile not found\n\n\n\n\n";
	else{
	// read the data from the file
	while (!infile.eof()){
		
		infile >> student[i].name;
		infile >> student[i].course;
		infile >> student[i].matrix;
		infile >> student[i].phone;
		infile >> student[i].village;
		infile >> student[i].nationality;
		j=i;
		i++;
	}
	}
	
	if (j==-1)
		cout << "File is empty";
	
	infile.close();
	
}
void writeTOfile(int j){ 	/********************************************************************************/
	
	int i=0;
	
	// open a file in write mode.
	ofstream outfile;
	outfile.open("UniAdmSys.txt");
	
	// write inputted data into the file.
	for (i=0; i<=j; i++){
		outfile << endl << student[i].name << "	";
		outfile << student[i].course <<  "	";
		outfile << student[i].matrix <<  "	";
		outfile << student[i].phone <<  "	";
		outfile << student[i].village <<  "	";
		outfile << student[i].nationality;
	}
	
	// close the opened file.
	outfile.close();
	
}
