/* Name: Jonathan Price
   Date: 10/11/2019
   Course: CIT-245-Z02B
   
   The purpose of this file is to create an int, a pointer to that int, and a
   pointer to that pointer, then make two classes to demonstrate deep and
   shallow copy that also include a destructor. */

//Set up libraries with console input and output facilities
#include <iostream>
#include <cstdlib>
using namespace std;

//Create deep copy class
class WrapArrayDeep
{
	private:
		char *pca;
	public:
		//Default constructor
		WrapArrayDeep() 
		{
			pca = new char[5];
			*pca = 97;
			*(pca + 1) = 98;
			*(pca + 2) = 99;
			*(pca + 3) = 100;
			*(pca + 4) = 101;
		}
		
		//Copy constructor
		WrapArrayDeep(WrapArrayDeep &wad)
		{
			pca = new char[5];
			for (int i = 0; i < 5; i++)
			{
				pca[i] = wad.pca[i];
			}
		}

		//Display
		void display() 
		{
			for (int i = 0; i < 5; i++)
			{
				cout << pca[i] << "\t";
			}
			cout << endl;
		}
		
		//Mutator
		void set(int index, char value)
		{
			pca[index] = value;
		}

		//Accessor
		int get(int index)
		{
			return pca[index];
		}

		//Destructor
		~WrapArrayDeep()
		{
			cout << "Calling destructor for WrapArrayDeep." << endl;
			delete[] pca;
		}
};

//Create shallow copy class
class WrapArrayShallow
{
	private:
		char *pca;
	public:
		//Default constructor
		WrapArrayShallow() 
		{
			pca = new char[5];
			pca[0] = 'a';
			pca[1] = 'b';
			pca[2] = 'c';
			pca[3] = 'd';
			pca[4] = 'e';
		}
		
		//Copy constructor
		WrapArrayShallow(WrapArrayShallow &was) 
		{
			pca = new char[5];
			pca = was.pca;
		}

		//Display
		void display() 
		{
			for (int i = 0; i < 5; i++)
				cout << *(pca + i) << "\t";
			cout << endl;
		}

		//Mutator
		void set(int index, char value) 
		{ 
			pca[index] = value; 
		}
		
		//Accessor
		int get(int index) 
		{ 
			return pca[index]; 
		}

		//Note: Does not work on my compiler. Causes program to crash.
		//Destructor
		~WrapArrayShallow() 
		{
			cout << "Calling destructor for WrapArrayShallow." << endl;
			//delete[] pca;
		}
};

//Main program
int main()
{
	//Introduce first part of program
	cout << "This program section uses 3 variables:" << endl;
	cout << "i = 7; pi, a pointer to i; and ppi, a pointer to pi." << endl;

	/* Create int i with value of 7 and pointer to int pi, point pi to i, then print pointer, address, 
	and dereference. */
	int i = 7;
	int *pi = &i;
	cout << "pi = " << pi << endl;
	cout << "Address of pi: " << &pi << endl;
	cout << "Address of i: " << &i << endl;
	cout << "Dereference of pi: " << *pi << endl << endl;

	/* Create pointer to int pointer ppi, point it to pointer to int pi, then print ppi, address of ppi,
	dereference to ppi and a double dereference to ppi. */
	int **ppi;
	ppi = &pi;
	cout << "ppi = " << ppi << endl;
	cout << "Address of ppi: " << &ppi << endl;
	cout << "Dereference of ppi: " << *ppi << endl;
	cout << "Double dereference of ppi: " << **ppi << endl << endl;
	cout << endl;

	//Set up arrays, then introduce second part of program
	WrapArrayDeep wad1;
	WrapArrayShallow was1;
	cout << "This section instantiates a wrapper class for a dynamic array of 5 elements." << endl;
	cout << endl;

	//Display original deep copy array
	cout << "WrapArrayDeep 1: " << endl;
	wad1.display();

	//Create and display copy of deep copy array
	WrapArrayDeep wad2(wad1);
	cout << "WrapArrayDeep 2: (Created using the copy constructor on 1)" << endl;
	wad2.display();

	//Modify the original deep copy array, then display both deep copy arrays
	wad1.set(0, '{');
	wad1.set(1, '|');
	wad1.set(2, '}');
	wad1.set(3, '~');
	wad1.set(4, '^');
	cout << "After changing the contents of WrapArrayDeep 1..." << endl; 
	cout << "WrapArrayDeep 1:" << endl;
	wad1.display();
	cout << "WrapArrayDeep 2:" << endl;
	wad2.display();
	cout << endl;

	//Display original shallow copy array
	cout << "Now doing the same thing with WrapArrayShallow..." << endl; 
	cout << "WrapArrayShallow 1:" << endl;
	was1.display();

	//Create and display copy of shallow copy array
	WrapArrayShallow was2(was1);
	cout << "WrapArrayShallow 2: (Created using the copy constructor on 1)" << endl;
	was2.display();

	//Modify the original shallow copy array, then display both shallow copy arrays
	was1.set(0, '{');
	was1.set(1, '|');
	was1.set(2, '}');
	was1.set(3, '~');
	was1.set(4, '^');
	cout << "After changing the contents of WrapArrayShallow 1..." << endl;
	cout << "WrapArrayShallow 1:" << endl;
	was1.display();
	cout << "WrapArrayShallow 2:" << endl;
	was2.display();
	cout << endl;

	//End program
	system("PAUSE");
	return 0;
}