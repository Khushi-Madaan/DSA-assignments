/*Design the logic to Find a missing number in a Sorted Array.
Give an array of n-1 distinct integers in the range of 1 to n,
find the missing numberin it in a sorted array.
a) Linear time
b) Using binary search
*/
#include<iostream>
using namespace std;
class missing
{
    int a[5]={1,2,4,5};
    int n=5;
    public:
    void linear()
    {
        int i,c=0;
        cout<<"\nn(5) sized Sorted Array with 4(n-1) elemensts is:\n";
        for(i=0;i<n-1;i++)
        {
            cout<<a[i]<<" ";
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]!=i+1)
            {
                cout<<"\n"<<i+1<<" is missing number";
                c=1;
                break;
            }
        }
        if(c==0)
        {
            cout<<"\n"<<n<<" is missing number"; 
        }
    }
    void binary()
    { 
        int lb=0,ub=n-2;
        int miss_num=n;
        while(lb<=ub)
        {
            int mid=lb+(ub-lb)/2;
            if(a[mid]==mid+1)
            {
                lb=mid+1;
            }
            else
            {
                miss_num=mid+1;
                ub=mid-1;
            }
        }
        cout<<"\n"<<miss_num<<" is missing number";
    }
};
int main()
{
   missing obj;
   cout<<"\nMissing number using linaer search\n";
   obj.linear();
   cout<<"\n\nMissing number using binary search";
   obj.binary();
    return 0; 
}   

    
       