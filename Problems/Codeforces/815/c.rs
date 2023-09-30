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
    let v: Vec<String> = (0..n).map(|_| scan.token()).collect();

    let mut zero = false;
    let mut flag = false;
    let mut cont = 0;

    for i in 0..n {
        for j in 0..m {
            if v[i].as_bytes()[j] == '1' as u8 {
                cont += 1;
            } else {
                zero = true;
            }

            let mut sum = 0;
            if i + 1 < n && j + 1 < m {
                sum += v[i].as_bytes()[j] - '0' as u8;
                sum += v[i].as_bytes()[j + 1] - '0' as u8;
                sum += v[i + 1].as_bytes()[j] - '0' as u8;
                sum += v[i + 1].as_bytes()[j + 1] - '0' as u8;
                if sum <= 2 {
                    flag = true;
                }
            }
        }
    }

    if flag {
        writeln!(w, "{}", cont);
    } else if zero {
        writeln!(w, "{}", cont - 1);
    } else {
        writeln!(w, "{}", cont - 2);
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