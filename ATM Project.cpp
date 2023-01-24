// Final Project Submited by Abdullah Lalwani,Ahmad Shazad,Furqan Javaid.
// Bs Data Science 1st semester
// ATM machine.
#include<iostream>
#include<fstream>
#include<ctime>
#include<windows.h>
using namespace std;
ofstream transactionHistory;
void showMenu()
{   cout<<"******************************************************************************************"<<endl;
	cout<<"****************MENU*****************";
	cout<<"\n\n\t 1) Check Balance";
	cout<<"\n\n\t 2) Deposite";
	cout<<"\n\n\t 3) Withdraw";
	cout<<"\n\n\t 4) Transection Record";
	cout<<"\n\n\t 5) Exit \n";
	cout<<"*************************************"<<endl;
	cout<<"******************************************************************************************"<<endl;
}
int main()
{  
HANDLE hConsole=
GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
transactionHistory.open("transaction_history.txt",ios::app);
	time_t now = time(0);
	char* date_time = ctime(&now);
	int pwd1=1234,pwd2;
	int attempt=3;
	double accNum1=1234506789101112,accNum2;
	cout<<endl<<"\tWelcome !"<<endl;
		while (attempt>0)
	{
	cout<<endl<<"Enter your Account number = ";
	cin>>accNum2;
	cout<<"Enter your Password = ";
	cin>>pwd2;
	if(pwd2==pwd1&&accNum2==accNum1)
    {
			cout<<"\n You are login.\n";
    	cout << "The current date and time is: " << date_time << endl;
   
    
	int option;
	double balance =5000;
	while(option!=5){
	showMenu();
		cout<<"Chose any option: ";
		cin>>option;
	    system("cls");
		switch (option)
		{
			case 1:cout<<"\n\tYour balance is : "<<balance<<"$"<<endl;
			     cout<<endl;
			break;
			case 2:cout<<endl;
			cout<<"\tDeposite Amount : ";
			 double depositeAmount;
			 cin>> depositeAmount ;
			 balance += depositeAmount;
			 cout << "\tYour new balance is: " << balance << endl;
			  transactionHistory << "Deposit Amount = " << depositeAmount << ",\n " << date_time << endl;
			 break;
		case 3:cout<<endl;
		cout<<"\tWithdraw Amount :";
		 double withdrawAmount;
		 cin >>withdrawAmount;
		 if(withdrawAmount <= balance){
		 
		   balance-= withdrawAmount;
		    transactionHistory << "Withdrawal Amount " << withdrawAmount << ",\n " << date_time << endl;
	}	else
		  {
		  cout<<endl<<"\tYou have not enough Money to withdraw from your Account."<<endl;
		  }
		  cout<<"\tYour remaining balance is :"<<balance<<endl;
		  break;
		  case 4:
    cout << endl;
    cout << "Transaction History:" << endl;
    string line;
    ifstream historyFile("transaction_history.txt");
    if (historyFile.is_open())
    {
        while (getline(historyFile, line))
        {
            cout << line << endl;
        }
        historyFile.close();
    }
    else
    {
        cout << "Unable to open transaction history file." << endl;
    }
    break;

		}
    }

    cout<< "\t THANK YOU FOR USING ATM"<<endl;
}
else
	{
		cout<<"Please enter the correct Password and Account Number. \n"<<attempt-1<<" Attemps are Remaning.";
		attempt--;
	
	}

}
//return;
}

