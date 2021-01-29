#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int arraySize){
    int i;
    if(!array){
        printf("Cannot print array elements.\n");
        return;
    }
    for(i = 0; i < arraySize; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* runningSum(int *nums, int numsSize, int *returnSize){
    int *summArray;
    int i;

    summArray = (int*) malloc(numsSize * sizeof(int));
    if(!summArray){
        printf("Cannot allocate memory.\n");
        return NULL;
    }

    summArray[0] = nums[0];
    *returnSize = numsSize;

    for(i = 1; i < numsSize; i++){
        nums[i] += nums[i - 1];
        summArray[i] = nums[i];
    }

    return summArray;
}


int main(){
    int array[] = {1,2,3,4,5};
    int *summArray;
    int summArrayLength;

    summArray = runningSum(array, 5, &summArrayLength);
    printArray(summArray, summArrayLength);

    free(summArray);

    return 0;
}
