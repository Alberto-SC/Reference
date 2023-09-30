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
    let mut w = scan.token::<i32>();
    let mut d = scan.token::<i32>();
    let mut h = scan.token::<i32>();
    let mut a = scan.token::<i32>();
    let mut b = scan.token::<i32>();
    let mut f = scan.token::<i32>();
    let mut g = scan.token::<i32>();

    let mut ans1 = 0;
    let mut ans2 = 0;
    let mut ans3 = 0;
    let mut ans4 = 0;

    ans1 = (a - f).abs() + h + b + g;
    ans2 = (a - f).abs() + h + (d - b) + (d - g);
    ans3 = (b - g).abs() + h + a + f;
    ans4 = (b - g).abs() + h + (w - a) + (w - f);

    let ans: i32 = min(ans1, min(ans2, min(ans3, ans4)));

    println!("{ans}");
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
