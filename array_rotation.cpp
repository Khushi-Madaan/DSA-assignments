/*Design the logic of a program to rotate a 1-D array by k
positions*/
#include<iostream>
using namespace std;
class rotation
{
    int a[5],i,j,n=5;
    public:
    void getdata()
    {
        for(i=0;i<n;i++)
        {
            cout<<"\nEnter array element: ";
            cin>>a[i];
        }
    }
    void display()
    {
        for(i=0;i<n;i++)
        {
            if(i==(n-1))
            {
                cout<<a[i];
            }
            else
            {
                cout<<a[i]<<",";
            }
        }
    }
    void right_rt()
    {
        getdata();
        cout<<"\nArray is:\n";
        display();
        int k;
        cout<<"\nEnter the position to rotate an array: ";
        cin>>k;
        int temp=a[0],s=temp,j;
        for(j=0;j<k;j++)
        {
            for(i=0;i<n-1;i++)
            {
                temp=a[i+1];
                a[i+1]=s;
                s=temp;
            }
            a[0]=s;
        }
        cout<<"Array after right rotation from ",k,"th position is:";
        display();

    }
    void left_rt()
    {
        getdata();
        cout<<"\nArray is:\n";
        display();
        int k;
        cout<<"\nEnter the position to rotate an array: ";
        cin>>k;
        for(j=0;j<k;j++)
        {
            int temp=a[0];
            for(i=0;i<n-1;i++)
            {
                a[i]=a[i+1];
            }
            a[i]=temp;
        }
        cout<<"Array after leftt rotation from ",k,"th position is:";
        display();

    }
};
int main()
{
    rotation obj,obj1;
    obj.left_rt();
    obj1.right_rt();
    return 0;
}