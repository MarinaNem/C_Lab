#pragma once
#include <stack>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void QuickSortRecursive(int* arr, int startIndex, int endIndex)
{
    if (endIndex == startIndex) return;
    int pivot = arr[endIndex];
    int storeIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++)
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    swap(&arr[storeIndex], &arr[endIndex]);
    if (storeIndex > startIndex) QuickSortRecursive(arr, startIndex, storeIndex - 1);
    if (storeIndex < endIndex) QuickSortRecursive(arr, storeIndex + 1, endIndex);
}

void QuickSortNotRecursive(int* arr, int startIndex, int endIndex)
{
    stack<int> stack;
    int pivot, leftB, rightB;
    int pivotIndex = startIndex;
    int left = pivotIndex + 1;
    int right = endIndex;
    stack.push(pivotIndex);
    stack.push(right);
    while (stack.size() > 0)
    {
        rightB = stack.top();
        stack.pop();
        leftB = stack.top();
        stack.pop();

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
                swap(arr[left], arr[right]);
        }
        if ((pivotIndex <= right) && (arr[pivotIndex] > arr[right]))
            swap(arr[pivotIndex], arr[right]);
        if (leftB < right)
        {
            stack.push(leftB);
            stack.push(right - 1);
        }
        if (rightB > right)
        {
            stack.push(right + 1);
            stack.push(rightB);
        }
    }
}