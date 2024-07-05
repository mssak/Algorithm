const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

let [a,b]=input;
let ra=a.split('');
ra.reverse();
a=ra.join('');
let rb=b.split('');
rb.reverse();
b=rb.join('');

console.log(Math.max(a,b));