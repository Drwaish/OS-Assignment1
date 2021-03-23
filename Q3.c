#include<stdio.h>
#include<stdlib.h>
_Bool IsVowel(char var)//utility function
{
	return((var=='A'||var=='a' ||var=='e'||var=='E'||var=='i'||var=='I'||var=='o'||var=='O'||var=='u'||var=='U'));
}
int main()
{
//	printf("%s",IsVowel('m'));
FILE* fptr=fopen("D:\\Q1.txt","r");             //"Q1" because for Q1 and Q3 use same file instruct by our TA
FILE *fptr1=fopen("D:\\temp.txt","w");          //create file to save the changings of file
char str[15];								 //for store the word to reverse 
if(fptr==NULL)
{
	printf("Error in opening file\n\n");
	return 0;
}
if(fptr1==NULL)
{
	printf("Error in opening Temp file\n\n");
	return 0;
}

while(!feof(fptr))								//condition for iterate at end of file
{
	int n; 										//for size of string to perform operation 
	int var1=0,var2;								//store the i and j values to avoid redundancy										
	str[15]=NULL; 									//play safe ie to avoid over write
	fscanf(fptr,"%d",str);							//store first word in str from file
	//Now we operate the operation
	n=sizeof(str);
	var2=n-1;
	int i;
	for ( i=var1;i<n;i++)
	{
		if(!IsVowel(str[i]))//if it is not vowel than this if execute 
		{
			for(int j=var2;j<i;j++)          //iterate from last if 
		{
				if(!IsVowel(str[j]))//if it is not vowel than this if execute and replace with ith position
			   {
				char var3=str[i];  //for swapping
				str[i]=str[j];
				str[j]=var3;
				//for next iteration
				var2=j;
			     break;
			   }
			
		}
			
			
		}

	}
	fprintf(fptr1,"%s",str);         //store the text after performing operatioin 
	
}
char oldname[]="Q1.txt";
char newname[]="temp.txt";
remove (oldname);
rename(newname,oldname);
	
	return 0;
}
