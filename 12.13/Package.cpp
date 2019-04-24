

#include "Package.h" 


Package::Package( const string &sName, const string &sAddress, 
   const string &sCity, const string &sState, int sZIP, 
   const string &rName, const string &rAddress, const string &rCity, 
   const string &rState, int rZIP, double w, double cost )
   : senderName( sName ), senderAddress( sAddress ), senderCity( sCity ),
     senderState( sState ), senderZIP( sZIP ), recipientName( rName ), 
     recipientAddress( rAddress ), recipientCity( rCity ), 
     recipientState( rState ), recipientZIP( rZIP )
{
   setWeight( w ); 
   setCostPerOunce( cost ); 
} 


void Package::setSenderName( const string &name )
{
    senderName = name;
} 


string Package::getSenderName() const
{
   return senderName;
} 


void Package::setSenderAddress( const string &address )
{
   senderAddress = address;
} 


string Package::getSenderAddress() const
{
   return senderAddress;
} 


void Package::setSenderCity( const string &city )
{
   senderCity = city;
} 


string Package::getSenderCity() const
{
   return senderCity;
} 

void Package::setSenderState( const string &state )
{
   senderState = state;
} 


string Package::getSenderState() const
{
   return senderState;
} 


void Package::setSenderZIP( int zip )
{
   senderZIP = zip;
} 


int Package::getSenderZIP() const
{
   return senderZIP;
} 


void Package::setRecipientName( const string &name )
{
    recipientName = name;
}
string Package::getRecipientName() const
{
   return recipientName;
} 


void Package::setRecipientAddress( const string &address )
{
   recipientAddress = address;
} 


string Package::getRecipientAddress() const
{
   return recipientAddress;
} 


void Package::setRecipientCity( const string &city )
{
   recipientCity = city;
} 


string Package::getRecipientCity() const
{
   return recipientCity;
} 

void Package::setRecipientState( const string &state )
{
   recipientState = state;
} 


string Package::getRecipientState() const
{
   return recipientState;
} 


void Package::setRecipientZIP( int zip )
{
   recipientZIP = zip;
} 


int Package::getRecipientZIP() const
{
   return recipientZIP;
} 

void Package::setWeight( double w )
{
   weight = ( w < 0.0 ) ? 0.0 : w;
} 


double Package::getWeight() const
{
   return weight;
}

void Package::setCostPerOunce( double cost )
{
   costPerOunce = ( cost < 0.0 ) ? 0.0 : cost;
} 


double Package::getCostPerOunce() const
{
   return costPerOunce;
} 


double Package::calculateCost() const
{
   return getWeight() * getCostPerOunce();
} 


