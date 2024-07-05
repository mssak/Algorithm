const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n,m]=input[0].split(' ').map(Number);

let arr = Array;
for(let i=1;i<=n;i++){
    arr[i]=i;
}

function sw(a,b){

}

for(let ix=1;ix<=m;ix++){
    let [i,j]=input[ix].split(' ').map(Number);
    while(i<j){
        [arr[i],arr[j]]=[arr[j],arr[i]];
        i++;
        j--;
    }
}

let ans=""
for(let i=1;i<=n;i++){
    ans+=arr[i]+" ";
}

console.log(ans);