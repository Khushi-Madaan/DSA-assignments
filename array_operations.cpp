/*Display a Menu driven program to demonstrate the followin operations of Arrays
-----MENU-----
1.CREATE
2. DISPLAY
3. INSERT
4. DELETE
5.LINEAR SEARCH
6. EXIT*/
#include<iostream>
using namespace std;
class array_operations
{
        int a[100],size;
        public:
        void createArray()
        {
           cout<<"Enter the number of elements to create: "; 
           cin>>size; 
		   if(size<0 || size>100)
		   {
			cout<<"Invalid size! Reset the size";
			size=0;
		   }  
		   else
		   {
			for(int i=0;i<size;i++)
			{
				cout<<"\nEnter array element: ";
				cin>>a[i];
			}
		   }
        }
        void displayArray()
        {
			if(size==0)
			{
				cout<<"\nArray is empty";
			}
			else
			{
				cout<<"\nArray elements:\n";
				for(int i=0;i<size;i++)
				{
					if(i==(size-1))
					{
						cout<<a[i];
					}
					else
					{
						cout<<a[i]<<",";
					}
				}
			}
        }
        void insertElement()
        {

			int e,k;
			cout<<"Enter the element to be inserted: ";
			cin>>e;
			cout<<"Enter the index to insert new element (index start from zero): ";
			cin>>k;
			if(k<size)
			{
				int temp=a[k];
				int s=temp;
				a[k]=e;
				for(int j=k+1;j<size;j++)
				{
					temp=a[j];
					a[j]=s;
					s=temp;
				}
				a[size]=s;
				size++;
				cout<<a[size-1];
				cout<<"\nArray after insertion:\n";
				displayArray();
			}
			else
			{
				cout<<"SORRY! Index is greater than array size";
			}	
    }
        void deleteElement()
        {
			int d,m=0;
			cout<<"\nEnter the element to be deleted: ";
			cin>>d;
			for(int i=0;i<size;i++)
			{
				if(d==a[i])
				{
					m=1;
					for(int k=i;k<size-1;k++)
					{
						a[k]=a[k+1];
					}
					size--;
					cout<<"\nArray after deletion:\n";
					displayArray();
				}
			}
			if(m==0)
			{
				cout<<"\nSorry! element is not in the array for deletion";
			}
        }
        void linearSearch()
        {
			int c=0,e;
			cout<<"\nEnter the element to be searched: ";
			cin>>e;
			for(int i=0;i<size;i++)
			{
				if(e==a[i])
				{
					c=1;
					break;
				}
			}
			if(c==1)
			{
				cout<<"\nElement is found";
			}
			else
			{
				cout<<"Sorry! Element is not found";
			}
        }
};
int main()
{
	array_operations obj;
	int choice;
	for(int i=1;i<7;i++)
	{
		cout<<"\n----MENU----";
		cout<<"\n1. CREATE";
		cout<<"\n2. DISPLAY";
		cout<<"\n3. INSERT";
		cout<<"\n4. DELETE";
		cout<<"\n5. LINEAR SERACH";
		cout<<"\n1. EXIT\n";
		cout<<"Enter your choice(1-6): ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			obj.createArray();
			break;
			case 2:
			obj.displayArray();
			break;
			case 3:
			obj.insertElement();
			break;
			case 4:
			obj.deleteElement();
			break;
			case 5:
			obj.linearSearch();
			break;
			case 6:
			cout<<"\nExiting the program, Goodbye\n";
			break;
		}
	}
    return 0;
}