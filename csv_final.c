/*****************************************************************************
 *   PROJECT  :Read the data from given CSV file and perform following       *
 *   operations                                                              *
 *   1-Recieve the roll number from user and print the score                 *
 *   2-Recieve the name of student from user and print the rank excluding    *
 *     Repeater's                                                            *
 *                                                                           *
 *   FILE_NAME:top_scorer.c                                                  *
 *   VERSION  :1.0.0                                                         *
 *   DATE     :19/06/2017                                                    *
 *                                                                           *
 *	 Saurabh S Dange ©                                                       *
 *   All rights reserved                                                     *
 *****************************************************************************/

/*****************************************************************************/

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*****************************************************************************/
int main()
{

      //declartion
      FILE *fp;
      fp=fopen("details.csv","r");
      char *arr;
      int i=0;
      int j=0,k=0;
      int r_no[2][15];
      int score[15];
      int ROLL;
      int key;
      char stu_name[20];
      char Name[15][15];
      char Repeater[15][15];
      char name[1024];
      int count=1;
      char *id1[20];

/*****************************************************************************/
      // code for reading the file
      while((fscanf(fp,"%s",name)!=EOF)&&(j<15))

      {
              arr=strtok(name,",");//strtok gives the tokenized part of string
                                  // It is like trimming the string


              for(i=0;i<4;i++)
              {         // this stores the value for roll number
                        if(i==0)
                          {
                          r_no[0][j]=atoi(arr);
                          printf("r=%d\t",r_no[0][j]);
                        }

                        // this stores the value for score
                        if(i==2)
                        {
                          r_no[1][j]=atoi(arr);
                          printf("s=%d\t",r_no[1][j]);
                        }

                        // this stores the value for Name
                        if(i==1)

                        {

                        strcpy( Name[j],arr);
                        printf("n=%s\t",Name[j]);

                        }

                        // this stores the value for Repeater index
                         if(i==3)
                        {
                          strcpy(Repeater[j],arr);
                          printf("re=%s\n",Repeater[j]);
                        }

                        arr=strtok(NULL,",");

          }
          j++;
          k++;
      }


/*****************************************************************************/


      // code for problem 1

      printf("enter the roll number of student\n");


      //validation
      if((scanf("%d",&ROLL))!=1)
      {
        printf("invalid input ");
        return 0 ;
      }

      for(i=0;i<15;i++)
      {

              if(r_no[0][i]==ROLL)
      {
              break;
      }


      }

        printf("%d\n",r_no[1][i]);


/*****************************************************************************/


      // code for problem 2

      //separate array is defined for storing the sorted value

      for(i=0;i<15;i++)
      {

      if((i==2)||(i==3)||(i==9)||(i==12))
      {
            score[i]=0; // makes the value of score 0 if student is repeater

      }

      else
      {
            score[i]=r_no[1][i];
      }

      }



      for(i=1;i<15;i++)
      {

            key=score[i];
            j=i-1;


      while(j>=0&&score[j]>key)
      {

            score[j+1]=score[j];
            j=j-1;

      }
            score[j+1]=key;

      }
      //sorting complete
/*****************************************************************************/
      printf("enter the name of student\n");

      if((scanf("%s",stu_name))!=1)
      {

        printf("invalid input");
        return 0;

      }


      for(i=0;i<15;i++)
      {


                if(strcmp(stu_name,Name[i])==0)//copy 3
                {
                        printf("%s\t",Name[i]);
                  break;
                }

       }

      for(j=14;j>=0;j--)
      {
              if(score[j]>r_no[1][i])
              {
                count++;
              }
      }
              printf("%d\n",count);

      return 0;


}
/*****************************************************************************/
