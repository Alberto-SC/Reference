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

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<usize>();
    let mut k = scan.token::<i32>();
    let nums: Vec<i32> = (0..n).map(|_| scan.token()).collect();

    let mut v = vec![vec![]; k as usize];

    for i in 0..n {
        v[(nums[i] % k) as usize].push(nums[i]);
    }

    // println!("{:?}", v);
    let mut rem = vec![];
    let mut ans = 0;
    for i in 0..=((k / 2) as usize) {
        if (k % 2 == 0 && i == (k / 2) as usize) || i == 0 {
            for j in (0..v[i].len()).step_by(2) {
                if j + 1 < v[i].len() {
                    ans += (v[i][j] + v[i][j + 1]) / k;
                }
            }
            if v[i].len() & 1 == 1 {
                rem.push(v[i].last().unwrap());
            }
        } else {
            let z = k as usize - i;
            v[i].sort();
            v[i].reverse();
            v[z].sort();
            v[z].reverse();
            for j in 0..min(v[i].len(), v[z].len()) {
                ans += (v[i][j] + v[z][j]) / k;
            }

            for j in min(v[i].len(), v[z].len())..v[i].len() {
                rem.push(&v[i][j]);
            }
            for j in min(v[i].len(), v[z].len())..v[z].len() {
                rem.push(&v[z][j]);
            }
        }
    }
    // println!("{:?}", rem);
    // rem.sort_by(|a, b| (*b % k).cmp(&(*a % k)));
    rem.sort();
    for i in (0..rem.len()).step_by(2) {
        ans += (rem[i] + rem[i + 1]) / k;
    }
    writeln!(w, "{ans}");
}

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut t = scan.token::<usize>();
    // let mut t = 1;
    while t > 0 {
        solve_case(scan, w);
        t -= 1;
    }
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());
    solve(&mut scan, &mut out);
}
