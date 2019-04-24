
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> 
#include "Date.h" 
using namespace std;

class Employee 
{
public:
   Employee( const string &, const string &, const string &, 
      int, int, int );

   void setFirstName( const string & ); 
   string getFirstName() const; 

   void setLastName( const string & ); 
   string getLastName() const; 

   void setSocialSecurityNumber( const string & ); 
   string getSocialSecurityNumber() const; 

   void setBirthDate( int, int, int ); 
   Date getBirthDate() const; 

   
   virtual double earnings() const = 0; 
   virtual void print() const; 
private:
   string firstName;
   string lastName;
   string socialSecurityNumber;
   Date birthDate; 
}; 
#endif 

