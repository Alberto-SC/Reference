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

// fn check(k: i64, v: &mut Vec<i64> ,c: i64,d:i64)-> bool{
//     let mut wait = BTreeSet<(i64,i64)>::new();
//     let mut available = BTreeSet<i64>::new();
//     let n = v.len();

//     for i in 0..n as usize{
//         available.insert(v[i]);
//     }
//     let mut sum:i64 = 0;
//     for i in 0..d{
//         if available.len()>=1{
//             let x = set.pop_last();
//             sum+=x;
//             wait.insert((i as i32,x));
//         }

//         if i - k>=0{
//             while 1 {
//                 let x= set.first;
//                 if x.0 == i-k {
//                     st.pop_first;
//                     available.insert(x);
//                 }
//                 else {break}

//             }
//         }

//     }
//     sum >=c
// }

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<i64>();
    let mut c = scan.token::<i64>();
    let mut d = scan.token::<i64>();

    let mut v: Vec<i64> = (0..n).map(|_| scan.token()).collect();

    v.sort();
    v.reverse();
    let mut ac: Vec<i64> = vec![v[0]; n as usize];

    for i in 1..n as usize {
        ac[i] = ac[i - 1] + v[i]
    }

    let (mut l, mut r) = (-1i64, 1e18 as i64);
    while l + 1 < r {
        let mut m: i64 = (l + r) >> 1;

        let mut x = d / (m + 1);
        let mut s = x * ac[min(m, n - 1) as usize];
        let mut md = d % (m + 1);
        if md > 0 {
            s += ac[min(n - 1, md - 1) as usize]
        }
        // println!("{m} {s} {md} ");
        if s >= c {
            l = m;
        } else {
            r = m;
        }
    }
    if l == -1 {
        writeln!(w, "Impossible");
        return;
    } else if l == 1e18 as i64 - 1 {
        writeln!(w, "Infinity");
    } else {
        writeln!(w, "{}", l);
    }
}

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut t = scan.token::<usize>();
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
