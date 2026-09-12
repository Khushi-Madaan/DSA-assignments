/*Implement the logic to
a. Reverse the elements of an array
b. Find the matrix multiplication
c. Find the Transpose of a Matrix */
#include<iostream>
using namespace std;
class matrix
{
    int a[10][10],b[3][2],c[10][10],d[10][10];
    int i,j,m,n,m1,n1;
    public:
    void getdata()
    {
        cout<<"\nEnter no. of  rows in an array: ";
        cin>>m;
        cout<<"\nEnter no. of  colums in an array: ";
        cin>>n;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<"\nEnter array element: ";
                cin>>a[i][j];
            }
        }
    }
    void display()
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<a[i][j]<<"  ";
                
            }
            cout<<endl;
        }
    }
    void reverse()
    {
        getdata();
        cout<<"\nArray is:\n";
        display();
        int temp,k;
        for(i=0;i<m;i++)
        {
            k=n-1;
            for(j=0;j<n/2;j++)
            {
                temp=a[i][j];
                a[i][j]=a[i][k];
                a[i][k]=temp;
                k--;
            }
        }
        cout<<"Reverse of an Array is:\n";
        display();
    }

    void input()
    {
        cout<<"\nEnter no. of  rows in an array: ";
        cin>>m1;
        cout<<"\nEnter no. of  colums in an array: ";
        cin>>n1;
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
            {
                cout<<"\nEnter array element: ";
                cin>>b[i][j];
            }
        }
    }
    void show()
    {
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
            {
                cout<<b[i][j]<<"  ";
                
            }
            cout<<endl;
        }
    }
    void multiply()
    {
        getdata();
        cout<<"\nArray is:\n";
        display();
        input();
        cout<<"\n2nd Array is:\n";
        show();
        if(n==m1)
        {
            for(i=0;i<m;i++)
            {
                for(j=0;j<n1;j++)
                {
                    c[i][j]=0;
                    for(int k=0;k<n;k++)
                    {
                        c[i][j]=c[i][j]+a[i][k]*b[k][j];
                    }
                }
            }
            cout<<"Multiplication of two Matrices is:\n";
            for(i=0;i<m;i++)
            {
                for(j=0;j<n1;j++)
                {
                    cout<<c[i][j]<<"  ";
                    
                }
                cout<<endl; 
            }
        }
        else
        {
            cout<<"Sorry! Multiplication isn't possible because no. of cols of Ist Array and no. of rows aren't equal";
        }   
    }
    void transpose()
    {
        input();
        cout<<"\nArray is:\n";
        show();
        for(i=0;i<n1;i++)
        {
            for(j=0;j<m1;j++)
            {
                d[i][j]=b[j][i];
            }
        }
        cout<<"Transpose of Matrix is:\n";
        for(i=0;i<n1;i++)
        {
            for(j=0;j<m1;j++)
            {
                cout<<d[i][j]<<"  ";
                
            }
            cout<<endl;
        }
    }
};
int main()
{
    matrix obj;
    cout<<"\nMultiply operation";
    obj.multiply();
     cout<<"\nTranspose operation";
    obj.transpose();
     cout<<"\nReverse operation";
    obj.reverse();
    return 0;
}