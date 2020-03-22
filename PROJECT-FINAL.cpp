/* Dynamic Programming implementation of LCS problem */
#include<iostream> 
#include<cstring> 
#include<string.h>
#include<cstdlib>
#include<fstream> 
using namespace std; 

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( char *X, char *Y, int m, int n ) 
{ 
int L[m+1][n+1]; 

/* Following steps build L[m+1][n+1] in bottom up fashion. Note 
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (int i=0; i<=m; i++) 
{ 
	for (int j=0; j<=n; j++) 
	{ 
	if (i == 0 || j == 0) 
		L[i][j] = 0; 
	else if (X[i-1] == Y[j-1]) 
		L[i][j] = L[i-1][j-1] + 1; 
	else
		L[i][j] = max(L[i-1][j], L[i][j-1]); 
	} 
} 

// Following code is used to print LCS 
int index = L[m][n]; 

// Create a character array to store the lcs string 
char l[index+1]; 
l[index] = '\0'; // Set the terminating character 

// Start from the right-most-bottom-most corner and 
// one by one store characters in lcs[] 
int i = m, j = n; 
while (i > 0 && j > 0) 
{ 
	// If current character in X[] and Y are same, then 
	// current character is part of LCS 
	if (X[i-1] == Y[j-1]) 
	{ 
		l[index-1] = X[i-1]; // Put current character in result 
		i--; j--; index--;	 // reduce values of i, j and index 
	} 

	// If not same, then find the larger of two and 
	// go in the direction of larger value 
	else if (L[i-1][j] > L[i][j-1]) 
		i--; 
	else
		j--; 
} 

// Print the lcs 
cout << "LCS  is " << l<<" and the length is "<<strlen(l);
 
} 

/* Driver program to test above function */
int main() 
{ 
cout<<"Enter the length 1st DNA sequence--> ";
int p,q; 
cin>>p;
cout<<"Enter the length 2nd DNA sequence--> ";
cin>>q;
char X[p+1];
char Y[q+1] ;

string line,m;
  ifstream myfile ("file.txt"); //these are the files that declared in the same location where it is saved
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    { 
    m=line;
    strcpy(X, m.c_str());
    }
    
    myfile.close();
    
    
  }

  else cout << "Unable to open file"; 


string line1,n;
  ifstream myfile1 ("file1.txt");
  if (myfile1.is_open())
  {
    while ( getline (myfile1,line1) )
    { 
    n=line1;
    strcpy(Y, n.c_str());
    }
    
    myfile1.close();
    
    
  }

  else cout << "Unable to open file"; 


 
int j = strlen(X); 
int k = strlen(Y); 
lcs(X, Y, j, k); 
return 0; 
} 

