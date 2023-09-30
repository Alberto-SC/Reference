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
    let mut v: Vec<i32> = (0..n).map(|_| scan.token()).collect();
    let mut s = scan.token::<String>();

    let (mut blue, mut red): (Vec<(i32, char)>, Vec<(i32, char)>) = s
        .chars()
        .enumerate()
        .map(|(id, c)| (v[id], c))
        .partition(|(val, c)| *c == 'B');

    blue.sort();
    blue.reverse();
    red.sort();

    let mut flag = true;

    for i in 1..=blue.len() as i32 {
        if blue.last().unwrap().0 < i {
            flag = false;
        } else {
            blue.pop();
        }
    }

    for i in 0..red.len() as i32 {
        if red.last().unwrap().0 > n as i32 - i {
            flag = false;
        } else {
            red.pop();
        }
    }

    if flag {
        writeln!(w, "YES");
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
