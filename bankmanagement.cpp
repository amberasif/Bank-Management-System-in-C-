#include <iostream>// to perform cin cout 
#include <fstream>//use file streams
#include <iomanip>// for error bits
#include <string>//string class for string fucntions
#include <cctype>// for isalpha,ispunct,isdigit,type check functions
#include <cstring>//string class
#include <sstream>//string stream, convert integer in string
#include <string.h>//string library
#include <stdio.h>//getch()
#include <conio.h>//console
#include <stdlib.h>//standard library, atoi, string to integer
#include <windows.h>// showmessages,buttons
using namespace std;

class BasicInfo{          // base class 
	protected:
unsigned long int id;
		char uname[20];
		char password[20];
		char fname[20];
		char lname[20];
		char dob[12];
		unsigned int balance=0;

};
class Account:public BasicInfo{      // inheritance

		public:
			void getfname();//get first name
			void getlname();//get last name
			void getuname();//get user name
			void getpassword();//get password
			void getdata();// get all the basic data
			void getdate();//get date of birth
			void getid(unsigned long int);//get acount number
			int validateid();//check if id is correct
			void displaydata();//display data of the user
			int checkstring(string str);//check if it contains alphabets only
			int checkpassword(string str);//check alpha numeric requirements
			int checknumber(string str);//check digits only
			int checkdate(int,int,int);//check if date is correct
			void storedata();//store data in file
			void getfromfile();//retrieve data from file
			int searchid (unsigned long int i);//search id in file
			int checkaccount(unsigned long int);
			void viewall();//display all records
			void Delete(char*,char*);//delete account
			void Updatebasicdata(char*,char*);//calls Modifybasicdata() and store in file
			void Modifybasicdata();//modify data
			void getbalance();//get balance 
			void Updateamount(char* p,char*t,char c);// update balance in file
				int withdrawamount();//takes amount and also checks if balance is enough
					void depositamount();//takes amount
					void operator -(int);// operator overloading function
					void operator +(int);// operator overloading function
					int getchoice(string);//takes choice and validates it
			
};
int Account::checkstring(string str){
int x=1;
    for(int i=0; (i<str.length());){

x=isalpha(str[i]);// if character is alphabet then returns 2 else returns 0
     if(x!=0){// if character is an alphabet 

     i++;// move to next index and check it
	 }
   else if (x!=2){// if not an alphabet
   	MessageBox(NULL,"Please enter a valid string","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

   	break;// break from the loop 
   	x=0;// set x=0 for later comparison
   break;// finally break
   }

    }

if(x==0)// if not alphabet
    return 1;// return 1 to take string again
    else return 0;// All set!! Perfect!



}
 int Account::checkpassword(string str){
 int s=1,d=1,u=1,l=1,c,space;// initialization, can be declared only as well


     for(int i=0; (i<str.length());){
       d=isdigit(str[i]);// checks if digit
       if(d!=0)// if digit
       break;// break from checking futher to another check
       else
     i++;// move to next index if not a digit
 }
 if(d!=0){// if a digit
   for(int i=0; (i<str.length());){
u=isupper(str[i]);// check if upper case
     if(u!=0)// yes it's an upper case
     break;// stops from checking furhter and move to another check
     else
     i++;// move to another character if not an upper case
 }
 if(u!=0){// if upper case is true
     for(int i=0; (i<str.length());){

l=islower(str[i]);// checks if lower
     if(l!=0)//if character is in lower case
     break;// break from futher checking to another check
     else
     i++;// else move to another character and keep checking if lower
 }
 if(l!=0){// if lower is found
     for(int i=0; (i<str.length());){

c=ispunct(str[i]);// checks for special character
     if(c!=0)// special character found!!
     break;// break from checking futher to another check
     else
     i++;// else check for another character
 }
 if(c!=0){
     for(int i=0; (i<str.length());){

  space=(!str[i]);// if space in the password
  if(space!=0)// if space found then break from futher checking
     break;
     else
     i++;// else check rest of the characters
 }
 if (space==0)// if space not found then perfect, return 0, which indicates that password is PERFECT
 return 0;
 else return 1;// EHEM!! Not fulfilling the requirements,too weak
 }
 else {
 	   	MessageBox(NULL,"Enter an alpha numeric password with upper and lower case","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
// If any of the requirements doesn't get fulfilled, ERROR MESSAGE
 return 1;// Weak Password
}
 }
 else {
 	   	MessageBox(NULL,"Enter an alpha numeric password with upper and lower case","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
 // If any of the requirements doesn't get fulfilled, ERROR MESSAGE
 return 1;// Weak Password
}
 }
 else {
 	   	MessageBox(NULL,"Enter an alpha numeric password with upper and lower case","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
 // If any of the requirements doesn't get fulfilled, ERROR MESSAGE
 return 1;// Weak Password
}

 }
 else {
 	   	MessageBox(NULL,"Enter an alpha numeric password with upper and lower case","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
 // If any of the requirements doesn't get fulfilled, ERROR MESSAGE
 return 1;// Weak Password
}
}
int Account::validateid(){// checks if id is 5 digits long and is an unsigned integer only
		 int n=1;
		unsigned long int i;
	while(n==1){// until correct

     	while(1){// until no error bits
		cin.unsetf(ios::skipws);// donot skip empty inputs and whitespaces
		cout<<"\nEnter Account Number: ";
		cin>> i;

		if(cin.good()){// if input is correct 
			cin.ignore(1000,'\n');
			n=0;// perfect
			break;// break from the loop
			}

cin.clear();// clear the buffer
 	   	MessageBox(NULL,"INVALID!!!","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);// error message if requirements not fulfill
cin.ignore(1000,'\n');

	}
	if(i>99999||i<10000){// must be 5 digits
			n=1;
 	   	MessageBox(NULL,"INVALID!! ENTER 5 DIGIT ID","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
			}
			else n=0;
			cin.clear();
			}
if(n==0)
return i;

cin.clear();

}
void Account::getid(unsigned long int i){// after validating id, set id
	id=i;
}
void Account::getfname(){// gets first name
	 int n=1;// 1 indicates that string is incorrect, for futher check it is initialized 1

    while(n==1){// takes first name until n=0
        cout<<"\n\nEnter First name: ";

    cin.getline(fname,10);// takes first 10 characters only
    string fn=fname;// converting to string to use string class functions

    n=fn.empty();// checks if user entered an empty string or not
    if (n==1){// if empty
 	   	MessageBox(NULL,"CAN'T BE LEFT BLANK","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);// display error message
    }
    else {
    n=checkstring(fn);// if not blank then check if string doesnt contain digits or special character
}
}

}
void Account::getlname(){// get last name 
	 int n=1;
    while(n==1){// until input is correct

        cout<<"\n\nEnter last name: ";
    cin.getline(lname,10,'\n');
    string ln=lname;// array to string
    n=ln.empty();// string class member function to check if empty or not
    if (n==1){// if empty
 	   	MessageBox(NULL,"CAN'T BE LEFT BLANK","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
    }
    else {
    n=checkstring(ln);// if not empty then check alphabets only
}
}

}
void Account::getuname(){// get username
	 int n=1;



    while(n==1){// until correct input
        cout<<"\n\nEnter username: ";

     cin.getline(uname,10,'\n');
    string un=uname;
    n=un.empty();// checks empty or not
    if(n==1){// if empty
 	   	MessageBox(NULL,"CAN'T BE LEFT BLANK","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
}
    }
    
}
void Account::getpassword(){// takes password
	 int n=1;

    while(n==1){
    cout<<"\n\t\tPassword Must Be greater than 8";// 8-15 characters long
while(n==1)
{
    cout<<"\n\nPassword: ";
    char p;// passwords character by character
    for(int i=0;i<20;){
    	p=getch();// get character
    	if((p!='\b')&&(p!='\r')){// if not backspace or enter key pressed

    	password[i]=p;
        ++i;
		cout<<"*"; }// output stars to hide password
		else if(p=='\b'&&i>=1){// if backspace and atleast one character on the screen

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){// if enter pressed
			password[i]='\0';// null in the last character to terminate
			break;
		}
	}
      
    string pass=password;// array to string
    n=pass.empty();// checks if empty
    if (n==1)
 	   	MessageBox(NULL,"CAN'T BE LEFT BLANK","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
    else {
        if (pass.length()<8){
 	   	MessageBox(NULL,"PASSWORD TOO SHORT","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
        n=1;

    }
    else if(pass.length()>15){// must be less than 16
         	   	MessageBox(NULL,"PASSWORD TOO LONG","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

        n=1;
    }
        else {
        n=checkpassword(password);// checks if an alpha numeric password with upper and lower case
    }
}
}

if(n==0)
{char pass2[20];
	cout<<"\n\nConfirm your password: ";// password confirmation
	 char p;
    for(int i=0;i<20;){
    	p=getch();
    	if((p!='\b')&&(p!='\r')){

    	pass2[i]=p;
        ++i;
		cout<<"*"; }
		else if(p=='\b'&&i>=1){

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){
			pass2[i]='\0';
			break;
		}
	}

	if(!strcmp(pass2,password)){// compare both the passwords

	n=0;}
	else{
 	   	MessageBox(NULL,"PASSWORD DIDN'T MATCH","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
	 n=1;
}
}
}
//Successful
}
void Account::getdata(){

getfname();// get first name
getlname();// get last name
getuname();// get user name
getpassword();// get password name
getdate();// get dob
getbalance();// get initial balance

}
void Account::getbalance(){

     	while(1){// until unsigned integer only
		cin.unsetf(ios::skipws);
		cout<<"\n\nEnter Balance: ";
		cin>> balance;

		if(cin.good()){
			cin.ignore(1000,'\n');
			break;
			}

cin.clear();
 	   	MessageBox(NULL,"INVALID!!!","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');

	}
}
void Account::getdate(){

char year[5];
char day[3];
char month[3];
char date[12];

int y,m,d;// year, month, day
int n=1;
while (n==1){
        cout<<"\n\nEnter DATE OF BIRTH in yy/mm/dd format\n";
	while(true){
		cin.unsetf(ios::skipws);
		cout<<"\n\nEnter year:  ";
cin.getline(year,5);
 y= atoi(year);// change string in int
		if(cin.good()){

			break;
			}
cin.clear();
 	   	MessageBox(NULL,"INCORRECT YEAR","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');
	}
//cout<<y;
while(true){
		cin.unsetf(ios::skipws);
		cout<<"\n\nEnter month:  ";
cin.getline(month,3,'\n');
 m=atoi(month);// change string in integer
		if(cin.good()){

			break;
			}
cin.clear();
 	   	MessageBox(NULL,"INCORRECT MONTH","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');
	}

while(true){
		cin.unsetf(ios::skipws);
	cout<<"\n\nEnter day:  ";

cin.getline(day,3,'\n');
 d=atoi(day);
		if(cin.good()){
			
			break;
			}
cin.clear();
 	   	MessageBox(NULL,"INCORRECT DAY","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');
	}


n=checkdate(y,m,d);// passing integer values of year, month and day
}

if(strlen(month)==1){//  if 1 to 9 entered
	int temp;
temp=month[0];
month[0]='0';
month[1]=temp;//if month is 2 then set 02, just an example
}


if(strlen(day)==1){//  if 1 to 9 entered
	int temp;
temp=day[0];
day[0]='0';
day[1]=temp;//if day is 2 then set 02 just an example
}
 int i=0;
for( int j=0;j<2;j++){

	date[i++]=day[j];

}

date[i++]='-';// separate day month and year with -
	for(int j=0;j<2;j++){
	date[i++]=month[j];

}
date[i++]='-';
	for(int j=0;j<4;j++){
	date[i++]=year[j];
}
cout<<"\nDate:  "<<date;
strcpy(dob,date);// copy array to actual data member of date

}
int Account::checkdate(int year,int month, int day)
{
     int n=1;
    if((1000 <= year )&&(year<= 2015))
       {
         if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && day>0 && day<=31)// 31 days exist in 1,3,5,7,8,10,12 months only
         n=0;
         else
     if(month==4 || month==6 || month==9|| month==11 && day>0 && day<=30)
                     n=0;
         else
            if(month==2)
               {
               if((year%400==0 || (year%100!=0 && year%4==0)) && day>0 && day<=29)// checks leap year
                         n=0;
               else if(day>0 && day<=28)
                          n=0;
               else{
               	 n=1;
 	   	MessageBox(NULL,"Day,Month,or Year out of range... Please enter again","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

               	 
			   }


               }
        else{
               	 n=1;
 	   	MessageBox(NULL,"Day,Month,or Year out of range... Please enter again","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
			   }
      }
    else{
               	 n=1;
 	   	MessageBox(NULL,"Day,Month,or Year out of range... Please enter again","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
			   }

 return n;
}
	void Account::displaydata(){


		cout<<id<<"		"<<uname<<"	      "<<fname<<" "<<lname<<"          "<<dob<<"      "<<balance<<endl;
	}
	void Account::storedata(){

        ofstream f;
        f.open("BasicInfo.txt",ios::app|ios::binary);// opens binary file in append mode 
        f.write((char*)this,sizeof(*this));// open file in write mode write object, and  size of object indicated by sizeof(*this)
        f.close();

	}
	int Account::searchid(unsigned long int i){

    int flag=0;
    ifstream in;
        in.open("BasicInfo.txt",ios::in|ios::binary);
  
        in.read((char*)this,sizeof(*this));// read from file, where to read, size?
        while(!in.eof())
        {
            if(i==id)
            {
            
            	flag=1;
        cout<<"__________________________________________________________________________"<<endl;
            	cout<<"Acc.Number			"<<"User Name	 "<<"Name"<<"    "<<"Balance"<<endl;
		cout<<"__________________________________________________________________________"<<endl;
            	displaydata();
            	break;

            }
                    in.read((char*)this,sizeof(*this));

}
if (flag==0)
{
    
    return 0;

}
else return 1;
in.close();

	}
	int Account::checkaccount(unsigned long int i){

    int flag=0;
    ifstream in;
        in.open("BasicInfo.txt",ios::in|ios::binary);
   // if(!in)
    //{
     //   cout<<"\nfile not found";


    //}
    //else
    //{
        in.read((char*)this,sizeof(*this));// read from file, where to read, size?
        while(!in.eof())
        {
            if(i==id)
            {
            
            	flag=1;
            	break;

            }
                    in.read((char*)this,sizeof(*this));

}
if (flag==0)
{
    
    return 0;

}
else return 1;
in.close();

	}//}
		
	void Account::viewall()	{

	Account ac;
	ifstream inFile;
	inFile.open("BasicInfo.txt",ios::binary);
	if(!inFile)
	{
		 	   	MessageBox(NULL,"File could not be open !! Press any Key...","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

		

	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=====================================================================\n";
	cout<<"A/c no.           USER NAME         NAME            DOB       Balance\n";
	cout<<"=====================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))// type casting, data stores character wise in file
	{
		ac.displaydata();
	}
	inFile.close();
}

void Account::Delete(char* p,char*t)// passing array reference
    {

        int pos, flag = 0;

    ifstream ifs;
    ifs.open("BasicInfo.txt", ios::in | ios::binary);

    ofstream ofs;
    ofs.open("temp.dat", ios::out | ios::binary);

    while (!ifs.eof()){

        ifs.read((char*)this, sizeof(Account));

        // if(ifs)checks the buffer record in the file
        if (ifs) {

            
            if ((!strcmp(p,password)) &&(!strcmp(t,uname))){// if username and corresponding password match

                flag = 1;
                

                // display the record
                displaydata();
            }
            else {
                // copy the record of "BasicInfo" file to "temp" file
                ofs.write((char*)this, sizeof(Account));
            }
        }
    }


    ofs.close();
    ifs.close();


    // delete the old file
    remove("BasicInfo.txt");

    // rename new file to the older file
    rename("temp.dat", "BasicInfo.txt");

    if (flag == 1)
        cout << "\n\n\t\tRecord Successfully Deleted \n";
    else
		 	   	MessageBox(NULL,"RECORD NOT FOUND","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
}
int Account::getchoice(string str){// parameter for displaying later in the prog what to update
		int choice;
  	int n=1;
  	while(n==1){

  	cout<<str;// Give choice to user whether to update or not
  	while(true){
		cin.unsetf(ios::skipws);
		cout<<"\nChoice: ";
		cin>> choice;
		if(cin.good()){
			cin.ignore(1000,'\n');
			break;
			}
cin.clear();
		 	   	MessageBox(NULL,"INVALID CHOICE","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');
	}
	if((choice!=2)&&(choice!=1)){
		 	   	MessageBox(NULL,"INVALID CHOICE","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
	n=1;
	getch();

}
else
n=0;
cin.clear();
}
if (choice==1)
return 1;
else return 0;



}
  void Account:: Modifybasicdata(){

  	int choice;

  	choice=getchoice("\n\n\t\tUpdate First Name??    1-Yes  2-No");
  	if (choice==1)
  	{

  		getfname();
	  }


  	choice=getchoice("\n\n\t\tUpdate Last Name??    1-Yes  2-No");
  	if (choice==1)
  	{
  		getlname();
	  }

  	choice=getchoice("\n\n\t\tUpdate Password??    1-Yes  2-No");
  	if (choice==1)
  	{
  		getpassword();
	  }

  	choice=getchoice("\n\n\t\tUpdate DOB??    1-Yes  2-No");
  	if (choice==1)
  	{
  		getdate();
	  }

  }
void Account::Updatebasicdata(char*p,char*t)
{
	bool found=false;

	fstream File;
	File.open("BasicInfo.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
				 	   	MessageBox(NULL,"File could not be open !! Press any Key...","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

		return;
	}
	while(!File.eof() && found==false)// until record found or the file end
	{
		File.read(reinterpret_cast<char *> (this), sizeof(*this));
			if ((!strcmp(p,password)) &&(!strcmp(t,uname)))
		{
			displaydata();
			cout<<"\n\n\t\tEnter The New Details of account"<<endl;
			cin.ignore(0);
			Modifybasicdata();
			int pos=(-1)*static_cast<int>(sizeof(*this));// file pointer moves to next record so position of pointer-1
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (this), sizeof(*this));
			system("cls");// clear the screen
			cout<<"\n\n\t\t Record Updated\n\n";
			found=true;
			displaydata();
			getch();// pause screen until user presses any key
		  }
	}
	File.close();
	if(found==false)
				 	   	MessageBox(NULL,"RECORD NOT FOUND","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

}
void Account::operator +(int amount){
	balance+=amount;// object.balance+integer---------operator overloading definition

		}

		void Account::operator -(int amount){

			balance-=amount;// object.balance-integer--------- operator overloading definition

		}


	void Account:: Updateamount(char* p,char*t,char c){
			bool found=false;
			int n=1;

	fstream File;
	File.open("BasicInfo.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
				 	   	MessageBox(NULL,"File could not be open !! Press any Key...","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (this), sizeof(*this));
		if ((!strcmp(p,password)) &&(!strcmp(t,uname)))
		{found=true;
			if(c=='d'){// if deposit
			depositamount();
		}
		else
		n= withdrawamount();
		if (n==1)
{
			int pos=(-1)*static_cast<int>(sizeof(*this));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (this), sizeof(*this));
			cout<<"\n\n\t\t Record Updated\n\n";
    cout<<" ====================================================================\n";
	cout<<"A/c no.           USER NAME         NAME            DOB       Balance\n";
	cout<<"=====================================================================\n";
			displaydata();

		}  }
	}
	File.close();
	if(found==false)
				 	   	MessageBox(NULL,"RECORD NOT FOUND","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
		}
		void Account:: depositamount(){
			unsigned int amount;
   	while(1){
		cin.unsetf(ios::skipws);
		cout<<"\n\nEnter Amount: ";
		cin>> amount;

		if(cin.good()){
			break;
			}

cin.clear();
				 	   	MessageBox(NULL,"INVALID!!","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');

	}

	*this+amount;

	}
	int Account:: withdrawamount(){
		unsigned int amount;
	   	while(1){
		cin.unsetf(ios::skipws);
		cout<<"\n\nEnter Amount: ";
		cin>> amount;

		if(cin.good()){
			break;
			}

cin.clear();
				 	   	MessageBox(NULL,"INVALID","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');

	}
	if (balance>=amount){
	*this-amount;
	return 1;
	}
	else{
				 	   	MessageBox(NULL,"NOT ENOUGH BALANCE","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
		return 0;
	}
		}
int Menu();
void CreateAccount();
void UpdateAccount();
void DepositAmount();
void WithdrawAmount();
void ViewYourAccount();
void DeleteAccount();
void ViewAll();

	int main(){
	
		while(1){
			system("cls");
			switch(Menu())
			{
				case 1:

					cin.clear();
					 CreateAccount();
					
				
					break;
				case 2:

					UpdateAccount();
					break;
				case 3:

					DepositAmount();
					
					break;
				case 4:

					 WithdrawAmount();

					 break;
				case 5:

					ViewYourAccount();
					break;
				case 6:

				DeleteAccount();
					break;
						case 7:

				ViewAll();
					break;
					case 8:

						cout<<"\n\n\tThank you for using this application";
						cout<<"\n\n\tPress any key to exit";
						getch();
						exit(0);
						default:
				 	   	MessageBox(NULL,"INVALID CHOICE","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
							getch();
							cin.clear();
								}
		}

	}
int Menu(){
	int choice=0;
cin.clear();
cout<<"\n\n\t\t\t\t\tBANK MANAGEMENT SYSTEM\n";
	cout<<"\n\n\n\t\t\t\t1-Create Account";
	cout<<"\n\n\t\t\t\t2-Update Account";
	cout<<"\n\n\t\t\t\t3-Deposit Amount";
	cout<<"\n\n\t\t\t\t4-Withdraw Amount";
	cout<<"\n\n\t\t\t\t5-View Your Account";
	cout<<"\n\n\t\t\t\t6-Delete Account";
	cout<<"\n\n\t\t\t\t7-View All";
	cout<<"\n\n\t\t\t\t8-Exit";
	cout<<"\n\n\n\t\t\t\tEnter Your Choice\n";
	int n=1;

  	while(n==1){

  	while(true){
  		cin.clear();
		cin.unsetf(ios::skipws);
		cin.clear();
		cout<<"\n\t\t\t\tChoice: ";
		cin>> choice;
		if(cin.good()){
			cin.ignore(1000,'\n');
			break;
			}
cin.clear();
				 	   	MessageBox(NULL,"INCORRECT INPUT","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
cin.ignore(1000,'\n');

	}
	n=0;
cin.clear();
}
return choice;
cin.clear();
}
void CreateAccount(){
	system("cls");
	cout<<"\n\t\t\tCreate Account\n";
	 int found;
	unsigned long int checkid;
	Account ac;
cin.clear();
    checkid=ac.validateid();
	 found=	ac.checkaccount(checkid);// checks if id exists or not
	if (found==0){ // if doesnt exist
		ac.getid(checkid);
			ac.getdata();
	ac.storedata();

	}

				 	   	
	if(found==0){
		system("cls");
		cout<<"\n\n\t\t\tAccount Created Successfully";
		
		cin.clear();
	}
	else MessageBox(NULL,"RECORD EXIST","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

cin.clear();
	getch();

}
void UpdateAccount(){
	system("cls");
	cout<<"\n\t\t\tUpdate Account\n";
	Account a;
	char password[20];
		char user[20];

	cout<<"\nEnter username: ";
	
		cin.getline(user,10,'\n');
	
		cout<<"\nEnter password: ";
	 char p;
    for(int i=0;i<20;){
    	p=getch();
    	if((p!='\b')&&(p!='\r')){

    	password[i]=p;
        ++i;
		cout<<"*"; }
		else if(p=='\b'&&i>=1){

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){
			password[i]='\0';
			break;
		}
	}
	
	system("cls");
	cout<<"\n\n\n\t\t\t\tYour Record\n\n\n";
			a.Updatebasicdata(password,user);
				

}
void DepositAmount(){
	system("cls");
	cout<<"\n\t\t\tDeposit Amount\n";
	Account d;
char password[20];
char user[20];
char p;

	cout<<"\nEnter username: ";

		cin.getline(user,10,'\n');

		cout<<"\nEnter password: ";
	for(int i=0;i<20;){
    	p=getch();
    	if((p!='\b')&&(p!='\r')){

    	password[i]=p;
        ++i;
		cout<<"*"; }
		else if(p=='\b'&&i>=1){

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){
			password[i]='\0';
			break;
		}
	}

	d.Updateamount(password,user,'d');
		cin.ignore(1000,'\n');
getch();
	cin.clear();
}
void WithdrawAmount(){
	system("cls");
	cout<<"\n\t\t\t Withdraw Amount\n";
	Account w;
char password[20];
char user[20];
char p;

	cout<<"\nEnter username: ";

		cin.getline(user,10,'\n');
	
		cout<<"\nEnter password: ";
	for(int i=0;i<20;){
    	p=getch();
    	if((p!='\b')&&(p!='\r')){

    	password[i]=p;
        ++i;
		cout<<"*"; }
		else if(p=='\b'&&i>=1){

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){
			password[i]='\0';
			break;
		}
	}

	w.Updateamount(password,user,'w');
cin.ignore(1000,'\n');
getch();
	cin.clear();

}
void ViewYourAccount(){

	system("cls");
	cout<<"\n\t\t\tView Your account\n\n";
	int found=0;
	unsigned long int checkid;
	Account v;

    checkid=v.validateid();
	 found=	v.searchid(checkid);
	 if(found==0)
	 	   	MessageBox(NULL,"RECORD NOT FOUND","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);

	 	getch();
}
void DeleteAccount(){
	system("cls");
	cout<<"\n\t\t\tDelete Account\n\n";
	Account da;
char password[20];
char user[20];
char p;

	cout<<"\nEnter username: ";
	
		cin.getline(user,10,'\n');
	
		cout<<"\nEnter password: ";
	for(int i=0;i<20;){
    	p=getch();
    	if((p!='\b')&&(p!='\r')){

    	password[i]=p;
        ++i;
		cout<<"*"; }
		else if(p=='\b'&&i>=1){

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){
			password[i]='\0';
			break;
		}
	}
	
	da.Delete(password,user);
		getch();

}
void ViewAll(){
	system("cls");
		cout<<"\n\t\t\tView All\n\n";
	Account va;
	char pin[]="99113322";
	char username[]="AdminBBMM23";
	char u[13];
	char pinc[9];
	char p;

cout<<"\nEnter user name: ";
	cin.getline(u,13);
cout<<"\nEnter pin";
	for(int i=0;i<10;){
    	p=getch();
    	if((p!='\b')&&(p!='\r')){

    	pinc[i]=p;
        ++i;
		cout<<"*"; }
		else if(p=='\b'&&i>=1){

		cout<<"\b \b";
		--i;}
		else if(p=='\r'){
			pinc[i]='\0';
			break;
		}
	}

	if((!strcmp(u,username)&&(!strcmp(pin,pinc)))){// checking if pin and username match no not
		va.viewall();
		
	}
	else{

				 	   	MessageBox(NULL,"INCORRECT PIN OR USERNAME","BANK MANAGEMENT SYSTEM",MB_ICONERROR|MB_OK);
	cin.clear();

}

	getch();
	cin.clear();
}


