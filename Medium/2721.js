/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const n = functions.length;
        let values = new Array(n);
        let fill = 0;
        for (let i = 0; i < n; i++) {
            functions[i]().then((res) => {
                values[i] = res;
                fill++;
                if (fill == n) {
                    resolve(values);
                }
            }).catch((err) => reject(err))
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */