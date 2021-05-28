#include "sorts.h"
#include <iostream>

void merge_sort(int16_t* array, int16_t array_size)
{
	if (array_size <= 1) //base case
	{
		return;
	}
	int16_t middle = array_size / 2;
	int16_t* left = array;
	int16_t* right = array + middle;
	int16_t left_size = middle, right_size = array_size - middle;
	merge_sort(left, left_size); // 0 -- middle - 1
	merge_sort(right, right_size); // middle -- array_size
	int16_t* buffer = new int16_t[array_size];
	int16_t left_i = 0;
	int16_t rigth_i = 0;
	int16_t buffer_i = 0;
	while (left_i < left_size && rigth_i < right_size)
	{
		if (left[left_i] <= right[rigth_i])
		{
			buffer[buffer_i] = left[left_i];
			left_i++;
		}
		else
		{
			buffer[buffer_i] = right[rigth_i];
			rigth_i++;
		}
		buffer_i++;
	}
	while (left_i < left_size)
	{
		buffer[buffer_i] = left[left_i];
		left_i++;
		buffer_i++;
	}
	while (rigth_i < right_size)
	{
		buffer[buffer_i] = right[rigth_i];
		rigth_i++;
		buffer_i++;
	}
	for (int16_t i = 0; i < array_size; i++)
	{
		array[i] = buffer[i];
	}
	delete[] buffer;
	return;
}

void selection_sort(int16_t* array, int16_t array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		int index_min = i;
		for (int j = i + 1; j < array_size; j++)
		{
			if (array[j] < array[index_min])
			{
				std::swap(array[j], array[index_min]);
			}
		}
	}
	return;
}

void count_sort(int16_t* array, int16_t array_size)
{
	int16_t counters[10] = { 0 };
	for (int i = 0; i < array_size; i++)
	{
		counters[array[i]]++;
	}
	int16_t index = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < counters[i]; j++)
		{
			array[index++] = i;
		}
	}
	return;
}

void bubble_sort(int16_t* array, int16_t array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		for (int j = 1; j < array_size; j++)
		{
			if (array[j] < array[j - 1])
			{
				std::swap(array[j], array[j - 1]);
			}
		}
	}
}