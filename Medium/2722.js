/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let res = []
    let obj = {}
    for (const x of arr1) {
        const {id, ...rest} = x;
        obj[x["id"]] = rest;
    }
    for (const x of arr2) {
        const {id, ...rest} = x;
        if (!obj[x["id"]]) {
            obj[x["id"]] = rest;
        } else {
            for (const [key, value] of Object.entries(rest)) {
                obj[x["id"]][key] = value;
            }
        }
    }
    for (const [key, value] of Object.entries(obj)) {
        res.push({"id": Number(key), ...value});
    }
    res.sort((a, b) => a["id"] - b["id"]);
    return res;
};