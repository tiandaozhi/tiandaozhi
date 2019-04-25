#include <iostream>
using namespace std;
class Account
{
    double balance;
public:
    Account(double Balance=0){
    if(Balance<0)
    {
        balance=0;
        cout<<"Information error, which is an invalid value"<<endl;
    }
    else
        balance=Balance;
    }

    void credit(double Balance){balance+=Balance;}

    void debit(double Balance){
    if(Balance>balance)
        cout<<"Debit amount exceeded  acount balance."<<endl;
    else
        balance-=Balance;
    }

    double get_Balance(){return balance;}

    friend class SavingAccount;
    friend class CheckingAccount;
};

class SavingsAccount:public Account
{
    double interest_rate;
public:
    SavingsAccount(double Balance,double Interest_rate):Account(Balance),interest_rate(Interest_rate){}

    double calculateInterest(){return interest_rate*get_Balance();}

};

class CheckingAccount:public Account
{
    double service_charge;
public:
    CheckingAccount(double Balance,double Service_charge):Account(Balance),service_charge(Service_charge){}

    void credit(double Balance){balance=balance+Balance-service_charge;}

    bool debit(double Balance){
    if(balance>=Balance)return true;
    else return false;
    }

    void true_debit(double Balance){balance-=Balance;}
};

int main()
{
    double balance,credit,debit,interest_rate,service_charge;

    cout<<"Account的当前账户余额： "<<endl;
    cin>>balance;
    Account account(balance);

    cout<<endl<<"存入Account用户的金额："<<endl;
    cin>>credit;
    account.credit(credit);
    cout<<"Account用户存款后的余额："<<account.get_Balance()<<endl<<endl;

    cout<<"成功提取Account用户的金额："<<endl;
    cin>>debit;
    account.debit(debit);
    cout<<"Account成功提取后的余额: "<<account.get_Balance()<<endl<<endl;

    cout<<"透支提取Account用户的金额："<<endl;
    cin>>debit;
    account.debit(debit);
    cout<<"Account透支提取后的余额仍为: "<<account.get_Balance()<<endl<<endl;

    cout<<"SavingsAccount的当前账户余额和利率： "<<endl;
    cin>>balance>>interest_rate;
    SavingsAccount sav_account(balance,interest_rate);

    cout<<endl<<"SavingsAccount的利息为: "<<sav_account.calculateInterest()<<endl<<endl;

    sav_account.credit(sav_account.calculateInterest());

    cout<<"SavingsAccount的当前账户总额: "<<sav_account.get_Balance()<<endl<<endl;

    cout<<"CheckingAccount的当前账户余额和单笔交易费用: "<<endl;
    cin>>balance>>service_charge;
    CheckingAccount che_account(balance,service_charge);

    cout<<endl<<"存入CheckingAccount用户的金额: "<<endl;
    cin>>credit;
    che_account.credit(credit);
    cout<<"CheckingAccount用户存款后的余额: "<<che_account.get_Balance()<<endl<<endl;

    cout<<"提取CheckingAccount用户后的金额: "<<endl;
    cin>>debit;
    if(che_account.debit(debit)==false)
        cout<<"CheckingAccount已透支提取,余额仍为: "<<che_account.get_Balance()<<endl<<endl;
    else
      {
        che_account.true_debit(debit);
        cout<<"CheckingAccount成功取钱后的余额: "<<che_account.get_Balance()<<endl<<endl;
      }


}
