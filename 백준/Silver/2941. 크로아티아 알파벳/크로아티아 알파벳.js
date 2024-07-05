const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();

function f(s){
    while(input.indexOf(s)!==-1){
        input=input.slice(0,input.indexOf(s))+'a'+input.slice(input.indexOf(s)+s.length);
    }
}

f("dz=");
f("c=");
f("c-");
f("d-");
f("lj");
f("nj");
f("s=");
f("z=");

console.log(input.length);