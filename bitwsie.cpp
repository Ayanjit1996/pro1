// CPP program to set  bits  
// of a given number  
#include <iostream> 
using namespace std; 

void count(int n) 
{ 
    int count=0;
while(n)
{
	if (n & 1) 
		count+=1;
	n>>=1; 
} 
cout<<count;
}
// Driver code 
int main() 
{ 
	int n = 5; 
	count(n); 
	return 0; 
} 
