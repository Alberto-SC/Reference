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
    let n = scan.token::<usize>();
    let nums: Vec<i32> = (0..n).map(|_| scan.token()).collect();

    let mut cont = 0;
    let (mut i, mut j) = (0usize, 0usize);
    while i < n {
        j = i;
        while j < n && nums[i] == nums[j] {
            j += 1;
        }

        if i == 0 && j == n {
            cont += 1;
        } else if i > 0 && nums[i - 1] > nums[i] && j == n {
            cont += 1;
        } else if i == 0 && j < n && nums[j] > nums[j - 1] {
            cont += 1;
        } else if i > 0 && j < n && nums[i - 1] > nums[i] && nums[j] > nums[j - 1] {
            cont += 1;
        }

        i = j;
    }
    if cont > 1 {
        writeln!(w, "NO");
    } else {
        writeln!(w, "YES");
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
