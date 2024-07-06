const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);

let arr=[];
for(let i of input.slice(1)){
    if(i===0){
        arr.pop();
    }
    else{
        arr.push(i);
    }
}

console.log(arr.reduce((a,b)=>a+b,0));