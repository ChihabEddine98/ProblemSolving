#include "utils.h"



int* user_in2array(string name,int n)
{
    static int data[100]; 
    int x;
    //fill data array
    for(int i = 0; i < n; i++)
    { 
        cout << name+"["+to_string(i)+"]: ";
        cin >> x;
        data[i] = x;
    }
    return data;
}


