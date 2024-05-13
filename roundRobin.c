// ROUND ROBIN

#include<stdio.h>

void main()
{
	int n,b[100],a[100],w[100],tp[100],tq,flag=0,i,k,temp[100],tat[100],total=0;
	float avg_wt,total_wt;
	printf("Enter the no. of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process%d:",i+1);
		scanf("%d",&b[i]);
		w[i]=0;
		tp[i]=0;
	}
	printf("Enter the time quantum:");
	scanf("%d",&tq);
	i=0,k=0;
	while(1)
	{
		if(i==n)
		i=0;
		if(flag==n)
		break;
		
		if(b[i]<=tq && b[i]>0)
		{
			w[i]+=total-tp[i];
			flag++;
			
			total+=b[i];
			b[i]=0;
			temp[k]=i;
			k++;
		}
		if(b[i]>tq)
		{
			w[i]+=total-tp[i];
			b[i]=b[i]-tq;
			total+=tq;
			temp[k]=i;
			k++;
		}
		tp[i]=total;
		i++;
	}
	printf("Order of execution:\n");
	for(i=0;i<k;i++)
	{
		printf("P%d  ",temp[i]);
	}
	printf("\nWaiting Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",w[i]);
		total_wt+=w[i];
	}
	
	printf("\nAverage waiting time\n");
	avg_wt=total_wt/n;
	printf("%f",avg_wt);
}
