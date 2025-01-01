class CQueue {
  private items: number[];

  constructor() {
    this.items = [];
  }
  e(element: number): void {
    this.items.push(element);
  }
  d(): number | undefined {
    return this.items.shift();
  }
  s(): number {
    return this.items.length;
  }
  f(): number | undefined {
    return this.items[0];
  }
}

function findTheWinner(n: number, k: number): number {
  let q = new CQueue();
  for (let i = 1; i <= n; i++) {
    q.e(i);
  }
  while (q.s() > 1) {
    let x = k - 1; 
    while (x-- > 0) {
      const front = q.f();
      q.d();
      if (front !== undefined) q.e(front);
    }
    q.d();
  }

  return q.f() as number;
}
