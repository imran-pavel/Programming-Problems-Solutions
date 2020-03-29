/*

A format for expressing an ordered list of integers is to use a comma separated list of
either individual integers or a range of integers denoted by the starting integer
separated from the end integer in the range by a dash, '-'.

The range includes all integers in the interval including both endpoints.
It is not considered a range unless it spans at least 3 numbers.

For example ("12, 13, 15-17")
Complete the solution so that it takes a list of integers in increasing order and
returns a correctly formatted string in the range format.

Example:

solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]);
// returns "-6,-3-1,3-5,7-11,14,15,17-20"

*/

function solution(list){
  let eatEm = (startIndex) => {
    if(startIndex >= list.length) return null;
    let eaten = [];
    let i = startIndex;
    do {
      eaten.push(list[i]);
      i++;
    } while(i<list.length && list[i] - 1 === list[i-1]);
    if(!eaten.length) return null;
    return {
      eaten,
      nextStart: i
    }
  };
  let output = [];
  let start = 0;
  while(true){
    let eaten = eatEm(start);
    console.log(eaten);
    if(!eaten) break;
    start = eaten.nextStart;
    if(eaten.eaten.length >= 3){
      let lowest = eaten.eaten[0];
      let highest = '';
      if(eaten.eaten.length > 1) highest = highest + '-' + eaten.eaten[eaten.eaten.length - 1];
      output.push(lowest + highest);
    }
    else eaten.eaten.forEach((number) => output.push(number));
  }
  return output.join(',');
}

// console.log(solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]));



