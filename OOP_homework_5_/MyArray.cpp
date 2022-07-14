// file MyArray.cpp
// Member function definitions for class MyArray

#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

#include "MyArray.h"

// ---------------------------------------------------------------------------
// Default constructor for class MyArray //default size = 1
MyArray::MyArray():container(0), columns(new double[0]) {}

// ---------------------------------------------------------------------------
// constructor for class MyArray
MyArray::MyArray(int size):container(size) {
	columns = new double[size];                   // create space for MyArray
	assert(columns != 0);
	for(int i=0; i<size; i++){
		columns[i] = 0.0;
	}
}

// --------------------------------------------------------------------------- 
// constructor for class MyArray
MyArray::MyArray(double* MyArrayPtr, int size):container(size){
	columns = new double[colNum];
	// create space for MyArray
	columns = MyArrayPtr;
}

// ---------------------------------------------------------------------------
// Copy constructor for class MyArray
MyArray::MyArray(const MyArray &init) {
	this->setColNum(init.colNum);                 // create space for MyArray
	for (int i = 0; i < colNum; i++)
		columns[i] = init.columns[i];             // copy init into object
}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for class MyArray
MyArray::~MyArray() {
	if(colNum != 0)
	{
		delete [] columns;                             // reclaim space for MyArray
		columns = NULL;
	}
}

// --------------------------------------------------------------------------
// getColumns
double* MyArray::getColumns() const {
	if (colNum != 0)
		return columns;
	else
		return NULL;
}
// --------------------------------------------------------------------------
// get_i_
double MyArray ::get_i_(int i) const
{
	if(i>=0 && i<colNum)
		return columns[i];
	else 
		cout <<" <!> this index is wrong \n";
		return 0.0;

}
//---------------------------------------------------------------------------
// setSize 
// set the size of the MyArray
void MyArray::setColNum(int size){
	container::setColNum(size);
	columns = new double[size];
	for(int i=0; i<size; i++)
		columns[i] = 0.0;
}

// --------------------------------------------------------------------------
// setColumns 
void MyArray::setColumns(double* clmns){
	for(int i=0; i<colNum; i++)
		columns[i] = clmns[i];
}
//--------------------------------------------------------------------------
// set element 
void MyArray:: set_i_(int i,double b)
{
	columns[i]=b;
}
//---------------------------------------------------------------------------
//  addition
void MyArray:: addition (container *a)
{
	
	MyArray * x;
	x= new MyArray();
	x= (MyArray*)a;	
	int max,min;
	if(this->colNum >x->colNum)
		{
			max=this->colNum;
			min=x->colNum;
    	}
	else
		{
			max=x->colNum;
			min=this->colNum;

		}
	MyArray *res;
	bool f=(colNum>x->colNum);
	res=new MyArray(max);
	for(int i=0;i<min;i++)
		res->columns[i]=columns[i]+x->columns[i];
	for(int i=min;i<max;i++)
		{
			if(f)
			    res->columns[i]=columns[i];
		   else
			    res->columns[i]=x->columns[i];
     	}
	*this=*res;

}
//---------------------------------------------------------------------------
//   read  
   void MyArray::read()
   { 
	   cin>> *this ;
   }
//--------------------------------------------------------------------------
//  print
   void MyArray::print()const
   {  
	
	   cout<< *this<<endl;
   }
//---------------------------------------------------------------------------
//   Ascending_Sort
   void MyArray:: Ascending_Sort()
   {
	   this->operator<(*this);
   }
//---------------------------------------------------------------------------
//   Descending_Sort()
   void MyArray:: Descending_Sort()
   {
	   this->operator>(*this);
   }
//---------------------------------------------------------------------------
//  operators
//-------operator << -----------
 ostream &operator<<(ostream & output ,const MyArray &a)
 {
	 if(a.colNum==0)
		 output<<" The array is empty  <!> \n";
	 else
	  {
		    output<<" The array is : \n";
		    output<<"< ";
		    for(int i=0;i<a.colNum;i++)
			 {
				 if(i<a.colNum-1)
					 output<<a.get_i_(i)<<",";
				 else
					  output<<a.get_i_(i);
			 }
			 output<<" >";
			 output<<endl;
	  }
	 return output;
 }
 //------operator >> ------------
 istream &operator>>(istream &input, MyArray &a)
 {
	 cout <<" Enter the dimention of the array : ";
	 int size; input>>size;
	 a.setColNum( size);
	 cout <<endl;
	 cout <<" Enter the elements of the array \n";
	 for(int i=0;i<a.colNum;i++)
		 input >> a.columns[i];
	 return input;
 }
//-------operator ! -------------
bool MyArray:: operator!( )
{
	if(colNum==0)
		return true;
	else 
		return false;
}
//-------operator = --------------
MyArray &MyArray::operator=(const MyArray &a)
{
	colNum=a.colNum;
	for(int i=0;i<colNum;i++)
	{
		columns[i]=a.columns[i];
	}
	return *this;
}
//--------operator + --------------
MyArray &MyArray::operator+(const MyArray &a)
{
	MyArray *res;
	int maxn=max(colNum,a.colNum);
	int minn=min(colNum,a.colNum);
	bool f=(colNum>a.colNum);
	res=new MyArray(maxn);
	for(int i=0;i<minn;i++)
		res->columns[i]=columns[i]+a.columns[i];
	for(int i=minn;i<maxn;i++)
		if(f)
			res->columns[i]=columns[i];
		else
			res->columns[i]=a.columns[i];
	
	return *res;
}
//------------operator - -----------------------
MyArray &MyArray::operator-(const MyArray &a)
{
	MyArray *res;
	int maxn=max(colNum,a.colNum);
	int minn=min(colNum,a.colNum);
	bool f=(colNum>a.colNum);
	res=new MyArray(maxn);
	for(int i=0;i<minn;i++)
		res->columns[i]=columns[i]-a.columns[i];
	for(int i=minn;i<maxn;i++)
		if(f)
			res->columns[i]=columns[i];
		else
			res->columns[i]=-a.columns[i];
	return *res;
}
//----------operator [] -----------------
double MyArray::operator[]( int i )
{
	return get_i_(i);


}
//-------operator < -----------------------
MyArray &MyArray::operator<(MyArray &a)
{
	
	for(int i=0 ; i<a.colNum-1 ; i++)
	{
		for(int j=i+1 ; j<a.colNum ; j++)
		{
			if(a.columns[i]>a.columns[j])
				{
					double b;
					b=a.columns[i];
					a.columns[i]=a.columns[j];
					a.columns[j]=b;
			    }

		}
	}
	cout<<" The Array has been sorted in Ascending order  \n";
	return a;
}

//-------operator > -----------------------
MyArray &MyArray:: operator>(MyArray &a)
{
	for(int i=0 ; i<a.colNum-1 ; i++)
	{
		for(int j=i+1 ; j<a.colNum ; j++)
		{
			if(a.columns[i]<a.columns[j])
				{
					double b;
					b=a.columns[i];
					a.columns[i]=a.columns[j];
					a.columns[j]=b;
			    }

		}
	}
	
	cout<<" The Array has been sorted in Descending order  \n";
	
	return a; 
}