#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CaseSum(char* pch);
void CaseLoop(int CaseTotal,int Index);
void PrintResult(int* Result,int TotalLoop,int Index);

int ResultArray[100];
int ParameterCounter = 0;
int IsError = 0;
//IsError = 0  is false;
int main()
{

	int CaseCount = 0;
	scanf("%d",&CaseCount);
	fflush(stdin);
	IsError = 0;
	CaseLoop(CaseCount,0);
	if (IsError == 1)
	{
	    //TODO NOTHING.
	}
	else
	{
		if(CaseCount == 0){
		    printf ("\n No case. \n\n");
		}

		else{
            printf ("\n Show Output \n\n");
		}
		PrintResult(ResultArray,CaseCount,0);
	}
    return 0;
}


void CaseLoop(int CaseTotal,int Index)
{
	if (CaseTotal == 0)
	{
		return ;
	}
	int InputCount = 0;
	scanf("%d",&InputCount);
	fflush(stdin);
	char InputSum [500];
	gets (InputSum);
	char *pch = strtok (InputSum," ");
	ParameterCounter = 0;
	ResultArray[Index] = CaseSum(pch);

	if (ParameterCounter != InputCount)
	{
		printf("Input Parameter is invalid.\n");
		IsError = 1;
		return;
	}

	CaseLoop(CaseTotal-1,Index+1);



}
void PrintResult(int* Result,int TotalLoop,int Index)
{
	if (TotalLoop ==0)
	{
		return ;
	}
	printf("%d \n",*(Result+Index));
	PrintResult(Result,TotalLoop-1,Index+1);

}


int CaseSum(char* pch)
{
	if (pch == NULL)
	{
		return 0;
	}
	ParameterCounter += 1;
	int x = atoi(pch);
	pch = strtok (NULL, " ");

	if (x<0)
	{
		x = 0;
	}
	return (x*x)+CaseSum(pch);

}
