fn add(idx: &mut i32, val: usize, ft: &mut Vec<usize>, mxn: usize) {
    while *idx < mxn as i32 {
        ft[*idx as usize] += val;
        *idx = *idx | (*idx + 1);
    }
}

fn sum(idx: &mut i32, ft: &mut Vec<usize>) -> i32 {
    let mut res = 0;
    while *idx >= 0 {
        res += ft[*idx as usize] as i32;
        // println!("{:06b}", idx);
        *idx = (*idx & (*idx + 1)) - 1;
    }
    return res;
}
