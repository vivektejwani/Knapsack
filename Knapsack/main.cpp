//
//  main.cpp
//  Knapsack
//
//  Created by Vivek Tejwani on 20/02/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
void knapsack(int n, int W);
int B[100][100];
int K[100][100];
int input[100][2];
int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"Please provide the number of elements\n";
    int n;
    cin>>n;
    cout<<"Please provide the weight that the knapsack can withstand\n";
    int W;
    cin>>W;
    cout<<"Please enter the weight of item followed by its value\nWeight:\tValue:\n";
    for(int i=0;i<n;i++)
    {
        cin>>input[i][0];
        cin>>input[i][1];
        cout<<"\n";
    }
    knapsack(n,W);
    
    int i=n;
    cout<<"Item Numbers : ";
    while(i>0)
    {
        int j=W;
        while(j>0)
        {
            if(i<=0)
                break;
            else
            {   
                if(K[i][j]==1)
                {
                    cout<<" "<<i;
                    j=j-input[i-1][0];
                }
                i--;
            }
        }
    }
    return 0;
}
void knapsack(int n,int W)
{
    for(int i=0;i<=n;i++)
    {
        B[i][0]=0;
        K[i][0]=0;
    }
    for(int i=0;i<=W;i++)
    {
        B[0][i]=0;
        K[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(input[i-1][0]<=j)
            {
                if(B[i-1][j]<(input[i-1][1]+B[i-1][j-input[i-1][0]]))
                {
                    B[i][j]=input[i-1][1]+B[i-1][j-input[i-1][0]];
                    K[i][j]=1;
                }
                else
                    B[i][j]=B[i-1][j];
            }
            else
                B[i][j]=B[i-1][j];
        }
    }
}

