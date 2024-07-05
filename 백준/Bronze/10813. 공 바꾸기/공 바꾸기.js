const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n,m]=input[0].split(' ').map(Number);
let arr = new Array(n+1)

for(let i=1;i<=n;i++){
    arr[i]=i;
}

for(let ix=0+1;ix<m+1;ix++){
    let [i,j] = input[ix].split(' ').map(Number);
    tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

ans="";

for(let i=1;i<=n;i++){
    ans+=arr[i]+" ";
}

console.log(ans);