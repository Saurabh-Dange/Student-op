
/*****************************************************************************
 *   PROJECT  :Read the data from given CSV file and perform following       *
 *   operations                                                              *
 *   1-Recieve the roll number from user and print the score                 *
 *   2-Recieve the name of student from user and print the rank excluding    *
 *     Repeater's                                                            *
 *                                                                           *
 *   FILE_NAME:csv.c                                                         *
 *   VERSION  :1.0.0                                                         *
 *   DATE     :19/06/2017                                                    *
 *   Files used:details.csv                                                  *
 *                                                                           *
 *                                                                           *
 *       Saurabh S Dange ©                                                       *
 *   All rights reserved                                                     *
 *****************************************************************************/
/*****************************************************************************/

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*****************************************************************************/

struct student
{
        int Roll_N;
        char Name[20];
        int marks;
        char Repeater[10];

}array[15];

/*****************************************************************************/
//function declaration

void getRecord(struct student array[]);

void pScore(struct student array[]);

void pRank(struct student array[]);

void sort(struct student array[]);

void Modify(struct student array[]);
/*****************************************************************************/

/******************************************************************************
 *   Function Name:getRecord                                                  *
 *   Parameters passed:structure                                              *
 *   Return Type: void                                                        *
 *   Description:used for fetching the record from provided csv file          *
 ******************************************************************************/

void getRecord(struct  student array[]) {
       FILE *fp;
        fp=fopen("details.csv","r");
        char name[1024];
        int i,k=0;
        char *arr;
        int j=0;
  while((fscanf(fp,"%s",name)!=EOF)&&(j<15))

  {



          arr=strtok(name,",");//strtok gives the tokenized part of string
                              // It is like trimming the string


          for(i=0;i<4;i++)
          {         // this stores the value for roll number
                    if(i==0)
                      {
                    array[j].Roll_N=atoi(arr);
                      printf("r=%d\t",array[j].Roll_N);
                    }

                    // this stores the value for score
                    if(i==2)
                    {
                      array[j].marks=atoi(arr);
                      printf("s=%d\t",array[j].marks);
                    }

                    // this stores the value for Name
                    if(i==1)

                    {

                    strcpy( array[j].Name,arr);
                    printf("n=%s\t",array[j].Name);

                    }

                    // this stores the value for Repeater index
                     if(i==3)
                    {
                      strcpy(array[j].Repeater,arr);
                      printf("re=%s\n",array[j].Repeater);
                    }

                    arr=strtok(NULL,",");

      }
      j++;
      k++;
  }
}
/*****************************************************************************/

/******************************************************************************
 *   Function Name:pScore                                                     *
 *   Parameters passed:structure                                              *
 *   Return Type: void                                                        *
 *   Description:used for printing the score according to rank                *
 ******************************************************************************/

 void pScore(struct student array[]) {

      int i;
      int ROLL;
      printf("enter the roll number of student\n");


      //validation
      if((scanf("%d",&ROLL))!=1)
      {
        printf("invalid input ");
        return  ;
      }

      for(i=0;i<15;i++)
      {

              if(array[i].Roll_N==ROLL)
      {
              break;
      }


      }

        printf("%d\n",array[i].marks);

}
/*****************************************************************************/


/******************************************************************************
 *   Function Name:pRank                                                      *
 *   Parameters passed:structure                                              *
 *   Return Type: void                                                        *
 *   Description:used for printing the rank of student                        *
 ******************************************************************************/

void pRank(struct student  array[])
{
          char stu_name[20];

          int count=0;
          int i,j;
          printf("enter the name of student\n");

          if((scanf("%s",stu_name))!=1)
          {

              printf("invalid input");
              return ;

            }


            for(i=0;i<15;i++)
            {


                if(strcmp(stu_name,array[i].Name)==0)//copy 3
                {
                        printf("%s\t",array[i].Name);
                        break;
                }

              }

              for(j=14;j>=0;j--)
              {
                if(array[j].marks>array[i].marks)
                {
                    count++;
                }
              }
              printf("%d\n",count);


}

/*****************************************************************************/

/******************************************************************************
 *   Function Name:sort                                                       *
 *   Parameters passed:structure                                              *
 *   Return Type: void                                                        *
 *   Description:used for sorting the structure according to score            *
 ******************************************************************************/


void sort(struct student  array[])
{

                int i,j,key=0;
                for(i=1;i<15;i++)
            {

                  key=array[i].marks;
                  j=i-1;


            while(j>=0&&(array[j].marks)>key)
            {

                  array[j+1].marks=array[j].marks;
                  j=j-1;

            }
                  array[j+1].marks=key;

            }


}

/*****************************************************************************/

/******************************************************************************
 *   Function Name:Modify                                                     *
 *   Parameters passed:structure,                                             *
 *   Return Type: void                                                        *
 *   Description:used for making entry 0 for Repeater                            *
 ******************************************************************************/

void Modify(struct student array[])
{
          int i;
            for(i=0;i<15;i++)
          {

          if((i==2)||(i==3)||(i==9)||(i==12))
          {
           array[i].marks=0; // makes the value of score 0 if student is repeater

          }

          else
          {
            continue;
          }

          }
}
/*****************************************************************************/

int main() {

          int c;




          getRecord(array);
          printf("Enter your choicen\n");
          printf("1:Enter roll number and get score\n");
          printf("2:Enter Name and get Rank\n");

          if(scanf("%d",&c)!=1)
          {
                printf("invalid input");
          }

          switch (c) {
            case 1:pScore(array);
                    break;
            case 2: Modify(array);
                    sort(array);
                    pRank(array);
                    break;

          }

          return 0;
}

