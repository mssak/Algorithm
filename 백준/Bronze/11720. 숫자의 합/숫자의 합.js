const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let ans = BigInt('0');

for(let i=0;i<Number(input[0]);i++){
    ans+=BigInt(input[1][i]);
}

console.log(ans.toString());