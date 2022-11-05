#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;
string itos(int i)
{
     stringstream s;
     s << i;
     return s.str();
}
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
void FrontDesinge();
void Manu();
void ABOUT();
class PNB
{
private:
     char AccountNumber[15];
     char Balance[12];
     char AccountHolderName[30];
     char FatherName[30];
     char AadhaarNumber[15];
     char Age[3];
     char Gender;
     char MobileNumber[11];
     char EmailAddress[30];
     char Address[30];
     char Date[11];
     char Tpin[6];
     static char IFSC_CODE[9];

public:
     PNB(int x) {}
     void ALLRecord();
     void Print()
     {
          cout << ANSI_COLOR_RED << "  Account No.:  " ANSI_COLOR_GREEN << AccountNumber << endl;
          cout << ANSI_COLOR_YELLOW << "\tBalance         :  " ANSI_COLOR_MAGENTA << Balance << endl;
          cout << ANSI_COLOR_YELLOW "\tIFSC Code       :  " ANSI_COLOR_RESET << IFSC_CODE << endl;
          cout << ANSI_COLOR_YELLOW "\tName            :  " ANSI_COLOR_RESET << AccountHolderName << endl;
          cout << ANSI_COLOR_YELLOW "\tFather`s Name   :  " ANSI_COLOR_RESET << FatherName << endl;
          cout << ANSI_COLOR_YELLOW "\tAadhaar         :  " ANSI_COLOR_RESET << AadhaarNumber << endl;
          cout << ANSI_COLOR_YELLOW "\tAge             :  " ANSI_COLOR_RESET << Age << endl;
          cout << ANSI_COLOR_YELLOW "\tGender          :  " ANSI_COLOR_RESET << Gender << endl;
          cout << ANSI_COLOR_YELLOW "\tMobile Number   :  " ANSI_COLOR_RESET << MobileNumber << endl;
          cout << ANSI_COLOR_YELLOW "\tEmail Address   :  " ANSI_COLOR_RESET << EmailAddress << endl;
          cout << ANSI_COLOR_YELLOW "\tAddress         :  " ANSI_COLOR_RESET << Address << endl;
          cout << ANSI_COLOR_YELLOW "\tAC Opening Date :  " ANSI_COLOR_RESET << Date << endl;
          cout << ANSI_COLOR_RED "-----------------------------------------\n";
     }
     int FindUniqueAccountNumber()
     {
          ifstream fin;
          char num[15];
          int tempAccountN;
          fin.open("NextAccountNumber.dat", ios::binary | ios::in);
          fin.seekg(0);
          fin >> num;
          // AccountNumber.assign(num);
          strcpy(AccountNumber, num);
          tempAccountN = stoi(num); // stoi convert string to int
          tempAccountN++;
          fin.close();
          ofstream FWrite;
          FWrite.open("NextAccountNumber.dat");
          FWrite << tempAccountN;
          FWrite.close();
          return tempAccountN;
     }
     void CheckAadhar()
     {
          int i = 0;
          PNB temp(0);
          ifstream fin("Record.dat", ios::in | ios::binary);
          fin.seekg(0);
     chhotu:
          while (!fin.eof())
          {
               fin.read((char *)&temp, sizeof(temp));
               if (strcmp(temp.AadhaarNumber, AadhaarNumber) == 0)
               {
                    i = 1;
                    cout << "This Aadhar Number allready entred...!\nRe-Enter Aadhar number: ";
                    cin.getline(AadhaarNumber, 15);
                    goto chhotu;
               }
          }
          // cout<<strlen(AadhaarNumber)<<"     "<<i<<endl;
          if ((i == 0 and strlen(AadhaarNumber) == 14) || (i == 0 and strlen(AadhaarNumber) == 12))
          {
               int j = 0;
               while (j < strlen(AadhaarNumber))
               {
                    if (AadhaarNumber[j] >= '0' && AadhaarNumber[j] <= '9' || AadhaarNumber[j] == 32)
                    {
                         i = 2;
                    }
                    else
                    {
                         cout << ANSI_COLOR_RED << "\t\t\t\t" << 'x' << endl;
                         cout << ANSI_COLOR_YELLOW << "Re-Enter Aadhaar Number:    " ANSI_COLOR_RESET;
                         cin.getline(AadhaarNumber, 15);
                         goto chhotu;
                    }
                    j++;
               }
               if (i == 2)
               {
                    cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;
               }
          }
          else
          {

               cout << ANSI_COLOR_RED << "\t\t\t\t" << 'x' << endl;
               cout << ANSI_COLOR_YELLOW << "Re-Enter Aadhaar Number:    " ANSI_COLOR_RESET;
               cin.getline(AadhaarNumber, 15);
               goto chhotu;
          }
          fin.close();
     }
     PNB()
     {
          system("cls");
          fflush(stdin);
          cout << ANSI_COLOR_GREEN "\tAccount Creation page\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " __DATE__ << "\n"
               << ANSI_COLOR_BLUE "-----------------------------------------\n";
          strcpy(Balance, "0");
          cout << ANSI_COLOR_RED "Enter Our Details:-\n";
          cout << ANSI_COLOR_YELLOW "Name            :  " ANSI_COLOR_RESET;
          cin.getline(AccountHolderName, 30);
          cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;
          cout << ANSI_COLOR_YELLOW "Father`s Name   :  " ANSI_COLOR_RESET;
          cin.getline(FatherName, 30);
          cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;
          cout << ANSI_COLOR_YELLOW "Aadhaar         :  " ANSI_COLOR_RESET;
          cin.getline(AadhaarNumber, 15);
          CheckAadhar();
          cout << ANSI_COLOR_YELLOW "Age             :  " ANSI_COLOR_RESET;
          cin.getline(Age, 3);
          cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;

     ReEnterGender:
          cout << ANSI_COLOR_YELLOW "Gender(M/F)     :  " ANSI_COLOR_RESET;
          cin >> Gender;
          if (Gender == 'M' or Gender == 'F' or Gender == 'm' or Gender == 'f')
          {
               cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;
          }
          else
          {
               cout << ANSI_COLOR_RED << "\t\t\t\t" << 'x' << endl;
               cout << ANSI_COLOR_YELLOW << "Re-Enter ";
               goto ReEnterGender;
          }
          fflush(stdin);

     ReEnterMobile:
          cout << ANSI_COLOR_YELLOW "Mobile Number   :  " ANSI_COLOR_RESET;
          cin.getline(MobileNumber, 11);
          int j = 0;
          while (j < 11)
          {
               if (MobileNumber[j] < '0' && MobileNumber[j] > '9')
               {
                    cout << ANSI_COLOR_RED << "\t\t\t\t" << 'x' << endl;
                    cout << ANSI_COLOR_YELLOW << "Re-Enter ";
                    goto ReEnterMobile;
               }
               j++;
          }
          cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;

     ReEnterEmail:
          cout << ANSI_COLOR_YELLOW "Email Address   :  " ANSI_COLOR_RESET;
          cin.getline(EmailAddress, 30);
          int i;
          j = 0;
          string str2 = "@gmail.com";
          for (i = 0; EmailAddress[i]; i++)
          {
               if (EmailAddress[i] == str2[j])
               {
                    j++;
                    if (j == 9)
                         break;
               }
               else if ((EmailAddress[i] >= 'a' && EmailAddress[i] <= 'z') or (EmailAddress[i] >= 'A' && EmailAddress[i] <= 'Z'))
               {

                    j = 0;
               }
               else
               {
                    cout << ANSI_COLOR_YELLOW "Re-Enter ";
                    goto ReEnterEmail;
               }
          }
          cout << ANSI_COLOR_GREEN << "\t\t\t\t" << (char)251 << endl;

          cout << ANSI_COLOR_YELLOW "Address         :  " ANSI_COLOR_RESET;
          cin.getline(Address, 30);
          cout << ANSI_COLOR_RED << "\t\t\t\t" << 'x' << endl;

          cout << ANSI_COLOR_YELLOW "Date(DD/MM/YYYY):  " ANSI_COLOR_RESET;
          cin.getline(Date, 11);
          cout << ANSI_COLOR_RED << "\t\t\t\t" << 'x' << endl;

          FindUniqueAccountNumber();
          system("cls");
          cout << ANSI_COLOR_GREEN "\tTpin Creation page\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " __DATE__ << "\n"
               << ANSI_COLOR_BLUE "-----------------------------------------\n";
          Print();
          cout << ANSI_COLOR_RED "Your Account Successfully Created...." ANSI_COLOR_RESET << endl;
          cout << ANSI_COLOR_YELLOW "Enter Tpin         :  " ANSI_COLOR_RESET;
          cin >> Tpin;
          ofstream fout("Record.dat", ios::app | ios::binary);
          fout.write((char *)this, sizeof(*this));
          cout << ANSI_COLOR_BLUE "\tpress any key to continue.....   ";
          fout.close();
          getch();
     }
     void FindUniqueATMNumber()
     {
     }
     int Deposit();
     void WithdrawMoney();
     int GetATM();
};
char PNB::IFSC_CODE[] = "PUNB8920";
int PNB::GetATM()
{
     system("cls");
     cout << ANSI_COLOR_GREEN << "\t\tGet ATM\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " << __DATE__ "\n"
          << ANSI_COLOR_BLUE "-----------------------------------------\n";

     char CardNumber[20];
     char AccountNumber2[15];
     char AadharNumber2[15];
     char MobileNumber2[11];
     char Tpin2[6];
     int x = 0;

     fflush(stdin);
     cout << ANSI_COLOR_CYAN "Enter Details:---" << endl;
     cout << ANSI_COLOR_YELLOW "\tAccount Number  :  " ANSI_COLOR_RESET;
     cin.getline(AccountNumber2, 15);
     cout << ANSI_COLOR_YELLOW << "\tAadhar Number:  " ANSI_COLOR_RESET;
     cin.getline(AadharNumber2, 15);
     cout << ANSI_COLOR_YELLOW << "\tMobile Number:  " ANSI_COLOR_RESET;
     cin.getline(MobileNumber2, 15);
     cout << ANSI_COLOR_YELLOW << "\tTPIN         :  " ANSI_COLOR_RESET;
     cin.getline(Tpin2, 6);

     ifstream fin1;
     fin1.open("Record.dat", ios::in | ios::binary);
     fin1.seekg(0);
     while (!fin1.eof())
     {
          fin1.read((char *)this, sizeof(*this));
          if ((strcmp(AccountNumber, AccountNumber2) == 0) and (strcmp(MobileNumber, MobileNumber2) == 0) and (strcmp(AadhaarNumber, AadharNumber2) == 0) and (strcmp(Tpin, Tpin2) == 0))
          {
               x = 1;
               break;
          }
     }
     if (x == 0)
     {
          cout << ANSI_COLOR_RED "This Account Number doesnot exist...!" ANSI_COLOR_RESET << endl;
          cout << ANSI_COLOR_CYAN "\tPress any key to continue....." ANSI_COLOR_RESET << endl;
          getch();
          return 0;
     }
     else
          srand(time(0));
     int num;
     ifstream fin("ATMRecord.txt");

     char account[15], card[20];
     while (!fin.eof())
     {
          fin.getline(account, 15);
          fin.getline(card, 20);
          if (strcmp(account, AccountNumber2) == 0)
          {
               cout << ANSI_COLOR_RED "Not possible! only one Card at a time !" ANSI_COLOR_RESET << endl;
               cout << ANSI_COLOR_CYAN "\tPress any key to continue......" ANSI_COLOR_RESET;
               getch();
               return 0;
          }
     }

Re_find:
     for (int j = 0; j < 100; j++)
     {
          for (int i = 0; i < 19; i++)
          {
               num = (rand() % (0 - 10 + 1) + 48);
               if (i == 4 or i == 9 or i == 14)
                    CardNumber[i] = ' ';
               else
                    CardNumber[i] = (char)num;
          }
          CardNumber[19] = '\n';
          CardNumber[20] = '\0';
          char str[20];
          while (fin.eof())
          {
               fin.getline(str, 20);
               if ((strcmp(CardNumber, str) == 0))
               {
                    goto Re_find;
               }
          }
     }

     fin.close();
     ofstream fout("ATMRecord.txt", ios::app);
     fout << AccountNumber2 << '\n'
          << CardNumber << '\n';
     cout << ANSI_COLOR_GREEN "Your ATM Card has been successfully Created...." ANSI_COLOR_RESET << endl;
     cout << ANSI_COLOR_YELLOW "\tYour Card Number:   " ANSI_COLOR_MAGENTA << CardNumber << ANSI_COLOR_RESET;
     cout << ANSI_COLOR_RED << "\t[" << ANSI_COLOR_YELLOW "Your ATM pin is TPIN" << ANSI_COLOR_RED << "]" ANSI_COLOR_RESET;
     fout.close();
     cout << ANSI_COLOR_CYAN "\tPress any key to continue....." ANSI_COLOR_RESET << endl;
     getch();
}
int main()
{
     FrontDesinge();
     char choice;
     while (1)
     {
          Manu();
          scanf("%c", &choice);
          if (choice == '1')
          {
               PNB PT;
          }
          else if (choice == '8')
          {
               exit(0);
          }
          else if (choice == '2')
          {
               PNB temp(0);
               temp.Deposit();
          }
          else if (choice == '3')
          {
               PNB temp(0);
               temp.WithdrawMoney();
          }
          else if (choice == '4')
          {
               PNB temp(0);
               temp.GetATM();
          }
          else if (choice == '7')
          {
               ABOUT();
          }
          else if (choice == '9')
          {
               PNB temp(0);
               temp.ALLRecord();
               getch();
          }
          fflush(stdin);
     }
     return 0;
}
void FrontDesinge()
{
     string BankName = "Welcome To Punjab National Bank,Punjab National Bank Me Aapka Swagat Hai";
     system("cls");
     cout << ANSI_COLOR_GREEN << "\n\n\n\n\t";
     for (int i = 0; BankName[i]; i++)
     {
          if (BankName[i] == ',')
               cout << "\n\n   ";
          else
               cout << BankName[i];
          if (BankName[i] == ' ')
               usleep(300000); // usleep(1000);
          else
               usleep(100000); // usleep(1000); //
     }
}
void Manu()
{
     system("cls");
     cout << ANSI_COLOR_GREEN << "\t\tMain Manu\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " << __DATE__ "\n"
          << ANSI_COLOR_BLUE "-----------------------------------------\n";
     cout << ANSI_COLOR_MAGENTA "*****************************************" << endl;
     cout << "*" << ANSI_COLOR_YELLOW "   Press        ForWork\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   1        Open New Account\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   2        Deposit\t\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   3        Withdraw Money\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   4        Get an ATM\t\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   5        EYC\t\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   6        Loan\t\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   7        About\t\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   8        Exit\t\t\t" << ANSI_COLOR_MAGENTA "*" << endl;
     cout << ANSI_COLOR_MAGENTA "*****************************************" << ANSI_COLOR_RESET << endl;
     cout << ANSI_COLOR_RED "\nEnter Your Choice  ?    " ANSI_COLOR_RESET;
}
void PNB::ALLRecord()
{
     system("cls");
     cout << ANSI_COLOR_GREEN << "\t\tRecord Section\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " << __DATE__ "\n";

     int i = 1;
     ifstream fin("Record.dat", ios::in | ios::binary);
     fin.seekg(0);
     while (!fin.eof())
     {
          fin.read((char *)this, sizeof(*this));
          Print();
          i++;
     }
     fin.close();
}
int PNB::Deposit()
{

     char ACtemp[15];
     char TpinTemp[5];
     char choice;

     system("cls");
     cout << ANSI_COLOR_GREEN << "\t\tWithdraw Section\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " << __DATE__ "\n"
          << ANSI_COLOR_BLUE "-----------------------------------------\n";
     cout << ANSI_COLOR_MAGENTA "********************************************" << endl;
     cout << "*" << ANSI_COLOR_YELLOW "   Press        ForWork\t\t   " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   1        Deposit Through A/C Number\t   " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   2        Deposit Through Aadhar Number " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   3        Deposit Through ATM\t   " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << ANSI_COLOR_MAGENTA "********************************************" << ANSI_COLOR_RESET << endl;
     cout << ANSI_COLOR_RED "\tEnter Your choice ?       " ANSI_COLOR_RESET;

     cin >> choice;
     fflush(stdin);
     int Balancet;

     int x = 0;
     int check = 0;
     fstream fin("Record.dat");
     ifstream fint("ATMRecord.txt");
     switch (choice)
     {
     case '1':

          cout << ANSI_COLOR_YELLOW "\n\nEnter Your Account:   " ANSI_COLOR_RESET;
          cin.getline(ACtemp, 15);
          cout << ANSI_COLOR_YELLOW "Enter your Tpin:      " ANSI_COLOR_RESET;
          cin.getline(TpinTemp, 5);
          while (!fin.eof())
          {
               fin.read((char *)this, sizeof(*this));
               if (strcmp(ACtemp, AccountNumber) == 0 and strcmp(Tpin, TpinTemp) == 0)
               {
                    check = 1;
                    Print();
                    cout << ANSI_COLOR_RED "Enter Balance: " ANSI_COLOR_RESET;
                    cin >> Balancet;
                    x = atoi(Balance);
                    x += Balancet;
                    string temp = itos(x);
                    strcpy(Balance, temp.c_str());
                    fflush(stdin);
                    fin.seekg((fin.tellg()) - sizeof(*this));
                    fin.write((char *)this, sizeof(*this));
                    cout << ANSI_COLOR_RED "Deposit successfull....\n" ANSI_COLOR_RESET;
                    break;
               }
          }
          if (check == 0)
          {
               cout << ANSI_COLOR_RED "Wrong Account Number or Tpin !" ANSI_COLOR_RESET << endl;
               cout << ANSI_COLOR_CYAN "\tPress any key to continue...." ANSI_COLOR_RESET;
               getch();
               return 0;
          }

          break;
     case '2':

          cout << ANSI_COLOR_YELLOW "\n\nEnter Aadhar Number:   " ANSI_COLOR_RESET;
          cin.getline(ACtemp, 15);
          cout << ANSI_COLOR_YELLOW "Enter your Tpin:      " ANSI_COLOR_RESET;
          cin.getline(TpinTemp, 5);
          while (!fin.eof())
          {
               fin.read((char *)this, sizeof(*this));
               if (strcmp(ACtemp, AadhaarNumber) == 0 and strcmp(Tpin, TpinTemp) == 0)
               {
                    check = 1;
                    Print();
                    cout << ANSI_COLOR_RED "Enter Balance: " ANSI_COLOR_RESET;
                    cin >> Balancet;
                    x = atoi(Balance);
                    x += Balancet;
                    string temp = itos(x);
                    strcpy(Balance, temp.c_str());
                    fflush(stdin);
                    fin.seekg((fin.tellg()) - sizeof(*this));
                    fin.write((char *)this, sizeof(*this));
                    cout << ANSI_COLOR_RED "Deposit successfull....\n" ANSI_COLOR_RESET;
                    break;
               }
          }
          if (check == 0)
          {
               cout << ANSI_COLOR_RED "Wrong Account Number or Tpin !" ANSI_COLOR_RESET << endl;
               cout << ANSI_COLOR_CYAN "\tPress any key to continue...." ANSI_COLOR_RESET;
               getch();
               return 0;
          }
          break;
     case '3':
          char card[20], card2[20], account2[15];
          cout << ANSI_COLOR_YELLOW "\n\nEnter Card Number:   " ANSI_COLOR_RESET;
          cin.getline(card, 20);
          cout << ANSI_COLOR_YELLOW "Enter your Tpin        :   " ANSI_COLOR_RESET;
          cin.getline(TpinTemp, 5);
          while (!fint.eof())
          {
               fint.getline(account2, 15);
               fint.getline(card2, 20);
               if (strcmp(card2, card) == 0)
               {
                    check = 1;
                    break;
               }
          }
          if (check == 0)
          {
               cout << ANSI_COLOR_RED "Wrong Card Number !" ANSI_COLOR_RESET << endl;
               cout << ANSI_COLOR_CYAN "\tPress any key to continue...." ANSI_COLOR_RESET;
               getch();
               return 0;
          }
          while (!fin.eof())
          {
               fin.read((char *)this, sizeof(*this));
               if (strcmp(Tpin, TpinTemp) == 0)
               {
                    Print();
                    cout << ANSI_COLOR_RED "Enter Balance: " ANSI_COLOR_RESET;
                    cin >> Balancet;
                    x = atoi(Balance);
                    x += Balancet;
                    string temp = itos(x);
                    strcpy(Balance, temp.c_str());
                    fflush(stdin);
                    fin.seekg((fin.tellg()) - sizeof(*this));
                    fin.write((char *)this, sizeof(*this));
                    cout << ANSI_COLOR_RED "Deposit successfull....\n" ANSI_COLOR_RESET;
                    break;
               }
          }

          break;
     default:
          cout << ANSI_COLOR_RED "Invalid Choice !\n" ANSI_COLOR_RESET;
          break;
     }
     cout << ANSI_COLOR_BLUE "\tpress any key to continue.....   ";
     getch();
     fin.close();
}
void PNB::WithdrawMoney()
{

     char ACtemp[15];
     char TpinTemp[5];
     char choice;

     system("cls");
     cout << ANSI_COLOR_GREEN << "\t\tWithdraw Section\t" << ANSI_COLOR_MAGENTA __TIME__ << "  " << __DATE__ "\n"
          << ANSI_COLOR_BLUE "-----------------------------------------\n";
     cout << ANSI_COLOR_MAGENTA "********************************************" << endl;
     cout << "*" << ANSI_COLOR_YELLOW "   Press        ForWork\t\t   " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   1        Deposit Through A/C Number\t   " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   2        Deposit Through Aadhar Number " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << "*" << ANSI_COLOR_CYAN "   3        Deposit Through ATM\t   " << ANSI_COLOR_MAGENTA "*" << endl;
     cout << ANSI_COLOR_MAGENTA "********************************************" << ANSI_COLOR_RESET << endl;
     cout << ANSI_COLOR_RED "\tEnter Your choice ?       " ANSI_COLOR_RESET;

     int balance;
     int tempb;
     fstream fin("Record.dat");
     ifstream fint("ATMRecord.txt");

     cin >> choice;
     fflush(stdin);

     int x = 0, check = 0;

     switch (choice)
     {
     case '1':

          cout << ANSI_COLOR_YELLOW "\n\nEnter Your Account:   " ANSI_COLOR_RESET;
          cin.getline(ACtemp, 15);
          cout << ANSI_COLOR_YELLOW "Enter your Tpin:      " ANSI_COLOR_RESET;
          cin.getline(TpinTemp, 5);
          while (!fin.eof())
          {
               fin.read((char *)this, sizeof(*this));
               tempb = atoi(Balance);
               if (strcmp(ACtemp, AccountNumber) == 0 and strcmp(Tpin, TpinTemp) == 0)
               {
                    x = 1;
                    cout << "Enter Balance: ";
                    cin >> balance;

                    if (tempb >= balance)
                    {
                         tempb = tempb - balance;
                         string str = itos(tempb);
                         strcpy(Balance, str.c_str());
                    }
                    else
                    {
                         Print();
                         cout << ANSI_COLOR_RED "Transaction is not possiple" ANSI_COLOR_RESET;
                         break;
                    }
                    fflush(stdin);
                    fin.seekg((fin.tellg()) - sizeof(*this));
                    fin.write((char *)this, sizeof(*this));
                    break;
               }
          }
          break;
     case '2':
          cout << ANSI_COLOR_YELLOW "\n\nAadhar Number:   " ANSI_COLOR_RESET;
          cin.getline(ACtemp, 15);
          cout << ANSI_COLOR_YELLOW "Enter your Tpin:      " ANSI_COLOR_RESET;
          cin.getline(TpinTemp, 5);
          while (!fin.eof())
          {
               fin.read((char *)this, sizeof(*this));
               tempb = atoi(Balance);
               if (strcmp(ACtemp, AadhaarNumber) == 0 and strcmp(Tpin, TpinTemp) == 0)
               {
                    x = 1;
                    cout << "Enter Balance: ";
                    cin >> balance;
                    fflush(stdin);
                    if (tempb >= balance)
                    {
                         tempb = tempb - balance;
                         string str = itos(tempb);
                         strcpy(Balance, str.c_str());
                    }
                    else
                    {
                         Print();
                         cout << ANSI_COLOR_RED "Transaction is not possiple" ANSI_COLOR_RESET;
                         break;
                    }

                    fin.seekg((fin.tellg()) - sizeof(*this));
                    fin.write((char *)this, sizeof(*this));
                    break;
               }
          }
          break;
     case '3':

          char card[20], card2[20], account2[15];
          cout << ANSI_COLOR_YELLOW "\n\nEnter Card Number:   " ANSI_COLOR_RESET;
          cin.getline(card, 20);
          cout << ANSI_COLOR_YELLOW "Enter your Tpin        :   " ANSI_COLOR_RESET;
          cin.getline(TpinTemp, 6);
          while (!fint.eof())
          {
               fint.getline(account2, 15);
               fint.getline(card2, 20);
               if (strcmp(card2, card) == 0)
               {
                    while (!fin.eof())
                    {
                         fin.read((char *)this, sizeof(*this));
                         tempb = atoi(Balance);
                         if (strcmp(account2, AccountNumber) == 0 and strcmp(Tpin, TpinTemp) == 0)
                         {
                              x = 1;
                              cout << "Enter Balance: ";
                              cin >> balance;
                              fflush(stdin);
                              if (tempb >= balance)
                              {
                                   tempb = tempb - balance;
                                   string str = itos(tempb);
                                   strcpy(Balance, str.c_str());
                              }
                              else
                              {
                                   Print();
                                   cout << ANSI_COLOR_RED "Transaction is not possiple" ANSI_COLOR_RESET;
                                   break;
                              }

                              fin.seekg((fin.tellg()) - sizeof(*this));
                              fin.write((char *)this, sizeof(*this));
                              break;
                         }
                    }
                    check = 1;
                    break;
               }
          }
          if (check == 0)
          {
               cout << ANSI_COLOR_RED "Wrong Card Number !" ANSI_COLOR_RESET << endl;
          }
          break;
     default:
          cout << ANSI_COLOR_RED "Invalid Choice !\n" ANSI_COLOR_RESET;
          break;
     }
     if (x == 0)
     {
          cout << ANSI_COLOR_RED "Miss match Card Number/Tpin !\n" ANSI_COLOR_RESET;
     }
     else
     {
          cout << ANSI_COLOR_RED "Transaction successfull....\n";
     }

     cout << ANSI_COLOR_BLUE "\tpress any key to continue.....   ";
     getch();
     fin.close();
}
void ABOUT()
{
     system("cls");
     cout << ANSI_COLOR_CYAN << "\t\tAbout Developer\t" << endl;
     cout << ANSI_COLOR_YELLOW "\nI`m Chhotu" << endl;
     cout << "I`m 17 year old" << endl;
     cout << ANSI_COLOR_GREEN "\nAbout my schooling:-" << endl;
     cout << ANSI_COLOR_YELLOW "\tI`m completed 10th from +2 High School Sirari in 2019" << endl;
     cout << "\tI`m completed 12th from RD College sheikhpura in 2021" << endl;
     cout << "\tI`m graduating form RD College sheikhpura" << endl;
     cout << ANSI_COLOR_GREEN "\nAbout my special skill:-" << endl;
     cout << ANSI_COLOR_YELLOW "\t1.    Computer" << endl
          << "\t2.    C & C++" << endl
          << "\t3.    Image & Video editing" << endl;
     cout << "\nMob:    8920823219\nEmail:     chhotustduymail@gmail.com" << endl;
     cout << ANSI_COLOR_MAGENTA "\n\t\tThank U" ANSI_COLOR_RESET << endl;
     getch();
}
