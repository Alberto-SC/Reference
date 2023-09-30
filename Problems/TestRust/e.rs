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
    let n = scan.token::<i64>();
    let v: Vec<i64> = (0..n).map(|_| scan.token()).collect();

    let mut ac: Vec<i64> = vec![0; n as usize];
    let sum: i64 = v.iter().sum();

    let mut total: i64 = 0;

    for i in 0..n as usize {
        if i > 0 {
            ac[i] = ac[i - 1] + v[i];
        } else {
            ac[i] = v[i];
        }
        if v[i] == 0 {
            total += ac[i];
        }
    }
    let mut ans: i64 = total;
    for i in 0..n as usize {
        if v[i] == 0 {
            let left: i64 = if i > 0 { ac[i - 1] } else { 0 };
            let right: i64 = (n - (i as i64 + 1)) - (sum - ac[i]);
            ans = max(ans, total - left + right);
        } else {
            let left: i64 = if i > 0 { ac[i - 1] } else { 0 };
            let right: i64 = (n - (i as i64 + 1)) - (sum - ac[i]);
            ans = max(ans, total + left - right);
        }
    }
    writeln!(w, "{}", ans);
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
