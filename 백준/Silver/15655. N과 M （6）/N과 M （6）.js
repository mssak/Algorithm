const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n,m]=input[0].split(' ').map(Number);
let arr=input[1].split(' ').map(Number);
arr.sort((a, b) => a - b);
let res=[];
let ans=[];

function f(bef){
    if(res.length===m){
        ans.push(res.join(' '));
        return;
    }
    else{
        for(let i=bef;i<n;i++){
            if(i<n){
                res.push(arr[i]);
                f(i+1);
                res.pop();
            }
        }
    }
}

f(0);
console.log(ans.join('\n'));