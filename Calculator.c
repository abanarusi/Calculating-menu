#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int quadratic_root_1( int a, int b, int c) //Self defined fucntion for q2
{
	double root_a;

	 root_a=(-b +sqrt(pow(b, 2)-4*a*c))/2*a;
	 
	 return (root_a);
}
int quadratic_root_2( int a, int b, int c) //Self defined fucntion for q2
{
	double root_b;

	 root_b=(-b -sqrt(pow(b, 2)-4*a*c))/2*a;
	 
	 return (root_b);
}
int min(int alphas, int betas) //Self defined fucntion for q5
{
    return (alphas > betas ) ? betas : alphas;
}


int main () 
{
	int question, i;
	printf("Select one of the following: \n\n");
	printf("1. Calculating the power or root that is subject to your candidate number.\n\n");
	printf("2. Calculating roots of a quadratic equation.\n\n");
	printf("3. Caculating the value of a+x^n.\n\n");
	printf("4. Enter in a 3 by 2 Matrix where the elements are:\n\n  12   22\n  38   40\n  11   33\n\n");
	printf("5. Finding the max and min of user defined data.\n\n");
	printf("6. Loading File.txt\n\n");
	scanf("%d", &question);
	for(i=question;i<=6;i++)
	{
		
		while (question==1) //This is Question One
		{
		
			int Value_1, Value_2, Value_3, Value_4, Value_5, Value_6, sum, i=2;
			double root, power, result;
			printf("Enter in your student candidate number: \n");
			scanf("%d%d%d%d%d%d", &Value_1, &Value_2, &Value_3, &Value_4, &Value_5, &Value_6);
			sum = Value_1+Value_2+Value_3+Value_4+Value_5+Value_6;
			if (sum<=20 || sum==25)
			{
				result = pow(sum, i);
				printf("The sum of your candidate number is %d\n", sum);
				printf("The power of your sum is %lf\n", result);
			}
			else 
			{
				root=sqrt(sum);
				printf("The Sum of your candidate number us %d\n", sum);
				printf("The Squre root of your number is %lf\n\n", root);
			}
			getch();
			return 0;
		}
		while (question==2) //This is Questipn 2
		{
			
			double n1, n2, n3, root_1, root_2;
			
			printf("\n\nNow enter in values a, b and c of a quatratic:\n");
			scanf("%lf%lf%lf", &n1, &n2, &n3);
			if (pow(n2, 2)-4*n1*n3<=0)
			{
				printf("The values that you have entered do not satisfy the requirments, please try again\n");	
			}
			else 
			{
				root_1 = quadratic_root_1 (n1, n2, n3);
				root_2 = quadratic_root_2 (n1, n2, n3);
				printf("The roots is %lf and %lf", root_1, root_2);
			}
			getch();
			return 0;
		}
		while (question==3) //This is question 3
		{
			double val_a, val_x, val_n, end_value, carry_numb;
			printf("Enter in the values for a, x in order:\n");
			scanf("%lf%lf", &val_a, &val_x);
			for (val_n=carry_numb;carry_numb<100;carry_numb++)
			{
			end_value=val_a+pow(val_x, carry_numb);
			if(end_value<=2147483647)
				{
					printf("%.1lf  ", end_value);
				}
			else
				{
				printf("\n\nThe rest of the values lie out of the range");	
				getch();
				return 0;
				}
			}
			getch();
			return 0;
		}
		while (question==4) //This is question 4
		{
			int a[10][10];
			int x, y, pointer, row,column, matrix_sum=0;
			printf("Enter in the amount of rows and columns for Matrix A: \n");
			scanf("%d %d", &row,&column);
			
			printf("Now, enter the elements for Matrix A \n");
			for (y=0; y<row; y++)
			{
				for (x=0; x<column; x++)
				{
					scanf("%d",&a[y][x]);
				}
			}
			int *ptr = &a[y-1][x-1];
			printf("Matrix A is: \n\n");
			for (y=0; y<row; y++)
			{
				for (x=0; x<column; x++)
				{
					printf("%-5d  ",a[y][x]);
				}
				printf("\n");
			} 
			
			printf("Enter in a new value to replace the last element of the array:\n");
			scanf("%d",&pointer);
			*ptr=pointer;			
			printf("Matrix A is: \n\n");
			for (y=0; y<row; y++)
			{
				for (x=0; x<column; x++)
				{
					printf("%-5d  ",a[y][x]);
					matrix_sum=matrix_sum+a[y][x];
				}
				printf("\n");
			} 
			printf("Sum of entered matrices: %d \n", matrix_sum);
			getch();
			return 0;		
			}  	
		while(question==5)//this is question 5
		{
			int array[100],*maximum, size, c, *minimum, *ptr=&array[c];
			printf("Enter the size of the array\n");
			scanf("%d",&size);
			printf("Enter the Elements of the array\n");
			for(c=0;c<size;c++)
			{
				scanf("%d", &array[c]);
			}
				
			*ptr = array[0];
			//printf("The first element of the array is %d\n", *ptr); //used to debug
			
			maximum=array;
			*maximum=*array;
				
			for (c=1;c<size;c++)
			{
				if(*(array+c)>*maximum)
				{
					*maximum=*(array+c);
				}
			}
			printf("The maximum is %d\n", *maximum);
				
			//printf("The first element of the array is %d\n", *ptr); //used to debug
			minimum=array;
			*minimum=*array;
			for (c=1;c<size;c++)
			{
				if(*ptr<*minimum)
				{
					*minimum=*ptr;
				}
				if(*(array+c)<*minimum)
				{
					*minimum=*(array+c);
				}					
			}
			int alpha, beta, mins;
			alpha=*ptr;
			beta=*minimum;
				
			mins = min(alpha, beta);
			printf("The minimum is %d", mins);
				
			getch();
			return 0;	
		}
		while(question==6) //this is question 6
		{
			FILE *fPointer;
			fPointer = fopen("data.txt", "r");
			char singleLine[150];
			while(!feof(fPointer))
			{
				fgets(singleLine, 150, fPointer);
				puts(singleLine);
			}
			fclose(fPointer);
			return 0;		    
		}
	
		if(i>6) //This is if the entered number is invalid
		{
			printf("You have entered an invalid number, please try again");
		}
	
		getch();
		return 0;
	}
}
	


