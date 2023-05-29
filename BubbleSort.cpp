#include<iostream>
#include<stdlib.h>
#include <random>
#include <ctime>
#include<omp.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);


void bubble(int *a, int n)
{
    for(  int i = 0;  i < n;  i++ )
     {  	 
   	 int first = i % 2; 	 

   	 #pragma omp parallel for shared(a,first)
   	 for (int j = first;  j < n-1;  j += 2)
   	   {  	 
   		 if(  a[ j ]  >  a[ j+1 ]  )
   		  {  	 
     			 swap(  a[ j ],  a[ j+1 ]  );
   		  }  	 
   		   }  	 
     }
}


void swap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

int main()
{
    const int size = 1000; // Size of the array
    int numbers[size];    // Array to store the random numbers

    // Seed the random number generator
    srand(time(nullptr));

    // Generate random numbers and store them in the array
    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand();
    }

    // Print the generated numbers
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;


    for(int i=0;i<size;i++)
    {
   	 cout<<numbers[i]<<endl;
    }

    cout << "======";

    
    bubble(numbers,size);
    
    cout<<"\n sorted array is=>";
    for(int i=0;i<size;i++)
    {
   	 cout<<numbers[i]<<endl;
    }


return 0;
}
