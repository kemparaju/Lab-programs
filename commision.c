#include<stdio.h>
#include<stdlib.h>

int ls[70] , ss[80] , bs[90] , fault[100]={0};

int check_input()
{
  int i=0;

  printf("Enter -1 for locks to Terminate\n");
 
  printf("LOCKS\tSTOCKS\tBARRELS\n");

  while(1)
  { 
    scanf("%d" ,&ls[i]);
     if(ls[i] == -1) break;
    scanf("%d%d",&ss[i] ,&bs[i]);

    
    if( (ls[i] <1 || ls[i] >70) || (ss[i]<1 || ss[i] > 80 ) || (bs[i]<1 || bs[i] > 90) )
     fault[i] = 1;
    i++;
  }
  return i;
}

void calculate_comm(float *sales , float* comm , int count)
{
   int i;
    float temp;

    for(i=0;i<count;i++)
    {
       if(fault[i])
        {
           sales[i] = comm[i]=0;
           continue;
         }
      sales[i] = ls[i]*45 + ss[i]*30 + bs[i]*25;
       temp = sales[i];

      if(temp>1000)
       {
          comm[i] = .10*1000;
           temp = temp-1000;
             if(temp > 800)
              {
                comm[i] += .15*800;
                temp = temp - 800;
                comm[i] += .20*temp;
              }
             else comm[i] +=.15*temp;
        }
      else comm[i] = temp*.10;
     
    }
       

    
}
int main()
{
  int count  , i;
  float comm[90], sales[90];

  count=check_input();

  if(!count) 
  {
    printf("Commision Cannot be calculated\n");
     exit(0);
   }

  calculate_comm(sales , comm , count);

  printf("---------------------------------------------------------------------\n");
   printf("\t\tMONTHLY SALES REPORT\n");
   printf("---------------------------------------------------------------------\n\n");
  printf("LOCKS\tSTOCKS\tBARRELS\tSALES\tCOMM\n");
   for(i=0;i<count;i++)
      printf("%d\t%d\t%d\t$%.1f\t$%.3f\n" , ls[i] , ss[i] , bs[i] ,   sales[i] , comm[i]);
   
   return 0;
}













     


   



