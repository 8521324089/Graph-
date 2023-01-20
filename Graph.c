#include<stdio.h>
#include<stdlib.h>
struct node{
    int name;
    int weight;
    struct node *next;
};

void main()
{
    int vertices,element;
    struct node *matrix[30][30];
    
    printf("Enter the number of vertices = ");
    scanf("%d",&vertices);
    for(int i=0;i<vertices;i++)
    {
        matrix[i][0]=(struct node*)malloc((sizeof(struct node)));
        printf("Enter the %d Element name = ",i+1);
        scanf("%d",&matrix[i][0]->name);
        matrix[i][0]->weight=0;
    }
    
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<30;j++)
        {
            printf("Enter the neighbour of %d or press 0 =",matrix[i][0]->name);
            scanf("%d",&element);
            if(element==0)
            break;
            else{
                struct node *leave;
                for(int k=0;k<vertices;k++)
                {
                    leave=matrix[k][0];
                    if(leave->name==element)
                    break;
                }
                if(leave->name!=element)
                {
                    leave=0;
                    printf("Wrong vertex input\n");
                }
                printf("Enter the weight =");
                matrix[i][j+1]=(struct node*)malloc((sizeof(struct node)));
                matrix[i][j+1]->name=element;
                matrix[i][j+1]->weight=0;
                matrix[i][j+2]=0;
                scanf("%d",&matrix[i][j]->weight);
                matrix[i][j]->next=leave;
            }
        }
    }
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(matrix[i][j]==0)
            break;
            printf("[%d]-> ",matrix[i][j]->name);
            if(matrix[i][j+1]!=0)
            printf("%d-> ",matrix[i][j]->weight);
        }
        printf("\n");
    }
}
 