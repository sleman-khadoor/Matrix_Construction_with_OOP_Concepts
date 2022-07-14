// file MatrixData.h
// Composed class MatrixData (compose of Two Array)
// CREATED BY: Sleman Khadoor
//
//---------------------------------------------------------------------------
#ifndef MATRIXDATA_H
#define MATRIXDATA_H

#include "MyArray.h"
//---------------------------------------------------------------------------
// MatrixData class:  as if we have two Array the first is Horisental,
// while the second is Vertical.
//   this class should get use of all the operations on the MyArray class:
//
// Assumptions:
//   -- in <<, MatrixData are displayed in this form:
//	a11	a12	a13	.	.	a1n
//	a21
//	a31
//	.
//	.
//	.
//	am1
//---------------------------------------------------------------------------
class MatrixData{
		friend ostream &operator<<(ostream &,const MatrixData &);
	    friend istream &operator>>(istream &, MatrixData  &);

public:

//----------------Costructors & Destructor-------------------------------
	MatrixData();
	MatrixData(int );
	MatrixData(MyArray, MyArray );
	MatrixData(const MatrixData& );
	~MatrixData();
//-----------------------------------------------------------------------

//--------------------------setters--------------------------------------
	void setH_Array(const MyArray& );
	void setV_Array(const MyArray& );
	void set_i_j_(int,int,double);
//-----------------------------------------------------------------------

//--------------------------getters--------------------------------------
	MyArray getH_Array()const;
	MyArray getV_Array()const;
	int hSize()const;
	int vSize()const;
	double get_i_j_(int ,int )const;
//--------------------------operators-----------------------------------
	
//-----------------------------------------------------------------------
	MatrixData * next;
private:
	MyArray h_array;	//Horisental Array
	MyArray v_array;		//Vertical Array
	
};


#endif