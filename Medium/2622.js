var TimeLimitedCache = function() {
    this.obj = {}
    this.timeoutIds = {}
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let alr = false;
    if (this.obj[key]) {
        alr = true;
        clearTimeout(this.timeoutIds[key])
        delete this.timeoutIds[key];
    }
    this.obj[key] = value;
    const timeoutId = setTimeout(() => {delete this.obj[key]}, duration);
    this.timeoutIds[key] = timeoutId;
    return alr;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.obj[key]) return this.obj[key];
    return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return Object.keys(this.obj).length;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */