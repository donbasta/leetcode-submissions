/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    obj = {}
    for (let i = 0; i < this.length; i++) {
        const cur = fn(this[i]);
        if (!(cur in obj)) {
            obj[cur] = []
        }
        obj[cur].push(this[i]);
    }
    return obj;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */