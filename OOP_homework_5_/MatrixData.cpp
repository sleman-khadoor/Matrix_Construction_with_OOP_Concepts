// file MatrixData.cpp
// Member function definitions for class MatrixData

#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

#include "MatrixData.h"

// ---------------------------------------------------------------------------
// Default constructor for class MatrixData
MatrixData::MatrixData():h_array(NULL), v_array(NULL), next(NULL){}

MatrixData::MatrixData(int n) : h_array(n), v_array(n-1), next(NULL){}

// ---------------------------------------------------------------------------
// constructor for class MatrixData
MatrixData::MatrixData(MyArray _h, MyArray _v) : h_array(_h), v_array(_v), next(NULL){}

// ---------------------------------------------------------------------------
// Copy constructor for class MatrixData
MatrixData::MatrixData(const MatrixData & md) : next(NULL)
{
	h_array.setColNum(md.h_array.getColNum());
	h_array.setColumns(md.h_array.getColumns());
	v_array.setColNum(md.v_array.getColNum());
	v_array.setColumns(md.v_array.getColumns());

}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for class MatrixData
MatrixData::~MatrixData(){
	next = NULL;
}

// --------------------------------------------------------------------------
// getters
// Get the horizental Array
MyArray MatrixData::getH_Array()const
{
	return h_array;
}

// --------------------------------------------------------------------------
// getters
// Get the vertical Array
MyArray MatrixData::getV_Array()const
{
	return v_array;
}

// --------------------------------------------------------------------------
// getSize h,v
int MatrixData::hSize()const
{
	return h_array.getColNum();
}

int MatrixData::vSize()const
{
	return v_array.getColNum();
}
//---------------------------------------------------------------------------
// get_i_j_
double MatrixData:: get_i_j_(int i,int j)const
{
	if(i>j)
		return v_array.get_i_(i-j-1);
	else
		return h_array.get_i_(j-i);
	
}

// --------------------------------------------------------------------------
// setters
// set the horizental Array
void MatrixData::setH_Array( const MyArray& _h)
{
	h_array.setColNum(_h.getColNum());
	h_array.setColumns(_h.getColumns());
}

// --------------------------------------------------------------------------
// setters
// set the vertical Array
void MatrixData::setV_Array( const MyArray& _v)
{
	v_array.setColNum(_v.getColNum());
	v_array.setColumns(_v.getColumns());
}
//------------------------------------------------------------------------------
//	 set_i_j_
void MatrixData::set_i_j_(int i,int j,double b)
{
	if(i>j)
		v_array.set_i_(i-j-1,b);
	else
		h_array.set_i_(j-i,b);
}
//-------------------------------------------------------------------------------
//	operators
//-------operator << -----------
 ostream &operator<<(ostream & output ,const MatrixData &a)
 {
	 if(a.hSize()==0  &&  a.vSize()==0 )
		 output<<" the array is empty \n";
	 else
	  {
		  for(int i=0;i<a.hSize();i++)
		  {
			  for(int j=0;i<a.vSize();i++)
			  {
				  output<<setw(6)<< a.get_i_j_(i,j);
			  }
			  output<<endl;
		  }
	  }
	 return output;
 }
//-------operator >> -----------
  istream &operator>>(istream &input, MatrixData  &a)
  {
	  double x;
		  for(int i=0;i<a.hSize();i++)
		  {
			  for(int j=0;i<a.vSize();i++)
			  {
				  input>>x;
				   a.set_i_j_(i,j,x);
			  }
		  }
	  return  input;

  }
//--------------------------------

