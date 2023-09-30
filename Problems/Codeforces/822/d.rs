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
    let mut k = scan.token::<usize>();
    k -= 1;
    let v: Vec<i32> = (0..n).map(|_| scan.token()).collect();

    if k == 0 || k == n - 1 {
        writeln!(w, "YES");
        return;
    }

    let mut sum = v[k];
    let mut l = k - 1;
    let mut r = k + 1;
    let mut flag = false;

    loop {
        let mut nw_r = r;
        let mut s = 0;
        let mut mx = -1;
        let mut mx_id_r = r;
        while nw_r < n {
            s += v[nw_r];
            if s + sum < 0 {
                break;
            }
            if s > mx {
                mx = s;
                mx_id_r = nw_r;
            }
            nw_r += 1;
        }
        if nw_r == n {
            flag = true;
            break;
        }
        if mx == -1 {
            mx = 0;
        }
        sum += mx;

        let mut nw_l = l as i32;
        let mut mx_id_l = l;
        s = 0;
        mx = -1;
        while nw_l >= 0 {
            s += v[nw_l as usize];
            if s + sum < 0 {
                break;
            }
            if s > mx {
                mx = s;
                mx_id_l = nw_l as usize;
            }
            nw_l -= 1;
        }
        if nw_l == -1 {
            flag = true;
            break;
        }
        if mx == -1 {
            mx = 0;
        }
        sum += mx;

        if mx_id_l == l && mx_id_r == r {
            break;
        }
        l = mx_id_l - 1;
        r = mx_id_r + 1;
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
