const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let arr=[];
let n=Number(input[0]);
for(let i=0;i<n;i++){
    let[a,b]=input[i+1].split(' ');
    arr[i]=[Number(a),b,i];
}

arr.sort((a,b)=>{
    if(a[0]===b[0]){
        return a[2]=b[2];
    }
    else{
        return a[0]-b[0];
    }
})

arr=arr.map(a=>a.slice(0,2));
console.log(arr.map(a=>a.join(' ')).join('\n'));