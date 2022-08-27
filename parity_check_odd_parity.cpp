#include <iostream>
using namespace std;

int d_length(char array[])
{
    int count=0;
    for(int i=0;array[i]!=NULL;i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char data[100];
    cout<<"Enter Your data in binary format: ";
    cin>>data;
    
    int length=d_length(data);
    int count=0;
    for(int i=0;i<length;i++)
    {
        if(data[i]=='1')
        {
            count++;
        }
    }
    cout<<"ORIGINAL DATA :";
    cout<<data<<endl;
    if(count%2==0)
    {
	data[length]='1';
	cout<<"DATA AFTER ADDING PARITY BITS :";
	cout<<data<<endl;
    }
    else
    {
    data[length]='0';
    cout<<"DATA AFTER ADDING PARITY BITS :";
	cout<<data<<endl;
    }
}
