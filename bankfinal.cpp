#include <iostream>
#include <string>
using namespace std;
// structure to store data
struct bank
{
  string name, address, emailid, dob, aadharno, fathername, password, mobileno;
  long int balance, accountno;
};
bank b[20];
int main()
{

  int n;
l1:
  void clearScreen();
  clearScreen();
  cout << "\n-----------------------------------------|| WELCOME TO STATE BANK OF INDIA ||-----------------------------------------\n\n";
  cout << "\npress 0 to open account";
  cout << "\npress 1 to deposit";
  cout << "\npress 2 to withdraw";
  cout << "\npress 3 to check balance";
  cout << "\npress 4 to bank to bank transfer";
  cout << "\npress 5 to edit your details ";
  cout << "\npress 6 to change your password";
  cout << "\npress 7 to see your information";
  cout << "\npress 8 to exit\n";
  cin >> n;
  switch (n)
  {
  case 0:
    cout << "\n || WELCOME TO ACCOUNT OPENING PAGE || \n\n";
    void accountopen();
    accountopen();
    goto l1;
  case 2:
    cout << "\n || WELCOME TO WITHDRAWL PAGE || \n\n";
    void withdraw();
    withdraw();
    goto l1;
  case 1:
    cout << "\n ||  WELCOME TO DEPOSIT PAGE || \n\n";
    void deposit();
    deposit();
    goto l1;
  case 3:
    cout << "\n || WELCOME TO BALANCE CHECK PAGE || \n\n";
    void balancecheck();
    balancecheck();
    goto l1;
  case 4:
    cout << "\n || WELCOME TO BANK TO BANK TRANSFER || \n\n";
    void banktrans();
    banktrans();
    goto l1;
  case 5:
    cout << "\n || WELCOME TO DETAILS EDIT PAGE || \n\n";
    void editdata();
    editdata();
    goto l1;
  case 6:
    cout << "\n || WELCOME TO BANK TO CHANGE PASSWORD || \n\n";
    void passchange();
    passchange();
    goto l1;
  case 7:
    cout << "\n || WELCOME TO BANK INFORMATION PAGE || \n\n";
    void viewdata();
    viewdata();
    goto l1;

  case 8:
    goto l2;
  default:
    cout << "\nINVALID INPUT";
    goto l1;
  }
l2:
  return 0;
}
void clearScreen()
{
#ifdef _WIN32
  system("cls"); // For Windows
#else
  system("clear"); // For Unix/Linux
#endif
}
int t = 0;
void accountopen()
{

  cout << "\nenter your name:";
  cin.ignore();            // clears buffer space for getline to run smoothly
  getline(cin, b[t].name); // takes a line as input including spaces
  cout << "\nenter your mobileno:";
  cin >> b[t].mobileno;
  cout << "\nenter your address:";
  cin.ignore();               // clears buffer space for getline to run smoothly
  getline(cin, b[t].address); // takes a line as input including spaces
  cout << "\nenter your emailId:";
  cin >> b[t].emailid;
  cout << "\nenter your dob:";
  cin >> b[t].dob;
  cout << "\nenter your father's name:";
  cin.ignore();                  // clears buffer space for getline to run smoothly
  getline(cin, b[t].fathername); // takes a line as input including spaces
  cout << "\nenter your aadhar number:";
  cin >> b[t].aadharno;
  cout << "\ncreate your password:";
  cin >> b[t].password;
  cout << "\ninitial ammount to deposit:";
  cin >> b[t].balance;
  b[t].accountno = 12345670 + t;

  // print details with automatically generated accno

  cout << "\nyour name is " << b[t].name;
  cout << "\nyour mobile number is " << b[t].mobileno;
  cout << "\nyour address is " << b[t].address;
  cout << "\nyour emailID is " << b[t].emailid;
  cout << "\nyour dob is " << b[t].dob;
  cout << "\nyour father's name is " << b[t].fathername;
  cout << "\nyour aadhar number is " << b[t].aadharno;
  cout << "\nyour account number is " << b[t].accountno;
  cout << "\nyour password is " << b[t].password;
  cout << "\nyour bank balance is " << b[t].balance << "\n\n\n";
  t++;

  cout << "\npress enter to continue";
  cin.get();
  cin.get(); // holds output screen till enter is pressed
}

void withdraw()
{
  long int withdraw, chaccountno;
  string chpassword;
  int i;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nenter your password:";
    cin >> chpassword;
    if (b[i].password == chpassword)
    {
      cout << "\nenter the amount to withdraw:";
      cin >> withdraw;
      if (b[i].balance >= withdraw)
      {
        b[i].balance = b[i].balance - withdraw;
        cout << "\nremaining balance in your account is " << b[i].balance;
      }
      else
        cout << "\nLow balance";
    }
    else
      cout << "\nIncorrect Password";
  }
  else
    cout << "\nno account found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}

void deposit()
{
  long int deposit, chaccountno;
  string chpassword;
  int i;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nenter your password:";
    cin >> chpassword;
    if (b[i].password == chpassword)
    {
      cout << "\nenter the amount to deposit:";
      cin >> deposit;
      b[i].balance = b[i].balance + deposit;
      cout << "\nremaining balance in your account is " << b[i].balance;
    }
    else
      cout << "Incorrect Password";
  }
  else
    cout << "\nno account found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}

void balancecheck()
{
  long int chaccountno;
  int i;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nyour balance is " << b[i].balance;
  }
  else
    cout << "\naccount not found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}

void banktrans()
{
  long int transamt, chaccountno, transaccno;
  string chpassword;
  int i, k, count = 0, r;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nenter your password:";
    cin >> chpassword;
    if (chpassword == b[i].password)
    {
      cout << "\nenter the account number to transfer:";
      cin >> transaccno;
      r = transaccno - 12345670;
      if (b[r].accountno == transaccno)
      {
        cout << "\nenter the amount to transfer:";
        cin >> transamt;
        if (b[i].balance >= transamt)
        {
          b[i].balance = b[i].balance - transamt;
          b[r].balance = b[r].balance + transamt;
          cout << "\naccount transferred successfully";
          cout << "\nremaining balance in your account is " << b[i].balance;
        }
        else
          cout << "\n Low balance";
      }
      else
        cout << "\nno such account found";
    }
    else
    {
      cout << "\nincorrect password";
    }
  }
  else
    cout << "\n no account found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}
void editdata()
{
  long int chaccountno;
  string chpassword;
  int i;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nenter your password:";
    cin >> chpassword;
    if (b[i].password == chpassword)
    {
      cout << "your password matched please provide your new details";
      cin.ignore(); // clears buffer space for getline to run smoothly
      cout << "\nenter your name:";
      getline(cin, b[i].name); // takes a line as input including spaces
      cout << "\nenter your mobileno:";
      cin >> b[i].mobileno;
      cout << "\nenter your address:";
      cin.ignore();               // clears buffer space for getline to run smoothly
      getline(cin, b[i].address); // takes a line as input including spaces
      cout << "\nenter your emailId:";
      cin >> b[i].emailid;
      cout << "\nenter your dob:";
      cin >> b[i].dob;
      cout << "\nenter your father's name:";
      cin.ignore();                  // clears buffer space for getline to run smoothly
      getline(cin, b[i].fathername); // takes a line as input including spaces
      cout << "\nenter your aadhar number:";
      cin >> b[i].aadharno;
    }
    else
      cout << "Incorrect Password";
  }
  else
    cout << "\nno account found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}

void passchange()
{
  long int chaccountno;
  string chpassword;
  int i;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nenter your password:";
    cin >> chpassword;
    if (b[i].password == chpassword)
    {
      cout << "your password matched please provide ur new password" << endl;
      cin >> b[i].password;
    }
    else
      cout << "Incorrect Password";
  }
  else
    cout << "\nno account found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}

void viewdata()
{
  long int chaccountno;
  string chpassword;
  int i;
  cout << "\nenter your account number:";
  cin >> chaccountno;
  i = chaccountno - 12345670;
  if (chaccountno == b[i].accountno)
  {
    cout << "\nenter your password:";
    cin >> chpassword;
    if (b[i].password == chpassword)
    {
      cout << "your password matched here are ur details\n";
      cout << "\nyour name is " << b[i].name;
      cout << "\nyour mobile number is " << b[i].mobileno;
      cout << "\nyour address is " << b[i].address;
      cout << "\nyour emailID is " << b[i].emailid;
      cout << "\nyour dob is " << b[i].dob;
      cout << "\nyour father's name is " << b[i].fathername;
      cout << "\nyour aadhar number is " << b[i].aadharno;
      cout << "\nyour account number is " << b[i].accountno;
      cout << "\nyour password is " << b[i].password;
      cout << "\nyour bank balance is " << b[i].balance << "\n\n\n";
    }
    else
      cout << "Incorrect Password";
  }
  else
    cout << "\nno account found";
  cout << "\npress enter to continue";
  cin.get();
  cin.get();
}
