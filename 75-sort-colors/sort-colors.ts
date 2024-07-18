/**
 Do not return anything, modify nums in-place instead.
 */
const sortC=(nums:number[],zero:number,one:number)=>{
    let i=0;
    let two=nums.length - one - zero;
    while(zero--){nums[i]=0;i++;}
    while(one--){nums[i]=1;i++;}
    while(two--){nums[i]=2;i++;}
}

function sortColors(nums: number[]): void {
    let one:number=0;
    let zero:number=0;
    for(let i:number=0;i<nums.length;i++){
        if(nums[i]==0)zero++;
        if(nums[i]==1)one++;
    }
    sortC(nums,zero,one);
};