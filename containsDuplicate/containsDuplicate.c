#include<stdio.h>
#include<stdbool.h>

void displayArr(int *arr, int size){
    for(int i=0;i<size;++i){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swapNumbers(int *numArr, int i, int j){
    int temp = numArr[i];
    numArr[i] = numArr[j];
    numArr[j] = temp;
}

int partionArray(int *numArr, int end, int start){
    int pivot = numArr[end];
    int i = start - 1;

    for(int j = start; j <= (end - 1); ++j){
        if(numArr[j] < pivot){
            ++i;
            swapNumbers(numArr, i, j);
        }
    }

    swapNumbers(numArr, ++i, end);
    return i;
}

void quickSort(int *numArr, int start, int end){
    if(start < end){
        int partitioning_index = partionArray(numArr, end, start);
        quickSort(numArr, start, partitioning_index-1);
        quickSort(numArr, partitioning_index+1, end);
    }
    
}

bool containsDuplicate(int* nums, int numsSize){
    quickSort(nums, 0, numsSize-1);

    int *p = nums;
    for(int i=0;i<numsSize-1;++i){
        if(*p == *(p+1)){
            return true;
        }
        ++p;
    }
    return false;
}


int main(){
    int arr[] = {2,3,1,5,2,7};
    quickSort(arr, 0, 5);
    // swapNumbers(arr, 1, 2);
    // displayArr(arr, 6);
    printf("%d", containsDuplicate(arr, 6));
    
    
    return 0;
}

/*
bool containsDuplicate(int* nums, int numsSize)
{
    int temp = 0; bool sorted = false;
    for(int i = 0; i < numsSize-1; i++)
    {
        sorted = false;
        for(int j = 0; j < numsSize-i-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                sorted = true;
            }
            else if(nums[j] == nums[j+1])
            {
                return true;
            }
        }
        if(!sorted)
        {
            return false;
        }
    }
    return false;
}
*/