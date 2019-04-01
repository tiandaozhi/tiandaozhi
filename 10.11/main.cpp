//Programming Finance 332:503

#include <iostream>

using namespace std;

//declaring the polynomial class
class Polynomial{
private:
	int array[12];
	int numTerms;
public:
//the public functions declarations for the object
    Polynomial operator=(Polynomial poly2);
	Polynomial operator+(Polynomial poly2);
	Polynomial operator+=(Polynomial poly2);
	Polynomial operator-(Polynomial poly2);
	Polynomial operator-=(Polynomial poly2);
	Polynomial operator*(Polynomial poly2);
	Polynomial operator*=(Polynomial poly2);
	int* get();
	void set(int[12]);
	friend ostream &operator<<( ostream &output, Polynomial &polyOut);
};

Polynomial Polynomial::operator=(Polynomial poly2)
{
    int* arrayPoly2 = new int[12];
    int arrayPolyReturn[12];
    Polynomial returnPoly;
    arrayPoly2 = poly2.get();
    for(int i = 0; i<12;i++)
    {
        arrayPolyReturn[i] = arrayPoly2[i];
    }
    //sets the return polynomial to the array
    returnPoly.set(arrayPolyReturn);

    return returnPoly;
}

//The + operator definition to add polynomials
Polynomial Polynomial::operator+(Polynomial poly2){
    int* arrayPoly2 = new int[12];
    int arrayPolyReturn[12];
    Polynomial returnPoly;
    arrayPoly2 = poly2.get();
    //loops to add all the polynomial values
    for(int i = 0; i<12;i++)
    {
        arrayPolyReturn[i] = array[i]+arrayPoly2[i];
    }
    //sets the return polynomial to the array
    returnPoly.set(arrayPolyReturn);

    return returnPoly;
}

//the += operator definition
Polynomial Polynomial::operator+=(Polynomial poly2)
{
//simpily calls the = operator since the operations are the same
    Polynomial returnPoly = *this + poly2;
    return returnPoly;
}

//the - operator definition
Polynomial Polynomial::operator-(Polynomial poly2){
    int* arrayPoly2 = new int[12];
    int arrayPolyReturn[12];
    Polynomial returnPoly;
    arrayPoly2 = poly2.get();
//subtracts the values of the array
    for(int i = 0; i<12;i++){
        arrayPolyReturn[i] = array[i]-arrayPoly2[i];
    }
    returnPoly.set(arrayPolyReturn);
    return returnPoly;
}

Polynomial Polynomial::operator-=(Polynomial poly2){
    Polynomial returnPoly = *this - poly2;
    return returnPoly;
}

//the * operator
Polynomial Polynomial::operator*(Polynomial poly2){
    int* arrayPoly2 = new int[12];
    int arrayPolyReturn[12] = {0};
    Polynomial returnPoly;
    arrayPoly2 = poly2.get();
    int tempExp;
//loops through the values in the two arrays
    for(int i = 0; i<12;i++){
        for(int j = 0; j<12; j++){
            tempExp = i + j;
            //the polynomial exponents are the indicies for the array
            arrayPolyReturn[tempExp] = arrayPolyReturn[tempExp] + array[i] * poly2.array[j];
        }
    }
    returnPoly.set(arrayPolyReturn);
    return returnPoly;

}

Polynomial Polynomial::operator*=(Polynomial poly2){
    Polynomial returnPoly = (*this) * poly2;
    return returnPoly;
}

//returns the array
int* Polynomial::get(){
    return array;
}

//sets the array with the input Array
void Polynomial::set(int inputArray[12]){
    for(int i = 0; i<12; i++){
    array[i] = inputArray[i];
    }
}

//output operator definition

ostream &operator<<( ostream &output, Polynomial &polyOut)
{
    int* arrayPoly = new int[12];
    arrayPoly = polyOut.array;
    int count = 0;
    //to get the number of terms in the polynomial
    for(int j = 0; j<12;j++){
        if(arrayPoly[j]!=0){
            count++;
        }
    }
    //loop to put the output to output ostream object instance
    for(int i = 0; i <12; i++)
        {
        if(arrayPoly[i]!=0){
            if(i==0){
                output<<arrayPoly[i];
            }
            else if(i==1){
                output<<arrayPoly[i]<<"x";
            }
            else{
                output<<arrayPoly[i]<<"x^"<<i;
            }
            count--;
            //only if count is > 0 so the last term will not have a + after it
            if(count>0){
                output<<" + ";
            }
        }
    }
    return output;
}

//the main function
int main(){
    //To store the number of terms
    int numTerms1;
    int numTerms2;
    //The input arrays to temporarily store the values
    int inputArray1[12];
    int inputArray2[12];
    //initializes the arrays
    for (int i = 0; i <12; i++){
        inputArray1[i] = 0;
        inputArray2[i] = 0;
    }
    //temporary store the coefficient and exponent
    int tempCoeff;
    int tempExponent;
    cout<<"Enter the number of polynomial terms: ";
    cin>>numTerms1;
    cout<<"\n";
    //the loop for the user to enter the coefficients and exponents for the first polynomial
    for(int i = 0; i < numTerms1; i++){
        cout<<"Enter coefficient and exponent: ";
        cin>>tempCoeff>>tempExponent;
        while(tempCoeff > 5){
            cout<< "You must enter an exponent of 5 or less";
            cout<<"Enter coefficient and exponent: ";
            cin>>tempCoeff>>tempExponent;
        }
        inputArray1[tempExponent] = tempCoeff;
    }
    //the loop for the user to enter the coefficients and exponents for the second polynomial
    cout<<"Enter the number of polynomial terms: ";
    cin>>numTerms2;
    cout<<"\n";
    for(int i = 0; i < numTerms2; i++){
        cout<<"Enter coefficient and exponent: ";
        cin>>tempCoeff>>tempExponent;
        while(tempCoeff > 5){
            cout<< "You must enter an exponent of 5 or less\n\n";
            cout<<"Enter coefficient and exponent: ";
            cin>>tempCoeff>>tempExponent;
        }
        cout<<"\n";
        inputArray2[tempExponent] = tempCoeff;
    }
//declare the instances of the Polynomial
    Polynomial poly1;
    Polynomial poly2;
//sets the polynomials to use the input arrays
    poly1.set(inputArray1);
    poly2.set(inputArray2);
    cout<<"First Polynomial is : "<<poly1<<"\n";
    cout<<"Second Polynomial is : "<<poly2<<"\n\n";
//adding the polynomials
    Polynomial poly3 = poly1+poly2;
    cout<<"Adding polynomial yields: "<<poly3<<"\n";
    poly3=poly1;
    poly3+=poly2;
    cout<<"+= the polynomial yields: "<<poly3<<"\n\n";
    poly1.set(inputArray1);  //reseting poly1 Polynomial
//subtracting the polynomials
    Polynomial poly4 = poly1-poly2;
    cout<<"Subtracting the polynomial yields: "<<poly4<<"\n";
    poly4=poly1;
    poly4-=poly2;
    cout<<"-= the polynomial yields: "<<poly4<<"\n\n";
    poly1.set(inputArray1);
    //reseting poly1 Polynomial
//multiplying the polynomials
    Polynomial poly5 = poly1 * poly2;
    cout<<"Multiplying the polynomial yields: "<<poly5<<"\n";
    poly5=poly1;
    poly5*=poly2;
    cout<<"*=the polynomial yields: "<<poly5<<"\n";
}
