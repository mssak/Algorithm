const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
let ans="";

let mx=-Infinity,mxi=-1;
for(let i=0;i<9;i++){
    if(mx<input[i]){
        mx=input[i];
        mxi=i;
    }
}

console.log(mx);
console.log(mxi+1);