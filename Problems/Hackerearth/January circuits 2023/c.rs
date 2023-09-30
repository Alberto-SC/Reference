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
    let mut k = scan.token::<i64>();
    let a: Vec<i64> = (0..n).map(|_| scan.token()).collect();
    let l: Vec<i64> = (0..n).map(|_| scan.token()).collect();
    let r: Vec<i64> = (0..n).map(|_| scan.token()).collect();

    let mut mn: Vec<i64> = vec![0; n];
    let mut mx: Vec<i64> = vec![0; n];

    for i in (0..n).rev() {
        mn[i] = min((a[i] - l[i]).abs(), (a[i] - r[i]).abs());
        if a[i] >= l[i] && a[i] <= r[i] {
            mn[i] = 0;
        }
        mx[i] = max((a[i] - l[i]).abs(), (a[i] - r[i]).abs());
        if i != n - 1 {
            mn[i] += mn[i + 1];
            mx[i] += mx[i + 1];
        }
    }
    let mut b: Vec<i64> = vec![0; n];

    // println!("{:?}", mn);
    // println!("{:?}", mx);

    if mx[0] < k || mn[0] > k {
        writeln!(w, "-1");
        return;
    }

    let mut best = |idx, c, k: &mut i64| {
        match l[idx] > a[idx] {
            true => b[idx] = a[idx] + c,
            false => {
                if a[idx] - c < l[idx] {
                    b[idx] = a[idx] + c;
                } else {
                    b[idx] = a[idx] - c;
                }
            }
        }
        *k -= c;
    };

    for i in (0..n) {
        let mut dist_l = (a[i] - l[i]).abs();

        // println!("{dist_l} {k}");
        if i == n - 1 {
            best(i, k, &mut k);
        } else {
            match mx[i + 1] >= (k - dist_l) && mn[i + 1] <= (k - dist_l) {
                true => best(i, dist_l, &mut k),
                false => {
                    if k - dist_l < mn[i + 1] {
                        best(i, dist_l - (mn[i + 1] - (k - dist_l)), &mut k);
                    } else {
                        best(i, k - mx[i + 1], &mut k);
                    }
                }
            }
        }
    }
    for i in 0..n {
        write!(w, "{} ", b[i]);
    }
    writeln!(w, "");
}

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
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
    solve(&mut scan, &mut out);
}
