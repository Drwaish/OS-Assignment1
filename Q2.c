#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
//#include<string.h>
//utility function
bool strcpy1(char arr1[8],char arr2[8])//length of roll no=8
{
  for(int i=0;i<8;i++)
	if(arr1[i]!=arr2[i])
	{
		return false;
	}
	return true;
}

void ReadFullRecord()
{
    FILE *fptr=fopen("D:\\Q2.txt","r");
    char name[50];
    char roll_no[8], chars;
    char email[22];
    
    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Name:\t\tRoll\t\tEmail\n");
    while(!feof(fptr))
    {
	
	fscanf(fptr, "Name: %s\t\tRoll no: %d\t\tEmail: %f\n"
                    , name, roll_no, email) ;
       

        printf("%s\t\t%d\t\t%.2f\n", name, roll_no ,email);
    }

    fclose(fptr);
}
void showOwnRecord()
{
    FILE *fptr=fopen("D:\\Q2.txt","r");
    char name[50];
    char roll_no[8], chars;
    char email[22];
    char r1[8];
    printf("Enter your roll number in this format lYear-Roll_No\n");
    scanf("%s",r1);
    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    
    //for(int i=0;i<n;i++)
    while(!feof(fptr));
    {
	
	fscanf(fptr, "Name: %s\t\tRoll no: %d\t\tEmail: %f\n"
                    , name, roll_no, email) ;
    if(strcpy1(r1,roll_no))//as roll number equal than print all particuars
    {
     	printf("Name:\t\tRoll\t\tEmail\n");
        printf("%s\t\t%d\t\t%.2f\n", name, roll_no ,email);
    }
    else 
    {
    	printf("not found");
	}
    }

    fclose(fptr);
}
void deleteAll()
{
	    FILE *fptr=fopen("D:\\Q2.txt","r");
	    if(fptr!=NULL)
	    {
	         	char oldname[]="Q2.txt";
                char newname[]="temp.txt";
    
   			 remove(oldname);  //remove and then rename
    		 rename(newname,oldname);// temp file after renaming Q2.txt
			fclose(fptr);
		}
  printf("Error  opening file\n");
}
void deletOwnRec()
{
	FILE *fptr=fopen("D:\\Q2.txt","r");
    char name[50];
    char roll_no[8], chars;
    char email[22];
    char r1[8];
    if(fptr!=NULL)
    {
    	printf("Enter your roll number for deletr your record\n");
        scanf("%s",r1);
    	FILE* fptr1=fopen("D:\\temp1.txt","w");// for deletion temporary
	    while(!feof(fptr));
    {
	
	fscanf(fptr, "Name: %s\t\tRoll no: %d\t\tEmail: %f\n"
                    , name, roll_no, email) ;
    if(!strcpy1(r1,roll_no))//as roll number equal than print all particuars
    {
	
    chars=fprintf(fptr1, "Name: %s\t\tRoll no: %d\t\tEmail: %.2f\n",
            name, roll_no, email);
    }
    fclose(fptr);
    fclose(fptr1);
    char oldname[]="Q2.txt";
    char newname[]="temp.txt";
    
    remove(oldname);  //remove and then rename
    rename(newname,oldname);// temp file after renaming Q2.txt
    
	}
}
      printf("Error  opening file\n");

}
void addRecord()
{
	FILE *fptr=fopen("D:\\Q2.txt","w");
    char name[50];
    char roll_no[8],chars;
    char email[22];

    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int c;
	//fscanf(fptr,"%[^\n]",c);                //previously number of records in file
    printf("Records",c);
	printf("Entry System: \n\n");
    int n;
    printf("Enter the number of records you want to enter: ");
    scanf("%d", &n);
                           
	     c=ftell(fptr);            //for new insertion  in file at empty space
   
   fseek(fptr,c,SEEK_END);         //point at empty space
   
   int i;
    for( i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nEnter the details of student %d \n\n", i +1);

        printf("Enter name of the student: ");
        gets(name);

        printf("Enter roll no: in this format lYear-Roll_No\n\n");
        gets(roll_no);
        printf("Enter Email:   in this format lYearRollNo@lhr.nu.edu.pk");
        gets(email);

        chars=fprintf(fptr, "Name: %s\t\tRoll no: %d\t\tEmail: %.2f\n",
            name, roll_no, email);
       printf("\n%d characters successfully written to the file\n\n", chars);
    }

    fclose(fptr);
}
int main()
{
	int a;         //optiions to perform different operation
	printf("Enter 0 to add Record\n\n");
	printf("Enter 1 to View Record\n\n");
	printf("Enter 2 to delete Record\n\n");
	printf("Enter the operation:\n\n");
	scanf("%d",&a);
	
	
		if(a==0)
		{
			printf("Add record","\n");
			addRecord();
			return 0;
		}
		if(a==1)
		{
			printf("View record \n\n");
			int y;          //for view own record or view fellow's record
			printf("Enter 0 for view own record \n \n");
			printf("Enter 1 for view fellows Record \n\n ");
			printf("Enter your wish->");
			scanf("%d",&y);
			if(y==0)
			{
				showOwnRecord();
			}
			else if(y==1)
			{
				ReadFullRecord();
			}
		}
		if(a==2)
		{
			printf("delet record \n\n");
			int y;          //for delete own record or view fellow's record
			printf("Enter 0 for delete own record\n\n");
			printf("Enter 1 for delete fellows Record \n\n");
				printf("Enter your wish->");
			scanf("%d",&y);
			if(y==0)
			{
				deletOwnRec();
			}
			
			else if(y==1)
			{
				deleteAll();
			}
		}
	else 
	{
		printf("sorry wrong choice\n\n");
		}	
	
	return 0;
}
