const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [n,m]=input[0].split(' ').map(Number);

let arr=[];

for(let i=1;i<=n;i++){
    arr[i-1]=input[i].split(' ').map(Number);
}

for(let i=0;i<n;i++){
    for(let j=0;j<m;j++){
        arr[i][j]+=(input[i+n+1].split(' ').map(Number))[j];
    }
}

ans ="";
for(let i=0;i<n;i++){
    for(let j=0;j<m;j++){
        ans+=arr[i][j]+" ";
    }
    ans+="\n";
}

console.log(ans);