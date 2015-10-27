#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void printArray(int a[], int a_size)
{
    for(int i=0; i < a_size; i++)
    {
        cout << setw(5) << right << a[i];
        
        if((i+1) % 10 == 0)
        {
            cout << endl;
        }
    }
}

void fillArray(int a[], int a_size)
{
	srand(static_cast<unsigned int>(time(NULL)));

    for(int i=0; i < a_size; i++)
    {
        a[i] = rand() % 1000;
    }
}

int main()
{
	int a[10];
	int* b = new int[10];

	cout << "now using the std array\n";

	fillArray(a, 10);
	printArray(a, 10);

	cout << "now using the pointer array\n";

	fillArray(b, 10);
	printArray(b, 10);

	return 0;
}