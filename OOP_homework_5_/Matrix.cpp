// file Matrix.cpp
// Member function definitions for class Matrix

#include <iostream>
#include <cassert>
#include <iomanip>
#include <math.h>
#include "Matrix.h"
#include "container.h"
#include <vector>
using namespace std;

Matrix::Matrix():container()
{
	first = last = NULL;
}

Matrix::Matrix(const Matrix &m)
{
	
	MatrixData* m_ptr = m.first;
	while(m_ptr!=NULL)
	{
		addlast(m_ptr);
		m_ptr=m_ptr->next;
	}
}

Matrix::Matrix(int n):container(n)
{
	MatrixData *p=new MatrixData(n);
	first=last=p;
	for(int i=0;i<n-1;i++)
	{
		MatrixData *b=new MatrixData(n-i-1);
		last->next=b;
		last=b;
	}
}

Matrix::~Matrix()
{
	MatrixData* tmp;
	while(first)
	{
		tmp = first;
		first = first->next;
		delete tmp;
		tmp = NULL;
	}
	first = last = NULL;
}
//-----------get i j-----------------

double Matrix::get_i_j(int i ,int j )const
{
	int k=0;
	MatrixData *p=first;
	while(k<i && k<j)
	{
		p=p->next;
		k++;
	}
	return p->get_i_j_(i,j);
}
//-------------set i j --------------
void Matrix:: set_i_j(int i,int j, double b)
{
	
	int k=0;
	MatrixData *p=first;
	while(k<i && k<j)
	{
		p=p->next;
		k++;
	}
	p->set_i_j_(i,j,b);
}

//------------read-----------------
void Matrix :: read()
{
	cout<<" Enter the colNum of the matrix : ";
	int x; 
	cin>>x;
	colNum=x;
	Matrix a(colNum);
	*this=a;
	cout<<endl;
	cin>>*this;
}
//---------print --------------------
void  Matrix::print()const
{
	cout <<*this<<endl;
}

//----------- Ascending_Sort---------
void Matrix:: Ascending_Sort()
{
	this->operator<=(*this);
}
//----------- Descending_Sort -------
void Matrix:: Descending_Sort()
{
	this->operator>=(*this);
}
//-----------------------------------
void Matrix::addlast(MatrixData *q)
{
	MatrixData *p=new MatrixData(*q);
	if(first == NULL){
		first = p;
		last = p;
	}
	else{
		last->next = p;
		last = last->next;
	}


	
}
//----------------------------------------
//		operators
//-----operator = ---------------
Matrix &Matrix::operator=(const Matrix&a)
{
	MatrixData* tmp;
	while(first)
	{
		tmp = first;
		first = first->next;
		delete tmp;
		tmp = NULL;
	}
	first = last = NULL;
	MatrixData* m_ptr = a.first;
	if(m_ptr!=NULL)
	{
		MatrixData* temp;
		first=new MatrixData(*m_ptr);
		first->next=NULL;
		temp=first;
		m_ptr=m_ptr->next;
		while(m_ptr)
		{
			temp->next=new MatrixData (*m_ptr);
			temp=temp->next;
			temp->next=NULL;
			m_ptr=m_ptr->next;
		}
	    last=temp;
	}
	return *this;
	
}
//--------operator ! -------------
bool Matrix:: operator!()
{
	if (first==NULL && last==NULL)
		return true;
	else
		return false;
}
//---------- operator <<---------
 ostream &operator<<(ostream &output,const Matrix &a)
 {
	 
	 if(a.first==NULL  &&  a.last==NULL )
		 output<<" The Matrix is empty <!>\n";
	 else
	  {
		  output<<" The Matrix  is : \n";
		  for(int i=0;i<a.first->hSize();i++)
		  {
			  for(int j=0;j<a.first->hSize();j++)
			  {
				  output<<setw(6)<< a.get_i_j(i,j);
			  }
			  output<<endl;
		  }
	  }
	 return output;
 }
//--------- operator >> ----------
  istream &operator>>(istream &input, Matrix &a)
  {
	 
	  double x;
	  cout <<" Enter the elements of the Matrix :\n";
	  for(int i=0;i<a.first->hSize();i++)
		  {
			  for(int j=0;j<a.first->hSize();j++)
			  {
				  input>> x;
				  a.set_i_j(i,j,x);
			  }
			  
		  }
		  return input;
  }
//------operator * ---------------
Matrix &Matrix:: operator*(const Matrix &a)
{			double sum=0;
			Matrix *mat=new Matrix(a.first->hSize());
			
			if (first->hSize()!=a.first->hSize())
			{ 
				cout<<" Error \n"<<endl;
			return *this;
            }


			   for (int i=0;i<a.first->hSize() ; i++) 
				      {   for (int j=0;j<a.first->hSize() ; j++) 
							 {
								 for (int k=0;k<a.first->hSize() ; k++)
									{
										sum+= this->get_i_j(i,k) * a.get_i_j(k,j);
									}
								 mat->set_i_j (i,j,sum);
								 sum =0;
							 }
					   }
			  
						
		return *mat;
}

//---------- operator [] -------------------- BONUS--------------------
MyArray Matrix::operator[] (int i)
{
	int j;
	int x=this->first->getH_Array().getColNum();
	MyArray a(x);
	for (j=0;j<a.getColNum();j++)
		a.set_i_(j,this->get_i_j(i,j));
	return a;
	}
//-----------operator <= ---------------------- BONUS--------------------
// sorting in ascending order

Matrix &Matrix:: operator<=( Matrix &a)
{

	int n= a.colNum*a.colNum;
	vector <double> X;
	 for(int i=0; i<a.colNum; i++)
    {
        for(int j=0; j<a.colNum; j++)
        {
			X.push_back(a[i][j]);
           
        }
    }

	 
	for(int i=0 ; i<n-1 ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			if(X[i]>X[j])
				{
					double b;
					b=X[i];
					X[i]=X[j];
					X[j]=b;
			    }

		}

	}
	
	
	int k=0;
	for(int i=0; i<a.colNum ; i++)
    {
		for(int j=0; j<a.colNum; j++)
        {
			a.set_i_j(i,j, X[k]);
            k++;
        }
    }

	cout <<" The matrix has been sorted in Ascending order \n";
	

	return a;
}
//-----------operator >= ------------------------- BONUS--------------------
//operator >=      sorting in descending order

Matrix &Matrix:: operator>=( Matrix &a)
{

	int n= a.colNum*a.colNum;
	vector <double> X;
	 for(int i=0; i<a.colNum; i++)
    {
        for(int j=0; j<a.colNum; j++)
        {
			X.push_back(a[i][j]);
           
        }
    }

	 
	for(int i=0 ; i<n-1 ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			if(X[i]<X[j])
				{
					double b;
					b=X[i];
					X[i]=X[j];
					X[j]=b;
			    }

		}

	}
	
	
	int k=0;
	for(int i=0; i<a.colNum ; i++)
    {
		for(int j=0; j<a.colNum; j++)
        {
			a.set_i_j(i,j, X[k]);
            k++;
        }
    }

	cout <<" The matrix has been sorted in Descending order \n";
	

	return a;
}