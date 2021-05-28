#include <iostream>
#include "sorts.h"

using namespace std;

void input_array(int16_t*, int16_t);

void print_array(int16_t*, int16_t);

int main()
{
	int16_t array_size;
	cout << "enter size of array: ";
	cin >> array_size;
	if (array_size <= 0)
	{
		cerr << "size is unaccerteble" << endl;
		return 1;
	}
	int16_t* array = new int16_t[array_size];
	input_array(array, array_size);
	short int nums_a_sort;
	cin >> nums_a_sort;
	if (nums_a_sort == 1) { merge_sort(array, array_size); }
	if (nums_a_sort == 2) { bubble_sort(array, array_size); }
	if (nums_a_sort == 3) { selection_sort(array, array_size); }
	if (nums_a_sort == 4) { count_sort(array, array_size); }
	print_array(array, array_size);
	delete[] array;
	return 0;
}

void input_array(int16_t* array, int16_t array_size)
{
	for (int16_t i = 0; i < array_size; i++)
	{
		cin >> array[i];
	}
	return;
}

void print_array(int16_t* array, int16_t array_size)
{
	for (int16_t i = 0; i < array_size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return;
}