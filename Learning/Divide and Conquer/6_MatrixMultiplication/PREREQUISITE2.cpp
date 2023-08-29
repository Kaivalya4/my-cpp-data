/*
 Allocation and Deallocation for 1D array-
-> pointVar = new datatype[size];
-> delete[] pointVar
*/
#include<iostream>

using namespace std;

int main()
{
	///1D array
	{
		cout << "Enter the size of Array : ";
		int n;
		cin >>n;
		int *arr = new int[n];
		cout << "Enter the elements of Array : ";
		for(int i=0;i<n;i++)
		{
			cin >> *(arr+i);
		}
		cout << "Value of the arrays are : ";
		for(int i=0; i<n;i++)
		{
			cout << *(arr+i) << " ";
		}
		cout << endl;
		delete[] arr;
	}
	
	///2D array - remember here we are creating single array of large size.
	{
		cout << "Enter the number of rows: ";
		int n;
		cin >> n;
		cout << "Enter the number of columns: "	;
		int m;
		cin >> m;
		int *matrix = new int[n*m];
		cout << "Enter the value of matrix : ";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> *(matrix + i*m + j) ;
			}
		}	
		cout << "Value of the value of matrix : ";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout <<  *(matrix + i*m + j) << " ";
			}
			cout << endl;
		}	
		delete[] matrix;
	}
	
	///preferred of way of 2d array using array of pointers i.e we create an array of pointer whose each element
	///are pointers . Those pointers will point to one respective array.
	{
		cout << "Enter the number of rows: ";
		int n;
		cin >> n;
		cout << "Enter the number of columns: "	;
		int m;
		cin >> m;
		
		/// see new int*[] i.e. type is int pointer i.e. create an array of pointers
		int **matrix = new int*[n];
		for(int i=0;i<n;i++)
		{
			matrix[i] = new int[m];
		}
		cout << "Enter the value of matrix : ";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> matrix[i][j] ;
			}
		}	
		cout << "Value of the value of matrix : ";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout <<  matrix[i][j] << " ";
			}
			cout << endl;
		}	
		
		///first deallocate the each array.
		for(int i=0;i<n;i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	return 0;
}