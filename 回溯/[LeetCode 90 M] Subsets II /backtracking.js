var quicksort = (arr, start, end) => {
  let left = start;
  let right = end;
  if (left >= right) return;
  let pivot = ~~Math.random(right - left + 1) + left;
  [arr[left], arr[pivot]] = [arr[pivot], arr[left]];
  pivot = arr[left];

  left += 1;
  while (left < right) {
    if (arr[left] <= pivot) {
      left += 1;
      continue;
    }
    if (arr[right] >= pivot) {
      right -= 1;
      continue;
    }
    [arr[left], arr[right]] = [arr[right], arr[left]];
    left += 1;
    right -= 1;
  }
  if (arr[left] > arr[start]) {
    pivot = left - 1;
    [arr[start], arr[pivot]] = [arr[pivot], arr[start]];
  } else {
    pivot = left;
    [arr[start], arr[pivot]] = [arr[pivot], arr[start]];
  }
  quicksort(arr, start, pivot - 1);
  quicksort(arr, pivot + 1, end);
  return arr;
};
var checkExist = function (res, arr) {
  for (let ra of res) {
    if (ra.length !== arr.length) continue;
    let found = false;
    for (let i = 0; i < ra.length; i += 1) {
      if (ra[i] !== arr[i]) {
        found = true;
        break;
      }
    }
    if (found) {
      continue;
    }
    return true;
  }
  return false;
};
var subsetsWithDup = function (nums) {
  if (nums.length === 0) return [[]];
  if (nums.length === 1) return [[], [nums[0]]];

  nums.sort((a, b) => a - b);
  const path = [];
  const res = [];
  function bt(cur) {
    if (!checkExist(res, path)) {
      res.push([...path]);
    }
    if (cur === nums.length) return;
    for (let i = cur; i < nums.length; i += 1) {
      path.push(nums[i]);
      bt(i + 1);
      path.pop();
    }
    bt(cur + 1);
  }
  bt(0);
  return res;
};
