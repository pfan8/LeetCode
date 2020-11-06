/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function (n) {
  if (n === 0) return [0];
  const size = 2 ** n;
  const pool = new Array(size).fill(0);
  const res = [0];
  pool[0];
  while (res.length < size) {
    const cur = res[res.length - 1];
    for (let i = 0; i < size; i++) {
      const test = cur ^ (1 << i);
      const diff = cur ^ test;
      if (pool[test] !== 1 && (diff & (diff - 1)) === 0) {
        res.push(test);
        pool[test] = 1;
        break;
      }
    }
  }
  return res;
};
