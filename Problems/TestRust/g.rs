#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_imports)]
use std::cmp::{max, min, Reverse};
use std::collections::HashSet;
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

fn dfs(u: i32, p: i32, x: i32, b: i32, g: &Vec<Vec<(i32, i32, i32)>>, st: &mut HashSet<i32>) {
    for v in &g[u as usize] {
        if v.0 == p || v.0 == b {
            continue;
        }
        let nwx = x ^ v.1;
        st.insert(nwx);
        dfs(v.0, u, nwx, b, &g, st);
    }
}

fn solve_case<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut n = scan.token::<i32>();
    let mut a = scan.token::<i32>();
    let mut b = scan.token::<i32>();

    let mut graph = vec![vec![]; n as usize];
    // graph.resize(n as usize, Vec::<(i32, i32)>::new());

    for i in 0..n - 1 {
        let mut u = scan.token::<i32>();
        let mut v = scan.token::<i32>();
        let mut w = scan.token::<i32>();
        u -= 1;
        v -= 1;
        graph[u as usize].push((v, w));
        graph[v as usize].push((u, w));
    }
    a -= 1;
    b -= 1;
    let mut st1 = HashSet::<i32>::new();
    let mut st2 = HashSet::<i32>::new();
    dfs(a, -1i32, 0, b, &graph, &mut st1);
    dfs(b, -1i32, 0, -1, &graph, &mut st2);

    if (st2.contains(&0)) {
        writeln!(w, "YES");
        return;
    } else {
        for el in &st1 {
            if (st2.contains(el)) {
                writeln!(w, "YES");
                return;
            }
        }
    }
    writeln!(w, "NO");
}

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let mut t = scan.token::<i32>();
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
