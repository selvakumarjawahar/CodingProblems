# Contiguous Sub Array 

## Problem
You are given an array a of N integers. For each index i, you are required to determine the number of 
contiguous subarrays that fulfills the following conditions:
* The value at index i must be the maximum element in the contiguous subarrays, and
* These contiguous subarrays must either start from or end on index i.

## Signature
vector <int> CountSubarrays(vector <int> arr)

### Input
Array a is a non-empty list of unique integers that range between 1 to 1,000,000,000
Size N is between 1 and 1,000,000

### Output
An array where each index i contains an integer denoting the maximum number of contiguous subarrays of a[i]

## Example:
a = [3, 4, 1, 6, 2]  
output = [1, 3, 1, 5, 1]