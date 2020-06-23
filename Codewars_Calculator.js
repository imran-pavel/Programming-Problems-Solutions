/*

Create a simple calculator that given a string of operators
(), +, -, *, / and numbers separated by spaces returns the value of that
expression

Example:
Calculator().evaluate("2 / 2 + 3 * 4 - 6") # => 7


Remember about the order of operations!
Multiplications and divisions have a higher priority and should be performed
left-to-right. Additions and subtractions have a lower priority and
should also be performed left-to-right.

*/

let operatorPriorities = {
  '+': 0,
  '-': 0,
  '*': 1,
  '/': 1
};

let numberReg = /^\d+$|^\d+\.\d*$|^\d*\.\d+$/;

const Calculator = function() {
  
  let infix2PostFix = (expression) => {
    let stack = [];
    let postFix = [];
    expression.split(' ').forEach(content => {
      if(numberReg.test(content)){
        postFix.push(content);
        return;
      }
      if(!stack.length){
        stack.push(content);
        return;
      }
      if(content === '('){
        stack.push(content);
        return;
      }
      if(content === ')'){
        while(true){
          let lastElement = stack.pop();
          if(lastElement === '(') return;
          postFix.push(lastElement);
        }
      }
      while(stack.length && operatorPriorities[stack[stack.length-1]] >= operatorPriorities[content]){
        postFix.push(stack.pop());
      };
      stack.push(content);
    });
    while(stack.length){
      postFix.push(stack.pop());
    }
    return postFix;
  };
  
  this.evaluate = expression => {
    let postFixNotation = infix2PostFix(expression);
    let stack = [];

    postFixNotation.forEach(content => {
      if(content === ' ') return;
      if(numberReg.test(content)){
        stack.push(content);
        return;
      }
      let secondNumber = parseFloat(stack.pop(), 10);
      let firstNumber = parseFloat(stack.pop(), 10);
      
      switch(content){
        case '+':
          stack.push(firstNumber + secondNumber);
          break;
        case '-':
          stack.push(firstNumber - secondNumber);
          break;
        case '*':
          stack.push(firstNumber * secondNumber);
          break;
        default:
          stack.push(firstNumber / secondNumber);
          break;
      }
    });

    return stack[0];
  }
};

// console.log(new Calculator().evaluate("2 / 2 + 3 * 4 - 6"));
// console.log(new Calculator().evaluate("10 * 5 / 2"));
// console.log(new Calculator().evaluate("127"));