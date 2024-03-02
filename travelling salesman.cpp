#include<stdio.h> 
int arr[10][10],visited[10],n,cost=0;
int least(int);
void Input()
{
int i,j; 
printf("Enter the number of nodes: ");
scanf("%d",&n);
printf("\nEnter the Cost Matrix\n");
for(i=0;i < n;i++)
{
for( j=0;j < n;j++)
scanf("%d",&arr[i][j]);
visited[i]=0;
}
}
void mincost(int node)
{
int i,nnode;
visited[node]=1;
printf("%d--->",node+1);
nnode=least(node);
if(nnode==999)
{
nnode=0;
printf("%d",nnode+1);
cost+=arr[node][nnode];
return;
}
mincost(nnode);
}
int least(int c)
{
int i,nc=999;
int min=999,kmin; 
for(i=0;i < n;i++)
{
if((arr[c][i]!=0)&&(visited[i]==0))
if(arr[c][i]+arr[i][c] < min)
{
min=arr[i][0]+arr[c][i];
kmin=arr[c][i];
nc=i;
}
}
if(min!=999)
cost+=kmin;
return nc;
}
int main()
{
Input();
printf("\n\nThe Path is:\n");
mincost(0); 
printf("\n\nMinimum cost is %d\n ",cost);
return 0;
}
