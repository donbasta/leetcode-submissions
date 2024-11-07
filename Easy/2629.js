/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        if (functions.length === 0) {
            return x;
        }
        const [f1, ...fx] = functions;
        return f1(compose(fx)(x));
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */