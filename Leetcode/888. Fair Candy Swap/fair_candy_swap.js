// Leetcode 888. Fair Candy Swap
// https://leetcode.com/problems/fair-candy-swap/
// time complexity: O(NlogN)
// space complexity: O(1)

/**
 * @param {number[]} aliceSizes
 * @param {number[]} bobSizes
 * @return {number[]}
 */

var isExist = function(data, begin, end, target)
{
    while (begin <= end) {
        // have to floor the mid, otherwise the mid would be fractional number
        let mid = begin + Math.floor((end - begin) / 2);        
        if (data[mid] === target) {
            return true;
        } else if (data[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return false;
}

var fairCandySwap = function(aliceSizes, bobSizes)
{
    let result = [];
    let sum = 0;
    let aliceSum = 0;
    let bobSum = 0;
    aliceSizes.forEach((candy) => {
        aliceSum += candy;
    });
    
    bobSizes.forEach((candy) => {
        bobSum += candy;
    });
    
    bobSizes.sort((a, b) => a - b);
    
    let average = (aliceSum + bobSum) / 2;
    
    // a bit possible optimization:
    // we could choose shorter array for using in outer loop
    for (let i = 0; i < aliceSizes.length; i++) {
        let remain = aliceSum - aliceSizes[i];
        if (remain < average) {
            let target = average - remain;
            if (isExist(bobSizes, 0, bobSizes.length - 1, target)) {
                result.push(aliceSizes[i]);
                result.push(target);
                break;
            }
        }
    }
    
    return result;
};
