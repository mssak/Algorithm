const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(/\s+/).map(Number);
let [n,...ipt]=input;


ipt.sort((a,b)=>a-b);

let arr=Array(n).fill(0)
for(let i=0;i<n;i++){
  for(let j=1,ix=1;j<5;j++){
    if(ipt[i+ix]===ipt[i]+j){
      ix++;
    }
    else{
      arr[i]++;
    }
  }
}

res=arr.reduce((a,b)=>Math.min(a,b));
console.log(res);