/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let mapped = [];
    for (let i = 0; i < arr.length; i++) {
        mapped.push(fn(arr[i], i));
    }
    return mapped;
};