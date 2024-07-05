const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let arr=[];
let mx=-1;
for(let i=0;i<input.length;i++){
    arr[i]=input[i].split('');
    mx=Math.max(mx,arr[i].length);
}

let ans='';
for(let i=0;i<mx;i++){
    for(let j=0;j<input.length;j++){
        if(arr[j][i]!==undefined){
            ans+=arr[j][i];
        }
    }
}

console.log(ans);