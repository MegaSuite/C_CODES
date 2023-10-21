/*
* ==================================================================

* Description: aback-up.c
* Author: Konrad Locas.
* (C)Copyright Konrad Locas.
* All rights reserved.
* Date: 2023/04/03 21:29:10

* ===================================================================
*/
#include<stdio.h>
int main(void)
{
	int n,money;
	int fix[6]={100,50,10,5,2,1}; 
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&money);

			for(int j=0;j<6;j++)
			{
				sum=sum+money/fix[j];
				money=money%fix[j];
			}	
		}

		int a;
		scanf("%d",&a);
		
		if(sum==0)
			printf("Impossible\n");
		else
			printf("%d\n",sum);
	}
	return 0;
 }