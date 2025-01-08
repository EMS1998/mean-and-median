//计算平均值，中位数
#include<stdio.h>
#include<stdlib.h>//qsort用到，malloc用到


int compare(const void* a,const void* b){
	//考虑a-b的顺序，假设a=50 b=80，a-b=-30,a=50在前面，小的在前面，合理
	return (* (int*)a-* (int*)b);//这是错的：return (int*)a-(int*)b;
}

int main(){
	int n;
	printf("要输入的数字有多少个？\n");

	scanf("%d",&n);
	int* arr=(int*)malloc(n*sizeof(int));
	
	//面试malloc是否工作完成
	if(arr==NULL){
		printf("MALLOC分配内存失败");//TODO
		return 1;
	}
	
	//将n个数字存入数组
	printf("输入%d个数字，用空格隔开\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
		//TODO
	}
	
	//计算平均值

	double sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		//TODO
	}
	double mean=sum/n;
	
	//求中位数
	//先用qsort对数组排序
	qsort(arr,n,sizeof(int),compare);
	double median;
	if(n%2==0){//假设n=4，那么取第2，3的数字，也就是arr[1],arr[2],也就是arr[n/2-1] arr[n/2]
		median=(arr[n/2-1]+arr[n/2])/2.00;//平均值要求保留2位小数
	}else{
		//考虑n=5，median为3，arr[2],arr[(n-1)/2.0]//中位数保留1位小数
		median=arr[(n-1)/2];
	}
	
	printf("mean=%.2f,median=%.1f",mean,median);
	
	
	free(arr);
	return 0;
}
