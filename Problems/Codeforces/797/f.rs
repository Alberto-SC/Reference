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

fn gcd(a: i64, b: i64) -> i64 {
    if a == 0 {
        return b;
    }
    return gcd(b % a, a);
}

fn lcm(a: i64, b: i64) -> i64 {
    let x = a * b / gcd(a, b);
    return x;
}

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<usize>();
    let s = scan.token::<String>();
    let mut v: Vec<char> = s.chars().collect::<Vec<_>>();
    let mut nums: Vec<i32> = (0..n).map(|_| scan.token::<i32>() - 1).collect();

    let mut lm = 1i64;

    let mut vis = vec![false; n];
    for i in 0..n {
        if vis[i] {
            continue;
        }
        let mut u: usize = i;
        let mut len = 0;
        let mut nws: Vec<char> = vec![];
        while !vis[u] {
            len += 1;
            vis[u] = true;
            nws.push(v[u]);
            u = nums[u] as usize;
        }
        let mut min_shift = 0;

        for j in 1..=nws.len() {
            let mut flag = true;
            for k in 0..nws.len() {
                if nws[k] != nws[(k + j) % nws.len()] {
                    flag = false;
                    break;
                }
            }
            if flag {
                min_shift = j;
                break;
            }
        }
        lm = lcm(lm, min_shift as i64);
    }
    writeln!(w, "{lm}");
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
