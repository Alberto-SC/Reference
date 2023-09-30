#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_imports)]
use std::cmp::{max, min, Reverse};
use std::collections::{HashMap, HashSet};
use std::io::{self, prelude::*};
use std::{mem, str};

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

    let pos1 = v.iter().position(|&x| x == 1).unwrap();
    let pos2 = v.iter().position(|&x| x == 2).unwrap();
    let pos3 = v.iter().position(|&x| x == 3).unwrap();

    if n <= 3 {
        v.sort();
        for i in 0..n {
            write!(w, "{} ", v[i]);
        }
        writeln!(w, "");
        return;
    }

    let mut a = v.clone();
    let mut b = v.clone();
    let mut c = v.clone();

    let mut pos = vec![0; n + 1];

    for i in 0..n {
        pos[v[i] as usize] = i;
    }

    let mut mx = 2;
    let mut id = 1;
    let mut pos_a = pos.clone();
    for i in pos1..pos1 + n {
        if a[i % n] != id && mx > 0 {
            let prev = a[i % n];
            a.swap(pos_a[id as usize] as usize, i % n);
            pos_a.swap(prev as usize, id as usize);
            mx -= 1;
        } else if a[i % n] != id {
            break;
        }
        id += 1;
    }

    a.rotate_left(pos1);

    mx = 1;
    id = 2;
    let mut pos_b = pos.clone();
    // println!("{:?}", pos_b);
    for i in pos2..pos2 + n {
        if id > n as i32 {
            break;
        }
        // println!("{i} {id}");
        if b[i % n] != id && mx > 0 {
            let prev = b[i % n];
            b.swap(pos_b[id as usize] as usize, i % n);
            pos_b.swap(prev as usize, id as usize);
            mx -= 1;
        } else if b[i % n] != id {
            break;
        }
        id += 1;
    }
    let mut rot = pos2 as i32 - 1;
    if rot < 0 {
        rot += n as i32;
    }
    b.rotate_left(rot as usize);
    let mut nw_pos_1: i32 = (pos_b[1] as i32) - (pos2 as i32 - 1) as i32;
    if nw_pos_1 < 0 {
        nw_pos_1 += n as i32;
    }

    if (nw_pos_1 == 0) {
        id = 1;
        mx = 1;
        for i in 0..n {
            if id > n as i32 {
                break;
            }
            if b[i] != id && mx > 0 {
                let prev = b[i];
                b.swap(pos[id as usize] as usize, i);
                pos_b.swap(prev as usize, id as usize);
                mx -= 1;
            } else if b[i] != id {
                break;
            }
            id += 1;
        }
    } else {
        b.swap(0, nw_pos_1 as usize);
    }

    mx = 0;
    rot = pos3 as i32 - 2;
    if rot < 0 {
        rot += n as i32;
    }
    let mut pos_c = vec![0; n + 1];
    c.rotate_left(rot as usize);

    for i in 0..n {
        pos_c[c[i] as usize] = i;
    }

    if pos_c[1] == 0 {
        mx += 1;
    } else {
        let prev = c[0];
        c.swap(pos_c[1] as usize, 0);
        pos_c.swap(prev as usize, 1);
    }
    if pos_c[2] == 1 {
        mx += 1;
    } else {
        let prev = c[1];
        c.swap(pos_c[2] as usize, 1);
        pos_c.swap(prev as usize, 2);
    }
    id = 1;
    for i in 0..n {
        if id > n as i32 {
            break;
        }
        if c[i] != id && mx > 0 {
            let prev = c[i];
            c.swap(pos_c[id as usize] as usize, i);
            pos_c.swap(prev as usize, id as usize);
            mx -= 1;
        } else if c[i] != id {
            break;
        }
        id += 1;
    }
    let ans = min(min(&a, &b), &c);
    for i in 0..n {
        write!(w, "{} ", ans[i]);
    }
    writeln!(w, "");
    // println!("{:?}", a);
    // println!("{:?}", b);
    // println!("{:?}", c);
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
