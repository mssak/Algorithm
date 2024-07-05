const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [n,x]=input[0].split(' ').map(Number);
let arr=input[1].split(' ').map(Number);
for(let i=0;i<n;i++){
    if(arr[i]<x){
        process.stdout.write(arr[i]+" ");
    }
}
