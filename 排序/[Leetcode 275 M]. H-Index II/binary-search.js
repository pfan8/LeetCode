/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function (citations) {
  let left = 0,
    right = citations.length;
  while (left < right) {
    let mid = ~~((left + right) / 2);
    if (citations[mid] <= citations.length - mid - 1) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return citations.length - left;
};
