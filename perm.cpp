// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <sstream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main () {

  string uSet;
  cout << "Enter some set of integers: \n";
  getline(cin, uSet);
  cout << "Your set: " << uSet << "\n\n";

  int oPerm[uSet.length()-1];
  int permNum = factorial(uSet.length());
  int setLength = uSet.length();
  string perms[permNum-1 ];


  //std::sort (myints,myints+3);

  cout << "The " << permNum << " possible permutations with " << setLength << " elements:\n";
  
  for (int i = 0; i < permNum-1; i++){
  
  		// take that original set and get the "next_permutation" so we can
  		// add it to an array of all the possible permutations (from which
  		// we can randomly select one later)
  		
  		std::next_permutation(uSet.begin(),uSet.end());
  		
  		cout << '\t' << uSet << '\n';
  		
  		for (int j = 0; j < setLength-1; j++){
  			
  			perms[i] = uSet;
  		}
  	}
 	
 	cout << "Random Permutation: ";
 	
 	// it took me some time to figure out that i need to seed for the random num generation
 	srand(time(NULL));

 	//randomly select one of the possible permutations
	int rPerm = rand() % permNum-1;
	
  	cout << perms[rPerm] << '\n';
  

  return 0;
}
