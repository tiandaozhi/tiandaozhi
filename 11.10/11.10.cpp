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

    cout<<"Account�ĵ�ǰ�˻��� "<<endl;
    cin>>balance;
    Account account(balance);

    cout<<endl<<"����Account�û��Ľ�"<<endl;
    cin>>credit;
    account.credit(credit);
    cout<<"Account�û��������"<<account.get_Balance()<<endl<<endl;

    cout<<"�ɹ���ȡAccount�û��Ľ�"<<endl;
    cin>>debit;
    account.debit(debit);
    cout<<"Account�ɹ���ȡ������: "<<account.get_Balance()<<endl<<endl;

    cout<<"͸֧��ȡAccount�û��Ľ�"<<endl;
    cin>>debit;
    account.debit(debit);
    cout<<"Account͸֧��ȡ��������Ϊ: "<<account.get_Balance()<<endl<<endl;

    cout<<"SavingsAccount�ĵ�ǰ�˻��������ʣ� "<<endl;
    cin>>balance>>interest_rate;
    SavingsAccount sav_account(balance,interest_rate);

    cout<<endl<<"SavingsAccount����ϢΪ: "<<sav_account.calculateInterest()<<endl<<endl;

    sav_account.credit(sav_account.calculateInterest());

    cout<<"SavingsAccount�ĵ�ǰ�˻��ܶ�: "<<sav_account.get_Balance()<<endl<<endl;

    cout<<"CheckingAccount�ĵ�ǰ�˻����͵��ʽ��׷���: "<<endl;
    cin>>balance>>service_charge;
    CheckingAccount che_account(balance,service_charge);

    cout<<endl<<"����CheckingAccount�û��Ľ��: "<<endl;
    cin>>credit;
    che_account.credit(credit);
    cout<<"CheckingAccount�û���������: "<<che_account.get_Balance()<<endl<<endl;

    cout<<"��ȡCheckingAccount�û���Ľ��: "<<endl;
    cin>>debit;
    if(che_account.debit(debit)==false)
        cout<<"CheckingAccount��͸֧��ȡ,�����Ϊ: "<<che_account.get_Balance()<<endl<<endl;
    else
      {
        che_account.true_debit(debit);
        cout<<"CheckingAccount�ɹ�ȡǮ������: "<<che_account.get_Balance()<<endl<<endl;
      }


}
