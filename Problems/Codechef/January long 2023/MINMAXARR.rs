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

fn check(x: i32, mut v: Vec<i32>) -> bool {
    let n = v.len();

    if v[0] > x {
        return false;
    }
    let mut ac: i64 = (x - v[0]) as i64;
    for i in 1..n {
        let mx: i64 = min(ac, v[i] as i64);
        ac -= mx;
        v[i] -= mx as i32;

        if v[i] > x {
            return false;
        }
        ac += (x - v[i]) as i64;
    }
    return true;
}

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<usize>();
    let mut v: Vec<i32> = (0..n).map(|_| scan.token()).collect();

    let (mut l, mut r) = (-1i32, 1e9 as i32);

    while (l + 1 < r) {
        let mut m = (l + r) >> 1;
        if check(m, v.clone()) {
            r = m
        } else {
            l = m
        }
    }
    writeln!(w, "{}", r);
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
