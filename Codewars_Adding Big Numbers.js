/*

We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers.
The input numbers are strings and the function must return a string.

Example
add("123", "321"); -> "444"
add("11", "99");   -> "110"

Notes
The input numbers are big.
The input is a string of only digits
The numbers are positives

*/


function add(a, b) {
  let i = 1;
  let carry = 0;
  let result = '';

  while((a.length - i) > -1 && (b.length - i) > -1){
    let sum = parseInt(a.charAt(a.length - i)) + parseInt(b.charAt(b.length - i)) + carry;
    carry = Math.trunc(sum / 10);
    result = ('' + sum % 10) + result;
    i++;
  }

  while(a.length - i > -1){
    let sum = parseInt(a.charAt(a.length - i)) + carry;
    carry = Math.trunc(sum / 10);
    result = ('' + sum % 10) + result;
    i++;
  }

  while(b.length - i > -1){
    let sum = parseInt(b.charAt(b.length - i)) + carry;
    carry = Math.trunc(sum / 10);
    result = ('' + sum % 10) + result;
    i++;
  }
  if(carry) result = '' + carry + result;
  return result;
}


// console.log(add("19", "1"));