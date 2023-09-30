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
    let mut q = scan.token::<usize>();
    let v: Vec<usize> = (0..n).map(|_| scan.token()).collect();

    let mut wins: Vec<Vec<usize>> = vec![vec![]; n + 1];
    let mut last = v[0];

    for i in 1..n {
        if last > v[i] {
            wins[last].push(i);
        } else {
            wins[v[i]].push(i);
            last = v[i];
        }
    }

    // println!("{:?}", wins);
    for _ in 0..q {
        let mut idx = scan.token::<usize>();
        idx -= 1;
        idx = v[idx];
        let mut k = scan.token::<usize>();
        let mut l: i32 = -1;
        let mut r: i32 = wins[idx].len() as i32;

        while l + 1 < r {
            let mut m: i32 = (l + r) >> 1;
            if wins[idx][m as usize] > k {
                r = m;
            } else {
                l = m;
            }
        }

        if idx == n && k > n - 1 {
            writeln!(w, "{}", k - (n - 1) + r as usize);
        } else {
            writeln!(w, "{}", r);
        }
    }
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
