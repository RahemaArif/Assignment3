#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int get_t1=0;
int ffsum=0;
int in=100,il=0;
void *thread1(void *args){
int sum=0;
int *arr2=(int *)args;
for(int i=il;i<in;i++){
sum=sum+arr2[i];
}
il=in;
in=in+100;
return((void*)sum);

}

int main(){
int ans[10];
pthread_t arr2[10];
int arr[1000];
for(int i=0;i<1000;i++){
arr[i]=i;
}
for(int i=0;i<10;i++){
pthread_create(&arr2[i],NULL,thread1,(void*)(arr));
}
for(int i=0;i<10;i++){
pthread_join(arr2[i],(void**) &get_t1);
ans[i]=((int)get_t1);
}
for(int i=0;i<10;i++){
ffsum=ffsum + ans[i];
}
printf("Final sum: %d",ffsum);
printf("\n");
return 0;

}
