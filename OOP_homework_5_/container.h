#pragma once
class container
{
public:
//----------------Costructors & Destructor-------------------------------
	container(void);
	container(int );
	~container(void);
//-----------------------------------------------------------------------

//--------------------------getters--------------------------------------
	int getColNum()const;
//-----------------------------------------------------------------------

//--------------------------setters--------------------------------------
	void setColNum(int);	
//-----------------------------------------------------------------------

//--------------------other member functions-----------------------------
	virtual void  read();
	virtual void  print()const;
	virtual void  Ascending_Sort()=0;
	virtual void  Descending_Sort()=0;
	virtual void  addition ( container* );
	
	
protected : 
	int colNum;
};

