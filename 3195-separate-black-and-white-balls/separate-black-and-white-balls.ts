function minimumSteps(s: string): number {
    let steps = 0;
    let zeroCount = 0;

    // Loop through the string once
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '0') {
            zeroCount++; 
        }
    }
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '1') {
            steps += zeroCount; 
        } else {
            zeroCount--; 
        }
    }

    return steps;
}
