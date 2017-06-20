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


//declarationof structure
struct student
{

        int marks;
        char name;

}temp1;

//declaration of Function

void getRecord(int ,struct *);

void sortRecord(int,struct *);

void fetchRecord(int,struct *);

//----------------------------------------------------------------------------//


/******************************************************************************
 *   Function Name:getRecord                                                  *
 *   Parameters passed:number of students,structure                           *                       *
 *   Return Type: void                                                        *
 *   Description:used for storing the input in the structure                  *
 ******************************************************************************/
void getRecord(int stu,struct *array)
{
          int i;

          for ( i = 0; i < stu; i++) {

                 scanf("%s%d",&array[i].name,&array[i].marks);

         }


}
//----------------------------------------------------------------------------//

/******************************************************************************
 *   Function Name:sortRecord                                                 *
 *   Parameters passed:number of students,structure                           *                       *
 *   Return Type: void                                                        *
 *   Description:used for sorting the content of the structure                *
 ******************************************************************************/
void sortRecord(int stu,struct *array)
{
          int i;

          for(int i=0;i<stu;i++)
         {
                 min=i;
                 for( j=i+1;j<stu;j++)
                 {

                         if(&array[min].marks>&array[j].marks)
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

void fetchRecord(int stu,struct *array,int n)
{
          int i;

          for(i=stu-1;i>(stu-n-1);i--)
         {
                  printf("Name=%s\tMarks%d\n",&array[i].name,array[i].marks);
         }
         printf("\n");
}

//----------------------------------------------------------------------------//

int int main(int argc, char const *argv[]) {

          // Declaration of variables
          int n,stu,i,j,k;
          int min;

          //Taking the input for number of students
          printf("enter the number of students as a integer number\n");
         if(scanf("%d",&stu)!=1)
				 {
					 printf("invalid input");
				 }

                                 //dynamic allocation for structure
         struct student *array=malloc(sizeof(struct student)*stu);


                                 //Taking the input for number of toppers user wants
         printf("enter the integer value of n\n");
         if(scanf("%d",&n)!=1)
				 {
					 printf("invalid input");

				 }



         //Enter the marks of the student in the order
         printf("enter the name and  marks  of students in names\n");

         getRecord(stu,&array);

         sortRecord(stu,&array);

         fetchRecord(stu,&array,n);


          return 0;
}
