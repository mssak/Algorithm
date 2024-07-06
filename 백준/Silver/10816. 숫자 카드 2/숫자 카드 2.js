const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let mp=new Map();
for(let i of input[1].split(' ')){
    if(mp.has(i)){
        mp.set(i,mp.get(i)+1);
    }
    else{
        mp.set(i,1);
    }
}

let ans="";
for(let i of input[3].split(' ')){
    if(mp.has(i)){
        ans+=mp.get(i)+" ";
    }
    else{
        ans+="0 ";
    }
}
console.log(ans);