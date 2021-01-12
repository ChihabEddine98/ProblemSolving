/* A Dynamic programming version for Knapsack problem */
#define _GLIBCXX_USE_CXX11_ABI 0

#include <stdlib.h> 
#include <string> 
#include <iostream> 
#include <algorithm>
#include "utils/utils.h"

using namespace std;





// knapsack(n: #objects , C:capacity) : result [maximum profit we can get from availaible objects]
// naive version in O(2^n)
int knapsack(int n,int C,int* weights,int* profits) 
{ 

	// Base Case 
	if (n == 0 || C == 0) 
		return 0; 

	// If weight of the nth item is more 
	// than Knapsack capacity C, then 
	// this item cannot be included 
	// in the solution
	if (weights[n - 1] > C) 
		return knapsack(n-1,C,weights,profits); 

	// Return the maximum of two cases: 
	// (1) not included   
	// (2) nth item included
	else
        return max(knapsack(n-1,C,weights,profits)
                ,profits[n-1]+knapsack(n-1,C-weights[n-1],weights,profits));
} 

int main(int argc,char* argv[]) 
{ 
    
    // weights , profits vector will be given in cmd array in all the code
    int* weights=user_in2array("Weights",5); 
	cout << "--------------------" << "\n" ; 
    int* profits=user_in2array("Profits",5); 
	int C = 15; 
	int n = 5; 
	cout << knapsack(n,C,weights,profits); 
	return 0; 
} 

