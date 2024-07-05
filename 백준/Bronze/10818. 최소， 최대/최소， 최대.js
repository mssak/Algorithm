const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let n=input[0].split(' ').map(Number);
let arr=input[1].split(' ').map(Number);

console.log(arr.reduce((a,b)=>Math.min(a,b),Infinity),arr.reduce((a,b)=>Math.max(a,b),-Infinity));