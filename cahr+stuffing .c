#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j=0,n;
    char d[100],l[]="DLEETX",sd[100],ds[100];
    printf("Enter the characters \n");

        scanf("%s",d);

        sd[0]='D',sd[1]='L',sd[2]='E',sd[3]='S',sd[4]='T',sd[5]='X';
    j=6;
    while(d[i]!='\0')
    {
        if(d[i]=='D' && d[i+1]=='L' && d[i+2]=='E')
        {
            sd[j]='D',sd[j+1]='L',sd[j+2]='E',sd[j+3]='D',sd[j+4]='L',sd[j+5]='E';
            j+=6;
            i+=3;
        }
        else{
            sd[j++]=d[i++];
        }
        sd[j]='\0';
        strcpy(ds,sd);
        strcat(sd,l);
       } 
        printf("After Stuffing: ");
        printf("%s",sd);
  
    while(ds[i]!='\0')
    {
        if(ds[i]=='D' && ds[i+1]=='L' && ds[i+2]=='E' && ds[i+3]=='D' && ds[i+4]=='L' && ds[i+5]=='E' )
        {
            d[j]='D',d[j+1]='L',d[j+2]='E';
            j+=6;
            i+=3;
        }
        else{
            d[j++]=ds[i++];
        }
      
       } 
        printf("/n After de-Stuffing: ");
        printf("%s",d);
 

}
