#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_imports)]
use std::cmp::{max, min, Reverse};
use std::collections::{BTreeMap, HashMap, HashSet};
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
    let s = scan.token::<String>();

    let mut divs = vec![];

    for i in 1..n {
        if i * i > n {
            break;
        }
        if n % i == 0 {
            divs.push(i);
            if n / i != i {
                divs.push(n / i);
            }
        }
    }

    let mut map = BTreeMap::<char, i32>::new();

    for c in s.chars() {
        *map.entry(c).or_insert(0) += 1;
    }

    for d in &divs {
        let mut l: Vec<i32> = vec![];
        let mut r: Vec<i32> = vec![];
        let need = n / d;
        for (c, count) in &map {
            if count == n / d {
                continue;
            }
            if count > n / d {
                r.push(count);
            } else {
                l.push(count);
            }
            println!("{c} -> {count}");
        }
        l.sort();
        r.sort();

        let idxr: usize = 0;
        while idxr < r.len() {
            let mx = r[idxr] - need;

            let x = min(mx, need - l[l.len() - 1]);
            r[idxr] -= x;
            l[l.len() - 1] += x;
            if l[l.len() - 1] == need {
                l.pop();
            }
            if r[idxr] == need {
                idxr += 1;
            }
        }
    }

    println!("{:?}", map);
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
