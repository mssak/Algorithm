const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let ans=[];
for(let i='a'.charCodeAt(0);i<='z'.charCodeAt(0);i++){
    let idx=-1;
    for(let j=0;j<input[0].length;j++){
        if(i===input[0].charCodeAt(j)){
            idx=j;
            break;
        }
    }
    ans.push(idx);
}

console.log(ans.join(" "));
