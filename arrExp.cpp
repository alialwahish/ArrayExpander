// Name: Ali Bayati 
// Array Expander & Element Shifter 


#include<iostream>

using namespace std;

int * expand(int*, int*);
int * loadarray(int);
int * addone(int *, int *);
void print(int*, int);

int main()
{
	int *arr;
	int size ,i;
	cout << "Enter Size of Array: ";
	cin >> size;
	cout << "Loading Array with numbers ... \n";
		
	arr = loadarray(size);
		print(arr, size);
	arr = expand(arr, &size);
	cout << "Expanding the Array ...\n";
	print(arr, size);
	cout << "Shifting the Array ...\n";
	arr = addone(arr, &size);
	print(arr, size);
	return 0;
}
void print(int *arr , int size)
{
	
	int i;
	cout << "Array size :" << size << endl;
	for (i = 0; i < size; i++)
	{
		cout << "Array " << i << ":" << arr[i] << endl;
	}
	cout << endl;
}
int * loadarray(int size)
{
	int *arr = new int[size];
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	
	return arr;
}

int * expand(int* arr, int *size)
{
	int i;
	
	int *newarr = new int[*size * 2];
	for (i = 0; i < *size; i++)
	{
		newarr[i] = arr[i];
				
	}
	for (i = *size; i < (*size * 2); i++)
	{
		newarr[i]=0;
	}

	*size = *size + *size;
		delete[] arr;
			

	return newarr;
}

int * addone(int * arr, int *size)
{
	int *narr = new int[*size + 1];
	narr[0] = 0;
	for (int i = 1; i < *size; i++)
	{
		narr[i] = arr[i-1];

	}
	*size = *size + 1;
	delete[]arr;
	return narr;

}

/*Output
Enter Size of Array: 3
Loading Array with numbers ...
Array size :3
Array 0:1
Array 1:2
Array 2:3

Expanding the Array ...
Array size :6
Array 0:1
Array 1:2
Array 2:3
Array 3:0
Array 4:0
Array 5:0

Shifting the Array ...
Array size :7
Array 0:0
Array 1:1
Array 2:2
Array 3:3
Array 4:0
Array 5:0
Array 6:-842150451

Press any key to continue . . .*/