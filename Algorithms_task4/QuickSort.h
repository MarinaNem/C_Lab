#pragma once
#include <stack>

void QuickSortRecursive(int* arr, int startIndex, int endIndex)
{
    if (endIndex == startIndex) return;
    int pivot = arr[endIndex];
    int storeIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++)
        if (arr[i] <= pivot)
        {
            int t = arr[i];
            arr[i] = arr[storeIndex];
            arr[storeIndex] = t;
            storeIndex++;
        }
    int temp = arr[storeIndex];
    arr[storeIndex] = arr[endIndex];
    arr[endIndex] = temp;
    if (storeIndex > startIndex) QuickSortRecursive(arr, startIndex, storeIndex - 1);
    if (storeIndex < endIndex) QuickSortRecursive(arr, storeIndex + 1, endIndex);
}

void QuickSortNotRecursive(int* arr, int startIndex, int endIndex)
{
    int storage[2];
    int* a = storage;
    int pivot, leftB, rightB;
    int pivotIndex = startIndex;
    int left = pivotIndex + 1;
    int right = endIndex;

    *a = pivotIndex;
    a++;
    *a = right;
    while (a == &storage[0])
    {
        rightB = *a;
        a--;
        leftB = *a;
        a--;

        left = leftB + 1;
        pivotIndex = leftB;
        right = rightB;
        pivot = arr[pivotIndex];
        if (left > right) continue;
        while (left < right)
        {
            while ((left <= right) && (arr[left] <= pivot))
                left++;
            while ((left <= right) && (arr[right] >= pivot))
                right--;
            if (right >= left)
            {
                int t = arr[left];
                arr[left] = arr[right];
                arr[right] = t;
            }
        }
        if ((pivotIndex <= right) && (arr[pivotIndex] > arr[right]))
        {
            int temp = arr[pivotIndex];
            arr[pivotIndex] = arr[right];
            arr[right] = temp;
        }
        if (leftB < right)
        {
            *a = leftB;
            a++;
            *a = right - 1;
        }
        if (rightB > right)
        {
            *a = right + 1;
            a++;
            *a = rightB;
        }
    }
}
