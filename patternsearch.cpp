#include<iostream>
#include<string.h>
using namespace std;

void search(char *text, char *pt)
{
    int n=strlen(text);
    int m=strlen(pt);
    for (int i = 0; i <=n-m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if(text[i+j]!=pt[j])
                break;
        if(j==m)
        cout<<"The pattern is found at "<<i<<endl;
    }
    
}

int main()
{
    char text[]="AAAAAAAAAAAAAAAAAAAAB";
    char pt[]="AAAAAB";
    search(text,pt);
    return 0;
}