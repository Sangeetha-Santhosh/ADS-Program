#include<stdio.h>
int main(){
    int u,i,a,b,j;
    printf("Enter limit of universal set");
    scanf("%d",&u);
    int uni[u];
    printf("enter %d elements of universal set : ",u);
    for(i=0;i<u;++i)
        scanf("%d",&uni[i]);

    printf("Enter limit of set A");
    scanf("%d",&a);
    int seta[a];
    printf("enter %d elements of set a : ",a);
    for(i=0;i<a;++i)
        scanf("%d",&seta[i]);

    printf("Enter limit of set B");
    scanf("%d",&b);
    int setb[b];
    printf("enter %d elements set b : ",b);
    for(i=0;i<b;++i)
        scanf("%d",&setb[i]);

    int bita[u];
    int bitb[u];
    for(i=0;i<u;++i)
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

    printf("Bit string of A :");
    for(i=0;i<u;++i)
        printf("%d",bita[i]);

    printf("Bit string of B :");
    for(i=0;i<u;++i)
        printf("%d",bitb[i]);

    int unio[u],inter[u],diffab[u],diffba[u];

    for(i=0;i<u;++i)
    {
        unio[i]=bita[i]|bitb[i];
        inter[i]=bita[i]&bitb[i];
        diffab[i]=bita[i]&(!bitb[i]);
        diffba[i]=bitb[i]&(!bita[i]);
    }

    printf("Union :");
    for(i=0;i<u;++i)
        printf("%d",unio[i]);

    printf("Intersection :");
    for(i=0;i<u;++i)
        printf("%d",inter[i]);

    printf("A-B:");
    for(i=0;i<u;++i)
        printf("%d",diffab[i]);

    printf("B-A :");
    for(i=0;i<u;++i)
        printf("%d",diffba[i]);

    return 0;
}
