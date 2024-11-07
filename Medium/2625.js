/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let ans = [];
    if (n < 0) return [arr];
    for (let i = 0; i < arr.length; i++) {
        if (typeof arr[i] === 'number') {
            ans.push(arr[i]);
        } else {
            const rec = flat(arr[i], n - 1);
            ans.push(...rec);
        }
    }
    return ans;
};