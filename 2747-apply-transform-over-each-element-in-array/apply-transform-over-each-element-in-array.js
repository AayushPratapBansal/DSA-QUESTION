/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
  return arr.map((value, index) => {
    return fn(value, index);  // apply the logic passed in fn
  });
};

// Use it to increase by 1
let result = map([1, 2, 3], function(value) {
  return value + 1;
});

console.log(result); // [2, 3, 4]
