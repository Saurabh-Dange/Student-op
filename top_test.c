/*****************************************************************************
 *   PROJECT  :Print N number of toppers where N is user defined             *
 *   FILE_NAME:top_scorer.c                                                  *
 *   VERSION  :1.0.0                                                         *
 *   DATE     :19/06/2017                                                    *
 *                                                                           *
 *       Saurabh S Dange ©                                                   *
 *   All rights reserved                                                     *
 *****************************************************************************/

 //HeaderFiles
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//declarationof structure
struct student
{

        int marks;
        char name[30];

}temp1;

//declaration of Function

int getRecord(int ,struct student array[]);

void sortRecord(int,struct student array[]);

void fetchRecord(int,struct student array[],int);

int  isNumber(const char []);

//----------------------------------------------------------------------------//


/******************************************************************************
 *   Function Name:getRecord                                                  *
 *   Parameters passed:number of students,structure                           * 
 *   Return Type: int                                                         *
 *   Description:used for storing the input in the structure                  *
 ******************************************************************************/
int getRecord(int stu,struct student array[])
{
          int i;

          for ( i = 0; i < stu; i++) {

                if( (scanf("%s",array[i].name)!=1)||scanf("%d",&array[i].marks)!=1)
                {
                        printf("invalid input\n");
                        return 0;
                        }
                if(isNumber(array[i].name))
{               printf("invalid output5");
                return 0;
}
         }
return 1;


}
//----------------------------------------------------------------------------//

/******************************************************************************
 *   Function Name:sortRecord                                                 *
 *   Parameters passed:number of students,structure                           *                       *
 *   Return Type: void                                                        *
 *   Description:used for sorting the content of the structure                *
 ******************************************************************************/
void sortRecord(int stu,struct student array[])
{
          int i;
          int j;
          int min;

          for(int i=0;i<stu;i++)
         {
                 min=i;
                 for( j=i+1;j<stu;j++)
                 {

                         if(array[min].marks>array[j].marks)
                        {
                                 min=j;
                        }


                 }

                 temp1=array[min];
                 array[min]=array[i];
                 array[i]=temp1;



         }


}

//----------------------------------------------------------------------------//
/******************************************************************************
 *   Function Name:fetchRecord                                                *
 *   Parameters passed:number of students,structure,number of toppers required*                          *                       *
 *   Return Type: void                                                        *
 *   Description:used for printing the top scorer                             *
 ******************************************************************************/

void fetchRecord(int stu,struct student  array[],int n)
{
          int i;

          for(i=stu-1;i>(stu-n-1);i--)
         {
                  printf("Name=%s\tMarks%d\n",array[i].name,array[i].marks);
         }
         printf("\n");
}

//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//

/******************************************************************************
*   Function Name:isNumber                                                    *
*   Parameters passed:string from command line                                *
*   Return Type:int                                                           *
*   Description:This is used for validating if input is integer or not        *
*******************************************************************************/
int isNumber(const char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}
//*************************************************************
int  main(int argc, char const *argv[]) {

          // Declaration of variables
          int n,stu,i,j,k;
          int min;
        //      printf("%s %s",argv[1],argv[2]);
          if(argc==3)
                {
                if((isNumber(argv[1])!=1)&&(isNumber(argv[2])!=1))
                {

                        goto er;
                }
                n=atoi(argv[1]);
                stu=atoi(argv[2]);
                if((n<0)||(stu<0)||(stu<n))
                {
                        er:
                        printf("invalid input1");
                        return 0;
                }
                struct student *array=malloc(sizeof(struct student)*stu);
                goto op;
                }

          //Taking the input for number of students
          printf("enter the number of students as a integer number\n");
         if((scanf("%d",&stu)!=1)||stu<0)
                                 {
                                         printf("invalid input2\n");
                                         return 0;
                                 }
        if(stu==0)
{
return 0;
}

                                 //dynamic allocation for structure
         struct student *array=malloc(sizeof(struct student)*stu);


                                 //Taking the input for number of toppers user wants
         printf("enter the integer value of n\n");
         if((scanf("%d",&n)!=1)||n<0)
                                 {
                                         printf("invalid input3\n");
                                         return 0;
                                 }

        if(stu<n)
{
        printf("invalid input4");
        return 0;
}
        op:


         //Enter the marks of the student in the order
         printf("enter the name and  marks  of students in names\n");

        if( getRecord(stu,array)==0)
        return 0;


         sortRecord(stu,array);

         fetchRecord(stu,array,n);


          return 0;
}
