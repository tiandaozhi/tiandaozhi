
#include "OvernightPackage.h" 


OvernightPackage::OvernightPackage( const string &sName, 
   const string &sAddress, const string &sCity, const string &sState, 
   int sZIP, const string &rName, const string &rAddress, 
   const string &rCity, const string &rState, int rZIP, 
   double w, double cost, double fee ) 
   : Package( sName, sAddress, sCity, sState, sZIP, 
      rName, rAddress, rCity, rState, rZIP, w, cost )
{
   setOvernightFeePerOunce( fee ); 
} 

void OvernightPackage::setOvernightFeePerOunce( double overnightFee )
{
   overnightFeePerOunce = ( overnightFee < 0.0 ) ? 0.0 : overnightFee;
} 


double OvernightPackage::getOvernightFeePerOunce() const
{
   return overnightFeePerOunce;
} 


double OvernightPackage::calculateCost() const
{
   return getWeight() * ( getCostPerOunce() + getOvernightFeePerOunce() );
} 


