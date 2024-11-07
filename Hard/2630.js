/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    table = []
    computed = []

    return function() {
        let arr = Object.values(arguments);
        for (let i = 0; i < computed.length; i++) {
            if (computed[i].length !== arr.length) continue;
            let n = computed[i].length;
            let ok = true;
            for (let j = 0; j < n; j++) {
                if (computed[i][j] !== arr[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return table[i];
            }
        }
        table.push(fn(...arr));
        computed.push(arr);
        return table[table.length - 1];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */