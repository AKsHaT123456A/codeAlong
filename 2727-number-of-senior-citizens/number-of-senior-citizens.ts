function countSeniors(details: string[]): number {
    let cnt:number=0;
for (let i: number = 0; i < details.length; i++) { 
    let st: string = details[i].substring(11, 13);
    console.log(st)
    if(st>'60')cnt++;
}
return cnt;
};