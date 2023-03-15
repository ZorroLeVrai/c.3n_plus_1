function transform(previous: number) {
  //if previous is an odd number
  if (previous & 1)
    return 3 * previous + 1;

  //divide previous by 2
  return previous >> 1;
}

function getSeries(num: number) {
  const result: number[] = []
  result.push(num);
  while(num != 1) {
    num = transform(num);
    result.push(num);
  }

  return result;
}

//called even if the list is properly formatted by JavaScript
function seriesToString(nums: number[]) {
  return `[${nums.join(', ')}]`;
}

const nums = getSeries(1025);
console.log(seriesToString(nums));