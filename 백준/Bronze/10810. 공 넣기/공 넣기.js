const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n,m]=input[0].split(' ').map(Number);
let arr = new Array(n).fill(0);


for(let ix=1;ix<=m;ix++){
    let [i,j,k]=input[ix].split(' ').map(Number);
    arr.fill(k,i-1,j);
}

let ans='';
for(let i=0;i<arr.length;i++){
    ans+=arr[i]+" ";
}

console.log(ans);