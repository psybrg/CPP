#include<stdio.h>
int main()
{
int i,j;

for(i=9;i>0;i=i-2)
{
for(j=i;j>0;j=j-2)
printf("%d ",j);
printf("\n");
}
return 0;
}
