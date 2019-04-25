
#ifndef TWODAY_H
#define TWODAY_H

#include "Package.h" 

class TwoDayPackage : public Package
{
public:
   TwoDayPackage( const string &, const string &, const string &, 
      const string &, int, const string &, const string &, const string &, 
      const string &, int, double, double, double );

   void setFlatFee( double ); 
   double getFlatFee() const; 

   double calculateCost() const; 
private:
   double flatFee; 
}; 

#endif


