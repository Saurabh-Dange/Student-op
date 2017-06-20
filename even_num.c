/*****************************************************************************
 *   PROJECT  :Print the n even number after k where both n and k are        *
 *   user defined                                                            *
 *   FILE_NAME:even_num.c                                                    *
 *   VERSION  :1.0.0                                                         *
 *   DATE     :19/06/2017                                                    *
 *                                                                           *
 *	 Saurabh S Dange ©                                                       *
 *   All rights reserved                                                     *
 *****************************************************************************/

//Header files declaration
#include <stdio.h>

//---------------------------------------------------------------------------//

int main()
{
				// variable declaration //
        int n,k,i;

        printf("enter the value of n \n ");
        scanf("%d",&n);

        printf("enter value of k\n" );
        scanf("%d",&k);


				// to check that number is positive
				if(k<0){

						printf("invalid input");
						return;

				}

				// case 1 if given k is positive
        if(k%2==0)
        {

        		for(i=1;i<=n;i++)
        		{
                	printf("%d\t",k+2 );
                	k+=2;

        		}

        }

				// case 2 if given k is negative
        else
        {
            k+=1;

            for (int i = 1; i<=n; i++)
            {

                        printf("%d\t",k );
                        k+=2;
            }


        }

				//end of the function
        return 0;

}
