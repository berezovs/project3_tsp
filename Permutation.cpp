/***********************************************************
  Programmer: John Coffey
  Program: an iterative permutation generator
  Purpose: 
    - Produce all n! permutations of length ints
    -  Produce a set of permutations one at a time
 ***********************************************************/
#include <iostream>
#include "Permutation.hpp"

Permutation::Permutation(int length)
      {
        n = length;
        initS(length);
      }
		
      void Permutation::initS(int length)
      {
        int i;
        for(i = 0; i < length; i++)
          s[i] = i+1;
        s[i] = 0;
        n = length;
      }
      
      
     
       void Permutation::perm1() 
      {
         int m, k, p , q, i;

			//for(i = 1; i <= howmany; i++)
			{
			  m = n - 1;
			  while(s[m]>s[m+1])
           {       
			    m = m - 1;
		     }
           k = n-1;
			  while(s[m] > s[k])
			    k = k - 1;
	        swap(m,k);
			  p = m + 1;
		  	  q = n-1;
			  while( p < q)
		  	  {
			    swap(p,q);
			    p++;
			    q--;
	        }
	      }
	   } 
   	
       void Permutation::printS()
      {
         for(int i = 0; i < n; i++)
            std::cout << s[i] << " ";
         std::cout << std::endl;
      }
   
       void Permutation::swap(int i, int j) 
      { 
         int c = s[i];
         s[i] = s[j];
         s[j] = c; 
      } 
   
   int * Permutation::getS()
   {
     return s;
   }
   
   int Permutation::fact(int n)
   {
     int tot = 1;
     for(int i = 2; i <=n; i++)
        tot*=i;
     return tot;
   }
