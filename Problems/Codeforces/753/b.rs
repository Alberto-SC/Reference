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
    let mut x = scan.token::<i64>();
    let mut n = scan.token::<i64>();
    if n == 0 {
        writeln!(w, "{x}");
        return;
    }
    if x & 1 > 0 {
        x += 1;
        n -= 1;
        let mut z: i64 = n / 4;
        x -= z * -4;

        if n % 4 == 1 {
            x -= n + 1
        }
        if n % 4 == 2 {
            x -= n + 1;
            x -= n;
        }
        if n % 4 == 3 {
            x += n + 1;
            x -= n;
            x -= n - 1;
        }

        writeln!(w, "{x}");
    } else {
        x -= 1;
        n -= 1;
        let mut z: i64 = n / 4;
        x += z * -4;
        if n % 4 == 1 {
            x += n + 1
        }
        if n % 4 == 2 {
            x += n + 1;
            x += n;
        }
        if n % 4 == 3 {
            x -= n + 1;
            x += n;
            x += n - 1;
        }
        writeln!(w, "{x}");
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
