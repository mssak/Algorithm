const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let n=Number(input[0]);
let arr=[];
let ans=[];
for(let i=0;i<n;i++){
    let nw=input[i+1][0];
    if(nw==='1'){
        let [a,b]=input[i+1].split(' ').map(Number);
        arr.push(b);
    }
    else if(nw==='2'){
        ans.push(arr.pop()??-1);
    }else if(nw==='3'){
        ans.push(arr.length);
    }else if(nw==='4'){
        ans.push(arr.length?0:1);
    }else if(nw==='5'){
        ans.push(arr.length?arr.at(-1):-1);
    }
}

console.log(ans.join('\n'));