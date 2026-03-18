#include<stdio.h>
void main()
{
	int u,a,b,i,j;
	printf("Enter the size of the universal set : ");
	scanf("%d",&u);
	int uni[u];
	printf("Enter %d elements of the universal set ",u);
	for(i=0;i<u;i++)
		scanf("%d",&uni[i]);
		
	printf("Enter the size of the set A : ");
	scanf("%d",&a);
	int seta[a];
	printf("Enter %d elements of the set A ",a);
	for(i=0;i<a;i++)
		scanf("%d",&seta[i]);
		
	printf("Enter the size of the set B: ");
	scanf("%d",&b);
	int setb[b];
	printf("Enter %d elements of the set B ",b);
	for(i=0;i<b;i++)
		scanf("%d",&setb[i]);
		
	int bita[u],bitb[u],Union[u],inter[u],diffab[u],diffba[u];
	for(i=0;i<u;i++)
	{
		bita[i]=0;
		bitb[i]=0;
		
		for(j=0;j<a;j++)
			if(uni[i]==seta[j])
				bita[i]=1;
		
		for(j=0;j<b;j++)
			if(uni[i]==setb[j])
				bitb[i]=1;
	}
	
	printf("Bit strings of A : ");
	for(i=0;i<u;i++)
		printf("%d",bita[i]);
		
	printf("Bit strings of B : ");
	for(i=0;i<u;i++)
		printf("%d",bitb[i]);
		
    for(i=0;i<u;i++)
    {
    	Union[i]=bita[i] | bitb[i];
		inter[i]=bita[i] & bitb[i];
		diffab[i]=bita[i]&(!bitb[i]);
		diffba[i]=bitb[i]&(!bita[i]);
	}
	printf("\nAUB : {");
	for(i=0;i<u;i++)
		if(Union[i])
			printf("%d,",uni[i]);
	printf("}");
				
	printf("\nAnB : {");
	for(i=0;i<u;i++)
		if(inter[i])
			printf("%d,",uni[i]);
	printf("}");	
	
	printf("A-B : {");
	for(i=0;i<u;i++)
		if(diffab[i])
			printf("%d,",uni[i]);	
	printf("}");	
	
	printf("B-A : {");
	for(i=0;i<u;i++)
		if(diffba[i])
			printf("%d,",uni[i]);
	printf("}");		
}
