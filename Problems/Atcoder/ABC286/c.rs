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

pub fn rotate(str: &str) -> String {
    let mut str_vec: Vec<char> = str.chars().collect();
    str_vec.rotate_left(1);
    str_vec.iter().collect()
}

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<usize>();
    let mut a = scan.token::<i64>();
    let mut b = scan.token::<i64>();
    let mut s = scan.token::<String>();

    let mut ans: i64 = (b * n as i64) + (a * n as i64);
    
    for i in 0..n{
        let mut res: i64 = 0;
        for j in 0..n/2{
            if s.as_bytes()[j] != s.as_bytes()[n-1-j]{
                res+=1;
            }
        }
        ans = min(ans,(i as i64)* a) +(res*b);
    }

    for i in 0..n {
        let mut res: i64 = 0;
        for j in 0..n / 2 {
            if s.as_bytes()[j] != s.as_bytes()[n - 1 - j] {
                res += 1;

            }
        }
        ans = min(ans, (i as i64 * a) + (res * b));
        s = rotate(&mut s);
    }

    writeln!(w, "{}", ans);
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
