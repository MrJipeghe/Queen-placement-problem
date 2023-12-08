#include <stdio.h>
#include <stdlib.h>
#define size 4
#define size_vector 4






x[size_vector];
void solutie(int x[])
{
    for(int i=1;i<=size;++i)
        printf("%d ",x[i]);
    printf("\n");
}
int conditie(int pozitie,int k)
{

    for(int i=1;i<k;++i)
        if(x[i]==pozitie-k+i||x[i]==pozitie+k-i||x[i]==pozitie)
            return 0;

    return 1;
}


void backtracking(int k)
{

    for(int i=0;i<size_vector;++i)
    {
        x[k]=i+1;
        if(k==1)
            backtracking(k+1);
        else if(conditie(x[k],k))
        {
            if(k<size_vector)
                backtracking(k+1);
            else solutie(x);
        }
    }




}


int main()
{
    FILE *f = fopen("fisier.txt", "r");

    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }

    int v[size_vector];
    for(int i=0;i<size_vector;++i)
    {
        fscanf(f, "%d", &v[i]);
    }

    printf("\n");



    backtracking(1);


}
