#include <stdio.h>
#include <stdlib.h>
//sub problems:
//allocate memory for the numbers
//go through elements of nums 
//check if nums[i]+num[i+1]
//if yes, store the index of each of those
//else repeat

//its possible to add all elements then go through checking the sum and get
//the address of those whose sum = target.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //provide an array of integers nums of size numsSize, return the indices that
 //sum up to returnSize



int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
 
//allocate mem location for	the numbers. nums hold a memory address that is large enough to store numsSize integers

int *sumAtIndex;
	int a = 0;
	//sum all indexes

	int j = 1;
	int var=0; //controls j position
	for (int i=0;i<numsSize;i++)
	{
		for(;j<numsSize;j++){
			*(returnSize+a)=*(nums+i)+*(nums+j);
			a++;
		}
		//following piece of code makes it so after each
		//i iteration, j increases so it wont always
		//point to element [1].
		var=var+1;
		j=1+var;
	}
	
	//proud of this discrete mathematics formula down
	//here lol
	for(int i = 0; i<(numsSize*(numsSize-1)/2);i++){
	printf("%d \n",
	returnSize[i]);  
	}
	return returnSize;

}


int main()
{

	int numsSize=4;
	int* nums=(int *)malloc( (numsSize)*sizeof(int) );
	int target=9;	
	int* returnSize = malloc(numsSize*sizeof(int));
	nums[0]=1;
	nums[1]=2;
	nums[2]=7;
	nums[3]=10;
	twoSum( nums,numsSize,target,returnSize );

	

	for(int i=0;i<numsSize;i++)
	{
	//printf("%d\n", *(returnSize+i));
	}



}
