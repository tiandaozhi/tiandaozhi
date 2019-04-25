

#include "TwoDayPackage.h" 


TwoDayPackage::TwoDayPackage( const string &sName, 
   const string &sAddress, const string &sCity, const string &sState, 
   int sZIP, const string &rName, const string &rAddress, 
   const string &rCity, const string &rState, int rZIP, 
   double w, double cost, double fee ) 
   : Package( sName, sAddress, sCity, sState, sZIP, 
      rName, rAddress, rCity, rState, rZIP, w, cost )
{
   setFlatFee( fee );
} 


void TwoDayPackage::setFlatFee( double fee )
{
   flatFee = ( fee < 0.0 ) ? 0.0 : fee;
} 


double TwoDayPackage::getFlatFee() const
{
   return flatFee;
} 


double TwoDayPackage::calculateCost() const
{
   return Package::calculateCost() + getFlatFee();
} 


