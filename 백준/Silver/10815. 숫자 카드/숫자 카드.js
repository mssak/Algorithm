const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let st=new Set();
for(let i of input[1].split(' ')){
    st.add(i);
}
ans='';
for(let i of input[3].split(' ')){
    if(st.has(i)){
        ans+="1 ";
    }
    else{
        ans+="0 ";
    }
}
console.log(ans);