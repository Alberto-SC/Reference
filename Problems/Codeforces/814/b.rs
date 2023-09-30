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
    let mut k = scan.token::<usize>();

    let mut a: Vec<usize> = vec![];
    let mut b: Vec<usize> = vec![];
    let mut c: Vec<usize> = vec![];
    let mut d: Vec<usize> = vec![];
    let mut e: Vec<usize> = vec![];
    let mut ans: Vec<(usize, usize)> = vec![(0, 0); n / 2];
    for i in 1..=n {
        if (i + k) % 4 == 0 {
            a.push(i);
        } else if i % 4 == 0 {
            b.push(i);
        } else if (i + k) % 4 == 2 {
            c.push(i);
        } else if i % 4 == 2 {
            d.push(i);
        } else {
            e.push(i);
        }
    }

    let mut flag = true;

    // println!("{:?}", a);
    // println!("{:?}", b);
    // println!("{:?}", c);
    // println!("{:?}", d);
    // println!("{:?}", e);

    if a.len() + b.len() + min(c.len(), d.len()) < n / 2 {
        flag = false;
    } else {
        let mut idx = 0;
        let mut idxa = 0;
        let mut idxb = 0;
        for i in 0..min(c.len(), d.len()) {
            ans[idx].0 = c[i];
            ans[idx].1 = d[i];
            idx += 1;
        }

        for i in min(c.len(), d.len())..c.len() {
            e.push(c[i]);
        }
        for i in min(c.len(), d.len())..d.len() {
            e.push(d[i]);
        }

        for i in 0..a.len() {
            if idx == n / 2 {
                break;
            }
            ans[idx].0 = a[i];
            idx += 1;
            idxa += 1;
        }
        for i in 0..b.len() {
            if idx == n / 2 {
                break;
            }
            ans[idx].1 = b[i];
            idx += 1;
            idxb += 1;
        }

        idx = 0;
        // println!("{:?}", ans);

        while idxa < a.len() {
            while ans[idx].0 != 0 && ans[idx].1 != 0 {
                idx += 1;
            }
            if ans[idx].0 == 0 {
                ans[idx].0 = a[idxa];
            } else {
                ans[idx].1 = a[idxa];
            }
            idxa += 1;
            idx += 1;
        }
        while idxb < b.len() {
            while ans[idx].0 != 0 && ans[idx].1 != 0 {
                idx += 1;
            }
            if ans[idx].0 == 0 {
                ans[idx].0 = b[idxb];
            } else {
                ans[idx].1 = b[idxb];
            }
            idxb += 1;
            idx += 1;
        }

        for i in 0..e.len() {
            while ans[idx].0 != 0 && ans[idx].1 != 0 {
                idx += 1;
            }
            if ans[idx].0 == 0 {
                ans[idx].0 = e[i];
            } else {
                ans[idx].1 = e[i];
            }
            idx += 1;
        }
    }

    if flag {
        writeln!(w, "YES");
        for a_i in ans {
            writeln!(w, "{} {}", a_i.0, a_i.1);
        }
    } else {
        writeln!(w, "NO");
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
