
// working fine
const swapNumbers = function(numArr, i, j){
    let temp = numArr[i];
    numArr[i] = numArr[j];
    numArr[j] = temp;

    return numArr;
}
// console.log(swapNumbers(arr, 1, 2));

const partionArray = function(numArr, end, start){
    let pivot = numArr[end];
    let i = start - 1;

    for(let j = start; j < (end - 1); ++j){
        if(numArr[j] < pivot){
            ++i;
            numArr = swapNumbers(numArr, i, j);
        }
    }

    numArr = swapNumbers(numArr, ++i, end);
    return i;
}

const quickSort = function(numArr, start, end){
    if(start < end){
        let partitioning_index = partionArray(numArr, end, start);

        numArr = quickSort(numArr, start, partitioning_index-1);
        numArr = quickSort(numArr, partitioning_index+1, end);
    }
    
}

const main = function(){
    let arr = [2,3,1,5,0,7]
    quickSort(arr, 0, 5);
    console.log(arr);
}