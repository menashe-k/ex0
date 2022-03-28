#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR -1

int getLength();
int getNumbers(int *nums, int len);
void execute(int nums[], int len);
void findExponent(int num, int exponent, int *sum, int *originalnum);

int main() 
{
    int len= getLength();
    if(len==ERROR){
        return 0;
	}
    int *nums= malloc(sizeof (int)*len);
    if(getNumbers(nums,len)==ERROR){
        return 0;
	}
    execute(nums,len);
    free(nums);
    return 0;
}

int getLength()
{
    int len;
    printf("Enter size of input:\n");
    if(scanf("%d",&len)!=1 || len<=0){
        printf("Invalid size\n");
        return ERROR;
    }
    return len;
}
int getNumbers(int *nums, int len)
{
    printf("Enter numbers:\n");
    for (int i = 0; i < len; ++i) {
        if(scanf("%d",&nums[i])!=1){
            printf("Invalid number\n");
            free(nums);
            return ERROR;
        }
    }
    return 1;
}
void execute(int nums[], int len)
{
    int sum=0;
    for (int i = 0; i < len; ++i) {
        findExponent(nums[i],0,&sum,&nums[i]);
    }
    printf("Total exponent sum is %d\n",sum);
}

void findExponent(int num, int exponent, int *sum, int *originalnum)
{
    if(num==2){
        *sum+=exponent+1;
        printf("The number %d is a power of 2: %d = 2^%d\n",*originalnum,*originalnum,exponent+1);
        return;
    }
    if(num%2!=0 || num<=0){
        return;
	}
    findExponent(num/2,exponent+1,sum, originalnum);
}
