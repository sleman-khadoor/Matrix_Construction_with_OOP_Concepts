// file MyArray.h
// Simple class MyArray (for doubles)
// CREATED BY: Sleman Khadoor
// 
//---------------------------------------------------------------------------
#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
#include "container.h"
using namespace std;

//---------------------------------------------------------------------------
// MyArray class:  the same as double Array (reimplement all functionality) but also
//   provide additional operations:
//   -- input and output of the whole MyArray
//   -- comparison of 2 MyArrays, element by element
//   -- assignment of 2 MyArrays
//   -- addition-substraction-multiplication Arithmatic Operations
//
// Assumptions:
//   -- size defaults to a fixed size of 0 if size is not specified
//   -- MyArray elements are initialized to zeros
//   -- user must enter valid doubles when using >>
//   -- in <<, MyArrays are displayed in this form: {a1, a2, a3}
//---------------------------------------------------------------------------

class MyArray :public container {
	    friend class MatrixData; 
		friend ostream &operator<<(ostream &,const MyArray &);
	    friend istream &operator>>(istream &, MyArray &);

public:

//----------------Costructors & Destructor-------------------------------
	MyArray();								// default constructor
    MyArray(int);                      // a constructor with the size
    MyArray(double*, int);				// another constructor
    MyArray(const MyArray &);               // copy constructor
	~MyArray();                              // destructor
//-----------------------------------------------------------------------

//-----------------------operators----------------------------------------

	bool operator!( );
    MyArray &operator=(const MyArray &);
	MyArray &operator+(const MyArray &);
	MyArray &operator-(const MyArray &);
	double operator[]( int );
	MyArray &operator<(MyArray &);
	MyArray &operator>(MyArray &);
//--------------------------getters--------------------------------------

   double* getColumns() const;              // return the elements of MyArray
   double get_i_(int)	const;					// return the element in the index i
  
//-----------------------------------------------------------------------

//--------------------------setters--------------------------------------
   void setColNum(int =0);					// set the size of MyArray object
   void setColumns(double* );				// set the elements of MyArray object
    void  set_i_(int ,double);				// set an element
//-----------------------------------------------------------------------
void  addition (container * );
void read();
void print()const ;
void  Ascending_Sort();
void  Descending_Sort();

//-----------------------------------------------------------------------
private:
   double* columns;                          // pointer to first element of MyArray                               
};

#endif

