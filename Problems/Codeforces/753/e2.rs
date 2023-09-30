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

    let mut matrix = vec![vec!['a'; m]; n];

    for i in 0..n {
        let s = scan.token::<String>();
        matrix[i] = s.chars().collect::<Vec<_>>();
    }

    let mut dp = vec![vec![0; m]; n];
    let mut ans = (0, 0, 0);
    for x0 in 0..n {
        for y0 in 0..m {
            let (mut x, mut y, mut z) = (x0, y0, 0);
            let mut v = vec![];
            loop {
                if dp[x][y] > 0 {
                    z = dp[x][y];
                    break;
                } else if dp[x][y] == -1 {
                    let pos = v.iter().position(|i| i == &(x, y)).unwrap();
                    z = (v.len() - pos) as i32;
                    for &(i, j) in &v[pos..] {
                        dp[i][j] = z;
                    }
                    v.truncate(pos);
                    break;
                }
                dp[x][y] = -1;
                v.push((x, y));
                match matrix[x][y] {
                    'U' if x > 0 => x -= 1,
                    'D' if x < n - 1 => x += 1,
                    'L' if y > 0 => y -= 1,
                    'R' if y < m - 1 => y += 1,
                    _ => {}
                }
            }

            z += 1;
            for (i, j) in v.into_iter().rev() {
                dp[i][j] = z;
                z += 1;
            }
            ans = max(ans, (dp[x0][y0], x0, y0));
        }
    }
    writeln!(w, "{} {} {}", ans.1 + 1, ans.2 + 1, ans.0);
}

fn run<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
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
    run(&mut scan, &mut out);
}
