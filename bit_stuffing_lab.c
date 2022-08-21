
// 01111110 11011111 01111110

// 01111110 110111011 01111110


#include<stdio.h>
#include<string.h>
int main()
{
    int a[30],b[30],i,j,k,count,n,flag="01111110";
    printf("Enter frame size : ");
    scanf("%d",&n);
    printf("Enter the frame in : ");
    for(i=0; i<n; i++){
         scanf("%d",&a[i]);}
    i=0; count=1; j=0;



    while(i<n)
    {
        if(a[i]==1)
        {
            b[j]=a[i];
            for(k=i+1; a[k]==1 && k<n && count<5; k++)
            {
                j++;
                b[j]=a[k];
                count++;
                if(count==5)
                {
                    j++;
                    b[j]=0;
                }
                i=k;
            }
        }
        else
        {
            b[j]=a[i];
        }
        i++;
        j++;
    }

    printf("After Stuffing :");
    printf("%s",flag);
        for(i=0; i<j; i++)
     printf("%d",b[i]);
      printf("%s",flag);





 // de-stuffing

       while(i<n)
    {
        if(b[i]==1)
        {
            a[j]=b[i];
            for(k=i+1; a[k]==1 && k<n && count<5; k++)
            {
                j++;
                a[j]=b[k];
                count++;
                if(count==5)
                {
                    k++;
                }
                i=k;
            }
        }
        else
        {
            a[j]=b[i];
        }
        i++;
        j++;
    }
    printf(" \n \nAfter Bit De-Stuffing :");
    for(i=0; i<j-1; i++)
        printf("%d",a[i]);
}
