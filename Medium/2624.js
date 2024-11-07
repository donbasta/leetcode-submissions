/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if (this.length != rowsCount * colsCount) {
        return [];
    }
    let arr = [];
    for (let i = 0; i < rowsCount; i++) arr.push(new Array(colsCount));
    let curIndex = 0;
    for (let i = 0; i < colsCount; i++) {
        if (i % 2 == 0) {
            for (let j = 0; j < rowsCount; j++) {
                arr[j][i] = this[curIndex++];
            }
        } else {
            for (let j = rowsCount - 1; j >= 0; j--) {
                arr[j][i] = this[curIndex++];
            }
        }
    }
    return arr;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */