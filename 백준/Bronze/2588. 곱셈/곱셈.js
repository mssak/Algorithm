const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(/\s+/).map(Number);
let [a,b]=input;

let c=a*(b%10);
let d=a*((Math.floor(b/10))%10);
let e=a*(Math.floor((b/100))%10);

console.log(c);
console.log(d);
console.log(e);
console.log(c+d*10+e*100);