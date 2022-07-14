#include<iostream>
using namespace std;
#include "container.h"



// ---------------------------------------------------------------------------
// Default constructor for class container 
container::container(void)
{
	colNum=0;
}
//----------------------------------------------------------------------------
//constructor for class container
container::container(int n)
{
	colNum =n;
}
//----------------------------------------------------------------------------
// Destructor for class container
container::~container(void)
{
	
}
//----------------------------------------------------------------------------
// getColNum
int  container:: getColNum () const
{
	if (colNum != 0)
		return colNum;
	else
		return 0;
}
//----------------------------------------------------------------------------
// setColNum
void container:: setColNum (int size ) 
{
	colNum =size ;
}
//----------------------------------------------------------------------------
// read
void container:: read () 
{ 
	cout <<"Enter The colNum \n";
	int x; 
	cin>>x;
	colNum=x;
}
//----------------------------------------------------------------------------
// print
void container:: print ()const
{
	cout<< "The colNum  = "<<colNum<<endl ;
}
//----------------------------------------------------------------------------
//    addition 
void container:: addition ( container* )
{
	cout<<"+";
}
	
	