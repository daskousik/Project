#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void main()
{
	int n=7;
	int ini_state[7];
	int inter_state[7];
	int next_state[7];
	int RMT[8];
	int i, j, k, l, m, x, y;
	int rem, decimal, num;
	int number;
	int loopcount=0;
	int rule=184;


	m=7;
	while(rule>0)
   	 {
		 	rem=rule%2;
			RMT[m]=rem;
			m--;
			rule=rule/2;
   	 }
	
	 for(j=0;j<8;j++)
	 {
		 printf("%d\t",RMT[j]);
	 }

		printf("\n");

	x= pow(2,n);

	printf("x=%d\n",x);	
	
	for(number=0;number<x;number++)
	{
		l=0;
		num=number; 
		for(i=0;i<n;i++)
		{
			ini_state[i]=0;
		}

		printf("%d:\t",number);

		while(num>0)
		{
			rem=num%2;
			ini_state[l]=rem;
			l++;
			num=num/2;
		}
		
		//printf("Initial state:");
		for(i=0;i<n;i++)
		{
			printf("%d\t",ini_state[i]);
		}
			
		printf("|\t");		

		for(i=0;i<n;i++)
		{
			next_state[i]=ini_state[i];
		}

		for(loopcount=0;loopcount<1;loopcount++)
		{
			for(i=0;i<n;i++)
			{
				inter_state[i]=next_state[i];
			}

//			printf("loopcount=%d\n",loopcount);


			for(j=1;j<=n;j++)
			{

				decimal=0;
				if(j==1)
      			{
         				decimal=(inter_state[n-1]*pow(2,2))+(inter_state[0]*pow(2,1))+(inter_state[1]*pow(2,0));   
     			}    
    			else if(j==n)
        		{
          	 			decimal=(inter_state[j-2]*pow(2,2))+(inter_state[j-1]*pow(2,1))+(inter_state[0]*pow(2,0));
       			}	
       		 	else 
        				decimal=(inter_state[j-2]*pow(2,2))+(inter_state[j-1]*pow(2,1))+(inter_state[j]*pow(2,0)); 

				y=(7-decimal);

        		next_state[j-1]=RMT[y];

			}
		}

		//printf("Next state:");
		
		for(i=0;i<n;i++)
		{
			printf("%d\t",next_state[i]);
		}
		printf("      |   %d",127-number);
		printf("\n\n");
			
			
	}





}
