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

//function declaration
int get();
void print(int,int);
//---------------------------------------------------------------------------//

/******************************************************************************
 *   Function Name:get                                                        *
 *   Parameters passed:None                                                   *
 *   Return Type: int                                                         *
 *   Description:used for validating the input and storing in the variable    *
 ******************************************************************************/

int get()
{
      int n;
      if(scanf("%d",&n)!=1){
        printf("Invalid input");
      }
      return n;
}
//---------------------------------------------------------------------------//

/******************************************************************************
 *   Function Name:print                                                      *
 *   Parameters passed:Two integers                                           *
 *   Return Type: void                                                        *
 *   Description:used for printing the numbers according to the user          *
 *   requirements                                                             *
 ******************************************************************************/
void print(int k,int n)
{

  for(i=1;i<=n;i++)
        {
              printf("%d\t",k+2 );
              k+=2;

        }
}
//---------------------------------------------------------------------------//

//Main function

int main()
{     //variable declaration
      int n,k,i;

      printf("enter the value of n \n ");
      n=get();

      printf("enter value of k\n" );

      k=get();

      if (k<0) {

        printf("invalid input");
        return;

      }
      if (k%2==0) {

          print(k,n);
      }

      else
          print(k+1,n);


      return 0;


}
