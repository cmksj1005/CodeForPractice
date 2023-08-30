var readline = require('readline');

var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question('Enter Your Name: ', function (answer) {
  console.log('Hi ' + answer);
  rl.close();
});
