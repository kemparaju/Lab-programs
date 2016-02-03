#include<stdio.h>
#include<stdlib.h>

int a,b,c;

void check_triangle()
{
  if(a==b && b==c && a==c)
     printf("tringle is EQUILATERAL\n");
   else if(a==b || a==c || b==c)
     printf("triagle is ISOCELES\n");
   else if(a != b && b!=c && c!=a )
        printf("triangle is SCALENE\n");
   else printf("Not A Triangle\n");
}

int main() 
{
  printf("Enter the sides of triangle\n");
   scanf("%d%d%d" , &a , &b , &c);
  
  if( (a>200 || a<1 ) || (b<1 || b>200) || (c<1 || c>200) )
    {
      printf("Values Are Not In A Permissible Range\n");
       exit(0);
     }
   if(a>b+c || b>a+c || c>a+b )
     {
      printf("Not a triangle\n");
       exit(0);
     }
   check_triangle();
  return 0;
}





















