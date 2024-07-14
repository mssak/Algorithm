const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(/\s+/).map(Number);
let [n,...ipt]=input;


ipt.sort((a,b)=>a-b);

let mn=5;
for(let i=0;i<n;i++){
  let tmp=0;
  for(let j=1,ix=1;j<5;j++){
    if(ipt[i+ix]===ipt[i]+j){
      ix++;
    }
    else{
      tmp++;
    }
  }
  mn=Math.min(mn,tmp);
}

console.log(mn);