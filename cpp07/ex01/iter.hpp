#pragma once
#include <iostream>
#include <string.h>

template <typename T>
void	iter(T *arr, size_t size, void (*ft)(T& to_print))
{
	for (size_t i = 0; i < size; i++)
		ft(arr[i]);
}