// main.CPP
// Driver to test our simple class Array

#include "Matrix.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() 
{


	cout <<"             Welcome to our program made by Mr. Sleman Khadoor     \n";
	cout <<" We will help you to test every detail in our program \n\n";
	cout <<" To see what you asked us to do in the main function please press  <1> \n";
	while(true)
	{
			
		cout <<" To test the class Matrix please press  <2> \n";
		cout <<" To test the class MyArray please press  <3> \n";
		cout <<" To exit the program please press  <4> \n";
		cout <<endl;
		int choise ;
		cout <<" Enter your option  : ";
		cin>>choise;
		cout<<endl;
		while(choise<1 || choise >5)
		{
			cout<<" Error Enter number between <1> and <6> : ";
			cin>>choise;
			cout<<endl;
		 }
	
		switch (choise)
			{
			case 1: 	
				{
					container * contnr[2];
					contnr[0]=new MyArray();
					contnr[1]=new Matrix();
					contnr[0]->read();
					contnr[1]->read();
					contnr[0]->print();	
					contnr[1]->print();
					contnr[0]->Ascending_Sort();
					contnr[0]->print();
					contnr[0]->Descending_Sort();
					contnr[0]->print();
					contnr[1]->Ascending_Sort();
					contnr[1]->print();
					contnr[1]->Descending_Sort();
					contnr[1]->print();
					MyArray *a=new MyArray();
					cout <<" Enter the new Array : \n" ;
					cin>>*a;
					contnr[1]=a;
					cout <<" contnr[1] after the operation (contnr[1] = The New Array ) : \n" ;
					contnr[1]->print();
					contnr[1]->addition(a);
					cout <<" contnr[1] after addition the new Array to contnr[1] : \n" ;
					contnr[1]->print();
					break;
			
				}

			case 2: 
				{
					cout<<" Testing the class Matrix  \n";
					cout<<" Enter the size of the matrix :  ";
					int size;
					cin>> size;
					cout<<endl;
					Matrix mat(size);
					cin>>mat;
					cout<<endl;
					while(true)
					{
						int bro=1;
						cout<<" To test the class Matrix you have these options : \n\n";
						cout<<" To test if your Matrix empty or not please press   <1>\n";
						cout<<" To print the Matrix please press   <2> \n";
						cout<<" To sort the Matrix in  Ascending order please press   <3> \n";
						cout<<" To sort the Matrix in  Descending order please press   <4> \n";
						cout<<" To edit an element of the Matrix  please press   <5>\n";
						cout<<" To get the value of an element please press   <6>\n";
						cout<<" To Test the operator( = )please press  <7>\n";
						cout<<" To Test the operator( * )please press  <8>\n";
						cout<<" To return to the main Menu press   <9>\n";
						cout <<endl;
						int choise1 ;
						cout <<" Enter your option  : ";
						cin>>choise1;
						cout<<endl;
						switch(choise1)
						{
						case 1:
							{
								if(mat.operator!()==true)
									cout<<" The Matrix is empty \n";
								else
									cout<<" The Matrix is not empty \n";
								break;
							}
						case 2:
							{
								mat.print();
								break;
							}
						case 3:
							{
								mat.Ascending_Sort();
								break;
							}
						case 4:
							{
								mat.Descending_Sort();
								break;
							}
						case 5:
							{
								cout<<" Enter the index of the element you want to edit :\n";
								cout<<" Enter the line number : ";
								int i;
								cin>>i;
								cout<<" Enter the column number : ";
								int j;
								cin>>j;
								cout <<" Enter the new value of this element : ";
								double v;
								cin>>v;
								mat.set_i_j(i,j,v);
								break;
							}
						case 6:
							{
								cout<<" Enter the index of the element you want its value :\n";
								cout<<" Enter the line number : ";
								int i;
								cin>>i;
								cout<<" Enter the column number : ";
								int j;
								cin>>j;
								cout<<"\n The element  mat["<<i<<"]"<<"["<<j<<"]="<<mat[i][j]<<endl;
								break;
							}
						case 7:
							{
								cout<<" You will enter new Matrix and we will replace the old one with it using (=)\n";
								cout<<" Enter the size of the matrix :  ";
								int n;
								cin>> n;
								cout<<endl;
								Matrix ax(n);
								cin>>ax;
								size=n;
								mat=ax;
								break;
							}
						case 8:
							{
								cout<<" You will enter new Matrix and we will print \n";
								cout<<" the value of (Old Matrix[][] * New Matrix[][]) \n";
								Matrix ax(size);
								cin>>ax;
								cout<<" The value of (Old Matrix[][] * New Matrix[][]) is the following Matrix \n"<<mat*ax;
								break;
								
							}
						case 9:
							{
								bro=0;
								cout<<endl;
								break;
							}

						}
						if(bro==0)
							break;
						cout<<endl;
						
					}
					break;
				}
			case 3: 
				{  

					cout<<" Testing the class MyArray  \n";
					MyArray Array;
					Array.read(); 
					cout<<endl;
					while(true)
					{
						int bro=1;
						cout<<" To test the class MyArray you have these options : \n\n";
						cout<<" To test if your Array empty or not please press   <1>\n";
						cout<<" To print the Array please press   <2> \n";
						cout<<" To sort the Array in  Ascending order please press   <3> \n";
						cout<<" To sort the Array in  Descending order please press   <4> \n";
						cout<<" To edit an element of the Array  please press   <5>\n";
						cout<<" To get the value of an element please press   <6>\n";
						cout<<" To test the operator ( = ) please press   <7>\n";
						cout<<" To test the operator ( + ) please press   <8>\n";
						cout<<" To test the operator ( - ) please press   <9>\n";
						cout<<" To return to the main Menu press   <10>\n";
						cout <<endl;
						int choise1 ;
						cout <<" Enter your option  : ";
						cin>>choise1;
						cout<<endl;
						switch(choise1)
						{
						case 1:
							{
								if(Array.operator!()==true)
									cout<<" The Array is empty \n";
								else
									cout<<" The Array is not empty \n";
								break;
							}
						case 2:
							{
								Array.print();
								break;
							}
						case 3:
							{
								Array.Ascending_Sort();
								break;
							}
						case 4:
							{
								Array.Descending_Sort();
								break;
							}
						case 5:
							{
								cout<<" Enter the index of the element you want to edit : ";
								int i;
								cin>>i;
								cout <<" Enter the new value of this element : ";
								double v;
								cin>>v;
								Array.set_i_(i,v);
								break;
							}
						case 6:
							{
								cout<<" Enter the index of the element you want its value : ";
								int i;
								cin>>i;
								cout<<"\n The element  Array["<<i<<"] = "<<Array[i]<<endl;
								break;
							}
						case 7:
							{
								
								cout<<" You will enter new Array and we will replace the old one with it using (=)\n";
								MyArray ax;
								cin>>ax;
								Array=ax;
								break;

							}
						case 8:
							{
								
								cout<<" You will enter new Array and we will print  \n";
								cout<<" the value of (Old Array[] + New Array[]) \n";
								MyArray ax;
								cin>>ax;
								cout<<" the value of (Old Array[] + New Array[]) is the following Array \n"<<Array+ax<<endl;
								break;

							}
						case 9:
							{
								
								cout<<" You will enter new Array and we will print  \n";
								cout<<" the value of (Old Array[] - New Array[]) \n";
								MyArray ax;
								cin>>ax;
								cout<<" the value of (Old Array[] - New Array[]) is the following Array \n"<<Array-ax<<endl;
								break;

							}
						case 10:
							{
								bro=0;
								cout<<endl;
								break;
							}

						}
						if(bro==0)
							break;
						cout<<endl;
						
					}
					break;
				
				}

			

			case 4:    
				{
					cout <<"\n    Created by Sleman Khaddor ^_^  \n\n";
					exit(0);
				}
      
           }
	


	//
	//MyArray ax;
	//ax.read();
	//ax.print();
	//ax.Ascending_Sort();
	//ax.print();
	//ax.Descending_Sort();
	//ax.print();
	//cout <<"Enter the size of the matrix (n*n) \n";
	//int n;
	//cin>>n;
	//cout <<"This Size will be the default size of the matrices \n";
	//Matrix a,b(n);
	//cout <<"\nWe will make two matrices for you  \n";
	//cout <<"\nEnter the elements of the matrix a[]\n";
	//a.read();
	//cout <<"\nThe  matrix a[]\n";
	//cout<<a<<endl;
	//cout<<endl;
	////---------- BONUS-----[][]-------------
	//cout << "a[0][0]="<<a[0][0]<<endl;
	//cout << "a[0][1]="<<a[0][1]<<endl;
	//cout << "a[1][0]="<<a[1][0]<<endl;
	//cout << "a[1][1]="<<a[1][1]<<endl;
	////--------------------------------------
	//cout<<endl;
	////---------- BONUS----------------------
	//a<=a;   // sorting in ascending order
	////--------------------------------------
	//cout<<endl;
	////---------- BONUS-----[][]-------------
	//cout << "a[0][0]="<<a[0][0]<<endl;
	//cout << "a[0][1]="<<a[0][1]<<endl;
	//cout << "a[1][0]="<<a[1][0]<<endl;
	//cout << "a[1][1]="<<a[1][1]<<endl;
	////--------------------------------------
	//cout<<endl;
	////---------- BONUS----------------------
	//a>=a;   // sorting in descending order
	////--------------------------------------
	//cout<<endl;
	////---------- BONUS-----[][]-------------
	//cout << "a[0][0]="<<a[0][0]<<endl;
	//cout << "a[0][1]="<<a[0][1]<<endl;
	//cout << "a[1][0]="<<a[1][0]<<endl;
	//cout << "a[1][1]="<<a[1][1]<<endl;
	////---------------------------------------
	//cout <<"\nEnter the elements of the matrix b[]\n";
	//cin>>b;

	//while(true)
	//{
	//	cout<<"you have these options: \n";
	//	cout <<"press 1 to print a[] \n";
	//	cout <<"press 2 to print b[] \n";
	//	cout <<"press 3 to print the result of a[]*b[] \n";
	//	cout <<"press 4 to do this  (b[]=a[])   \n";
	//	cout <<"press 5 to do this  (a[]=b[])   \n";
	//	cout <<"press 6 to exit  \n";
	//	int m;
	//	cin>>m;
	//	switch (m)
	//	{
	//	case 1: 	cout <<"\nThe  matrix a[]\n";
	//				cout<<a<<endl;
	//				break;

	//	case 2:     cout <<"\nThe  matrix b[]\n";
	//				cout<<b<<endl;
	//				break;

	//	case 3:     cout <<"\nThe  matrix a[]*b[]\n";
	//				cout<<a*b<<endl;
	//				break;

	//	case 4:     b=a;
	//		        break;


	//	case 5:     a=b;
	//		        break;

	//	case 6:     exit(0);
	//	}
	//}
//--------------------- the array ------------
	//MyArray a,b;
	//cin >> a;
	//cout <<"a[]= "<<a<<endl;
	//cin>>b;
	//cout <<"b[]= "<<b<<endl;
	//cout <<"\na[] + b[] = ";
	//cout << a+b <<endl;
	//cout <<"\na[] - b[] = ";
	//cout << a-b <<endl;
	//cout <<"\nThe Array a[] in Ascending Order : \n ";
	//a<a;
	//cout<<a;
	//cout <<"\nThe Array a[] in Descending Order : \n ";
	//a>a;
	//cout<<a;
	
}
	return 0;
}

