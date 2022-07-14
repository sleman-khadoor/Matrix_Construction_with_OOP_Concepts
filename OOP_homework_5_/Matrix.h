// file Matrix.h
// Composed class Matrix (simply is a linkedList of MatrixFields)
// CREATED BY: Sleman Khadoor
// 
//---------------------------------------------------------------------------
#ifndef MATRIX_H
#define MATRIX_H

#include "MatrixData.h"
#include "container.h"

class Matrix :public container{

	
	friend ostream &operator<<(ostream &,const Matrix &);
	friend istream &operator>>(istream &, Matrix &);

public:
//----------------Costructors & Destructor-------------------------------
	Matrix();
	Matrix( const Matrix& );
	Matrix( int );
	~Matrix();
//-----------------------------------------------------------------------
	double get_i_j(int ,int )const;
	void set_i_j(int,int, double);
//----------------------------------
	void read();
    void print()const ;
    void  Ascending_Sort();
    void  Descending_Sort();
	
//-----------operator----------------------------------------------------
	Matrix &operator=(const Matrix &);
	MyArray operator[]( int );//--------------- BONUS--------------------
	bool operator!();
	Matrix &operator*(const Matrix &);
	Matrix &operator<=(Matrix &);//---------- BONUS----------------------
	Matrix &operator>=(Matrix &);//---------- BONUS----------------------
//-----------------------------------------------------------------------
	
	

private:
	void addlast(MatrixData *p);
	MatrixData* first;
	MatrixData* last;

};

#endif