#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_imports)]
use std::cmp::{max, min, Reverse};
use std::collections::{HashMap, HashSet};
use std::io::{self, prelude::*};
use std::str;

struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}
impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_whitespace(),
        }
    }
    fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_whitespace())
            }
        }
    }
}

fn solve(
    idx: usize,
    sum: usize,
    dp: &mut Vec<Vec<usize>>,
    n: usize,
    a: &Vec<usize>,
    b: &Vec<usize>,
    x: usize,
) -> usize {
    if sum > x {
        return 0;
    }
    if sum == x {
        return 1;
    }
    if idx == n {
        return 0;
    }

    if dp[idx][sum] != 1e9 as usize {
        return dp[idx][sum];
    }

    let mut ans = 0;

    for i in 0..=b[idx] {
        ans += solve(idx + 1, sum + (i * a[idx]), dp, n, a, b, x);
    }

    if ans > 0 {
        dp[idx][sum] = 1;
        return dp[idx][sum];
    }
    dp[idx][sum] = 0;
    return dp[idx][sum];
}

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<usize>();
    let mut x = scan.token::<usize>();
    let mut a: Vec<usize> = vec![0; n];
    let mut b: Vec<usize> = vec![0; n];
    for i in 0..n {
        a[i] = scan.token::<usize>();
        b[i] = scan.token::<usize>();
    }

    let mut dp: Vec<Vec<usize>> = vec![vec![1e9 as usize; 10007]; n];

    let ans = solve(0, 0, &mut dp, n, &a, &b, x);
    if ans == 1 {
        writeln!(w, "Yes");
    } else {
        writeln!(w, "No");
    }
}

fn run<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    // let mut t = scan.token::<usize>();
    let mut t = 1;
    while t > 0 {
        solve_case(scan, w);
        t -= 1;
    }
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());
    run(&mut scan, &mut out);
}
