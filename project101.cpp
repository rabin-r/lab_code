#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

// CRC Start
char exor(char a, char b)
{
    if (a == b)
        return '0';
    else
        return '1';
}
void crc(char data[], char key[])
{
    int datalen = strlen(data);
    int keylen = strlen(key);
    for (int i = 0; i < keylen - 1; i++)
        data[datalen + i] = '0';
    data[datalen + keylen - 1] = '\0';
    int codelen = datalen + keylen - 1;
    char temp[20], rem[20];
    for (int i = 0; i < keylen; i++)
        rem[i] = data[i];
    for (int j = keylen; j <= codelen; j++) {
        for (int i = 0; i < keylen; i++)
            temp[i] = rem[i];
        if (rem[0] == '0') {
            for (int i = 0; i < keylen - 1; i++)
                rem[i] = temp[i + 1];
        } else {
            for (int i = 0; i < keylen - 1; i++)
                rem[i] = exor(temp[i + 1], key[i + 1]);
        }
        if (j != codelen)
            rem[keylen - 1] = data[j];
        else
            rem[keylen - 1] = '\0';
    }
    for (int i = 0; i < keylen - 1; i++)
        data[datalen + i] = rem[i];
    data[codelen] = '\0';
    cout << " CRC=" << rem <<endl<< " Data after crc = " << data;
}
//CRC End

//Hamming Start

int check_parity(int n, int i, int code[])
{
    int p = 0, k;
    for (int j = i; j <= n; j = k + i) {
        for (k = j; k < j + i && k <= n; k++) {
            if (code[k] == 1)
                p++;
        }
    }
    if (p % 2 == 0)
        return 0;
    else
        return 1;
}
void hamming_code(int data[], int num)
{
    int r = 0, m = 0, n, j = 1, c, code[50];
    while ((r + num + 1) > (pow(2, r)))
        r++;
    n = num + r;
    for (int i = 1; i <= n; i++) {
        if (i == pow(2, m) && m <= r) {
            code[i] = 0;
            m++;
        } else {
            code[i] = data[j];
            j++;
        }
    }
    m = 0;
    for (int i = 1; i <= n; i++) {
        if (i == pow(2, m) && m <= r) {
            c = check_parity(n, i, code);
            code[i] = c;
            m++;
        }
    }
    cout << " The hamming code data : ";
    for (int i = n; i > 0; i--)
        cout << code[i];
}
//Hamming End

// Even parity Start
int d_length(char array[])
{
    int count=0;
    for(int i=0; array[i]!=NULL; i++) {
        count++;
    }
    return count;
}
// Even parity End

int main()
{
    while(true)
    {
     int set;

    cout<<endl<<endl<<" Which error detection techniques you want to use :"<<endl;
    cout<<" -----------------------------------------------------------------------"<<endl;
    cout<<" 1. Parity Check"<<endl<<" 2. CRC-Cyclic Redundancy Check"<<endl<<" 3. Hamming Code"<<endl<<" 4. Exit"<<endl;
    cout<<" -----------------------------------------------------------------------"<<endl;
    cin>>set;

    if(set==2) {
        char key[20], data[20];
        cout << " Enter the data:";
        cin >> data;
        cout << " Enter the key:";
        cin >> key;
        crc(data, key);
    }

    else if(set==3) {
        int data[50], num;
        cout << " Enter the size of data :";
        cin >> num;
        cout << " Enter the data:";
        for (int i = num; i > 0; i--)
            cin >> data[i];
        hamming_code(data, num);
    }

    else if(set==1)
    {
    int select;
    char data[100];
    cout<<" -----------------------------------------------------------------------"<<endl;
    cout<<" Which Error detection techniques you want to use : "<<endl<<" 1.Even parity"<<endl<<" 2.Odd parity"<<endl;
    cout<<" -----------------------------------------------------------------------"<<endl;
    cin>>select;
    cout<<" Enter Your data in binary format: ";
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
    cout<<" Original data :";
    cout<<data;
    if(count%2==0 && select==1)
    {
	data[length]='0';
	cout<<endl<<" Data after adding even parity bits : ";
	cout<<data<<endl;
    }
    else if(count%2!=0 && select==1)
    {
    data[length]='1';
    cout<<endl<<" Data after adding even parity bits : ";
	cout<<data<<endl;
    }
    else if(count%2==0 && select==2)
    {
	data[length]='1';
	cout<<endl<<" Data after adding odd parity bits : ";
	cout<<data<<endl;
    }
    else if(count%2!=0 && select==2)
    {
    data[length]='0';
    cout<<endl<<" Data after adding odd parity bits : ";
	cout<<data<<endl;
    }
    }
    else if(set==4)
    {
        return 0;
    }
    }
}
