#include<stdio.h>
#include<stdlib.h>

#define PRINT_ERROR perror("Invalid Date\n");

enum month
{
   jan=1 , feb , mar , apr , may ,jun,
   jul , aug , sep , oct , nov , dec 
};
int dd , yy , mm;

void odd()
{
  if(dd<1 || dd> 31)
     { 
     PRINT_ERROR
     exit(0);
   }
}

void even()
{
   if(dd<1 || dd>30 )
    {
        PRINT_ERROR
        exit(0);
     }
}

void calculate_date(int x)
{
   int t1 , t2 , t3;
  t1 = (dd+1) % x;

   if(t1==0)
    {
      dd=1;
      t2 = (mm+1)%13;
      if(t2==0)
       {
         mm = 1;
         t3 = (yy+1) %2017;
          if(t3 == 0)
           {
              printf("End of the year is reached\n");
             exit(0);
            }
           else
             yy = yy+1;
       }
     else 
        mm = mm+1;
     }
    else dd = dd+1;

} 

     
int main()
{
  

  printf("Enter Date(DD-MM-YY) :");
  scanf("%d%d%d",&dd, &mm,&yy);

  int r=0 , leap=0;

  r = yy%100;

  if(yy < 1704 || yy > 2016)
  {
    PRINT_ERROR
    exit(0);
  }

  if( r==0 && (yy%400 != 00) )
    leap = 0;
 
   else  if( yy%4 == 0) leap=1;

  switch(mm)
  {    
       case mar :
       case may :
       case jul :
       case aug :
       case oct :
       case dec :
       case jan :  odd();
                  calculate_date(32);
                   break;
       case jun:
       case sep:
       case nov:
       case apr: even();
                calculate_date(31);
                break;
 
        case feb : if(leap)
                 {
                   if(dd<1 || dd>29)
                    {
                      PRINT_ERROR
                      exit(0);
                     } calculate_date(30);
                  }
                  else
                   {
                     if(dd<1 || dd>28)
                    {
                      PRINT_ERROR
                      exit(0);
                     } calculate_date(29);
                   }
                  
                   break;
       

          default : PRINT_ERROR
                    exit(0);
       }

   printf("Next Date:%d-%d-%d\n",dd,mm,yy);
    return 0;
 }
                       
             
               






          
     
  
