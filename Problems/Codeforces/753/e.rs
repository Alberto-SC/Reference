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
    let mut m = scan.token::<usize>();
    let mut s = scan.token::<String>();

    let mut x_pos: Vec<i32> = vec![0; s.len() + 7];
    let mut x_neg: Vec<i32> = vec![0; s.len() + 7];
    let mut y_pos: Vec<i32> = vec![0; s.len() + 7];
    let mut y_neg: Vec<i32> = vec![0; s.len() + 7];
    let mut x: Vec<i32> = Vec::new();
    let mut y: Vec<i32> = Vec::new();

    for c in s.chars() {
        match c {
            'R' => y.push(1),
            'L' => y.push(-1i32),
            'U' => x.push(-1i32),
            'D' => x.push(1),
            _ => {}
        }
    }
    for i in 0..x.len() as usize {
        if i > 0 {
            x[i] += x[i - 1]
        }
        if x[i] < 0 {
            x_neg[x[i].abs() as usize] += 1
        } else {
            x_pos[x[i] as usize] += 1
        }
    }
    for i in 0..y.len() as usize {
        if i > 0 {
            y[i] += y[i - 1]
        }
        if y[i] < 0 {
            y_neg[y[i].abs() as usize] += 1
        } else {
            y_pos[y[i] as usize] += 1
        }
    }

    for i in ((0..=s.len()).rev()) {
        y_neg[i] += y_neg[i + 1];
        x_neg[i] += x_neg[i + 1];
        y_pos[i] += y_pos[i + 1];
        x_pos[i] += x_pos[i + 1];
    }

    let (mut a, mut b, mut mnx, mut mny) = (0i32, 0i32, s.len() as i32 + 1, s.len() as i32 + 1);
    println!("{:?}", x);
    println!("{:?}", y);
    println!("{:?}", x_pos);
    println!("{:?}", x_neg);

    for i in 0..n {
        let nw: i32 = x_pos[n - i] + x_neg[i + 1];
        println!("{nw} {i} {mnx}");
        if nw < mnx {
            a = i as i32;
            mnx = nw;
        }
    }

    for i in 0..m {
        let nw: i32 = y_pos[m - i] + y_neg[i + 1];
        if nw < mny {
            b = i as i32;
            mny = nw;
        }
    }
    writeln!(w, "{} {}", a + 1, b + 1);
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
