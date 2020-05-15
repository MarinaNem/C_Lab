#pragma once

int Search(int number, int arr[], int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == number) return i;
    return -1;
}

int BSearchRecursive(int value, int arr[], int left, int right)
{
    int middle = (left + right) / 2;
    if (value == arr[middle]) return middle;
    if (left == right) return -1;
    if (arr[middle] < value)
        return BSearchRecursive(value, arr, middle+1 , right);
    return BSearchRecursive(value, arr, left, middle);
}

int BSearchNotRecursive(int value, int arr[], int left, int right)
{
    while (left < right)
    {
        int middle = (right + left) / 2;
        if (value <= arr[middle])
            right = middle;
        else left = middle + 1;
    }
    if (arr[right] == value)
        return right;
    return -1;
}