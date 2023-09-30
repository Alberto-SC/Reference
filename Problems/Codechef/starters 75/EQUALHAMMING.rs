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

fn mod_pow(a: &mut i64, b: &mut i64, md: i64) -> i64 {
    let mut x: i64 = 1;
    while *b > 0 {
        if *b & 1 == 1 {
            x *= *a;
            x %= md;
        }

        *a *= *a;
        *a %= md;
        b >>= 1;
    }
    return x;
}

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<usize>();

    let s = scan.token::<String>();
    let t = scan.token::<String>();
    let mut cont: i64 = 0;
    let mut diff: i64 = 0;
    for i in 0..n {
        if s.as_bytes()[i] == t.as_bytes()[i] {
            cont += 1;
        } else {
            diff += 1;
        }
    }
    let md = 1e9 + 7 as i64;
    if diff & 1 == 1 {
        writeln!(w, "0");
    } else {
        let mut ans: i64 = mod_pow(&mut 2 as i64, &mut cont, md);
        ans *= mod_pow(&mut 2 as i64, &mut diff / 2, md);
        ans %= md;
        writeln!(w, "{}", ans);
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
