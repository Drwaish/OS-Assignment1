#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

int Occur_of_Sub_String(char* arr,FILE* fp,int size)
{
		int occur = 0;  //counter to return number of occurences 
	     char ch=getc(fp);
	     
	     //printf("%d",arr[0]);
	  while(ch!=EOF)
	   {
	  // printf("%d",ch);
	  	 if(ch==(int)arr[0])//check for first match
	  	  {
	  	     	for (int  i=1;i<size;i++)
	  	 
		   	    {
		   		   if((ch=getc(fp))!=arr[i])
	  	 		    {
	  	 			break;
	  	 		    }
	  	 	        	if((ch=getc(fp))==arr[i])
	  	 	    		{
	  	 				if(i==size-1)//for complete matching
	  	 					{
	  	 					occur++;
					   
							}
						}
	  	 	       }
	  	 	
		}
	  	ch=getc(fp);
	   } 

	return occur;


}

int main()
{
	
	
		int num;
		int size;
		FILE* fptr;
        char* arr,c;  //for substring
        //input  size of substring
        printf("Enter the size of substring\n\n");
        scanf("%d",&size);
        
     	arr =(char*) malloc(sizeof(char) );// allocation of memory
     	if(arr!=NULL)
     	 {
     		printf("Size is allocated Please Enter Substring\n\n");
		 }
     	if(arr==NULL)
     	 {
     		printf("Memory is not allocated \n\n");
		 }
		 int i=0;
  for(int i=0;i<size;++i)
  {
        char var;
		 	scanf("%d",&var);
		 	arr[i++]=var;	
		 
	}
          for(int i=0;i<size;i++)
           {
           	char var=arr[i];
		     printf("%s",var);
           }
           
		fptr = fopen("D:\\Q1.txt", "r") ;
		if (fptr == NULL)     //base case
	{
		printf("File does not exist (' | ')");
		return 1;
	}
	    

        
          printf("Value of Occurences=%d",Occur_of_Sub_String(arr,fptr,size) );
		
		fclose(fptr);
         
         
         free(arr);        //deallocate memory
		return 0;
	}
	
