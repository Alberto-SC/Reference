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
    let a: Vec<i32> = (0..n).map(|_| scan.token()).collect();
    let b: Vec<i32> = (0..n).map(|_| scan.token()).collect();

    let mut mp: BTreeMap<i32, Vec<i32>> = BTreeMap::new();

    let mut c = a.clone();
    c.append(&mut b.clone());
    c.dedup();
    c.sort();
    c.reverse();
    let (mut mn, mut mx) = (1e9 as i32, 0);

    for i in 0..n {
        if !mp.contains_key(max(&a[i], &b[i])) {
            mp.insert(max(a[i], b[i]), Vec::<i32>::new());
        }
        let v = mp.get_mut(max(&a[i], &b[i])).unwrap();
        v.push(min(a[i], b[i]));

        mx = max(a[i], b[i]);
        mn = min(mn, mx);
    }

    let mut ans: i32 = 1e9 as i32;
    let mut nwmx: i32 = 0;
    for c_i in &c {
        if *c_i < nwmx {
            break;
        }
        // println!("{mn}");
        ans = min(ans, *c_i - mn);

        let v = mp.get(c_i);
        match v {
            None => {
                break;
            }
            Some(x) => {
                // println!("{:?}", x);
                for v_i in x {
                    mn = min(mn, *v_i);
                    nwmx = max(nwmx, *v_i);
                }
            }
        }
    }
    writeln!(w, "{}", ans);
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
