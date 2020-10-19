/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function (people) {
  if (people.length < 2) return people;

  for (let cur = 0; cur < people.length; cur += 1) {
    // find index of min second value
    let mi = cur;
    for (let i = cur; i < people.length; i += 1) {
      if (people[mi][1] > people[i][1]) {
        mi = i;
      }
    }
    // insert into sorted array (cur before)
    let higherNum = 0;
    for (let i = 0; i < cur; i += 1) {
      if (people[i][0] >= people[mi][0]) {
        higherNum += 1;
        if (higherNum === people[mi][1] + 1) {
          people.splice(i, 0, people[mi]);
          people.splice(mi + 1, 1);
          mi = i;
          break;
        }
      }
    }
    if (higherNum === people[mi][1]) {
      people.splice(cur, 0, people[mi]);
      people.splice(mi + 1, 1);
    }
  }

  return people;
};
