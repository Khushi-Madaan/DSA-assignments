/*Write a program to find the sum of every row and every column 
in a two-dimensionl array.*/
#include<iostream>
using namespace std;
class matrix
{
    int a[10][10],i,j,m,n;
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
               cout<<"Enter array elements: ";
               cin>>a[i][j]; 
            }
        }
    }
    void display()
    {
        cout<<"\nArray is:\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void sum()
    {
        getdata();
        display();
        for(i=0;i<m;i++)
        {
            int sr=0;
            int sl=0;
            for(j=0;j<n;j++)
            {
                sr=sr+a[i][j];
                sl=sl+a[j][i];
            }
            cout<<"\nSum of "<<i<<" row is: "<<sr;
            cout<<"\nSum of "<<i<<" column is: "<<sl;
        }
    }
};
int main()
{
    matrix obj;
    obj.sum();
    return 0;
}