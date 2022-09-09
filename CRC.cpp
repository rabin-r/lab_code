//in program, d = length of data, k = length of divisor, t =length of total bits including divisor,rem = reminder bit


#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
char xor(char a, char b)
{
    if (a == b)
        return '0';
    else
        return '1';
}
void crc(char data[], char key[], int d, int k)
{
	// put 0 in crc bit position and find new data length=t
    for (int i = 0; i < k - 1; i++)
        data[d + i] = '0';
    data[d + k - 1] = '\0';
    int t = d + k - 1;
	
	//finding the reminder of data
    char temp[20], rem[20];
    for (int i = 0; i < k; i++)
        rem[i] = data[i];

	//xor and others functionality between key and reminder
    for (int j = k; j <= t; j++) {
        for (int i = 0; i < k; i++)
            temp[i] = rem[i];
        if (rem[0] == '0') {
            for (int i = 0; i < k - 1; i++)
                rem[i] = temp[i + 1];
        } else {
            for (int i = 0; i < k - 1; i++)
                rem[i] = xor(temp[i + 1], key[i + 1]);
        }

	//
        if (j != t)
            rem[k - 1] = data[j];
        else
            rem[k - 1] = '\0';
    }

	//coping and printing output
    for (int i = 0; i < k - 1; i++)
        data[d + i] = rem[i];
    data[t] = '\0';
    cout << "CRC=" << rem << "\nDataword=" << data;
}
int main()
{
    char key[20], data[30];
int i,k,d;
cout<<"enter the length of data";
cin>>d;
for(int i=0;i<d;i++)
{
	cin>>data[i];
}
cout<<"enter the length of key";
cin>>k;
for(int i=0;i<k;i++)
{
	cin>>key[i];
}
    crc(data, key,d,k);
    return 0;
}
