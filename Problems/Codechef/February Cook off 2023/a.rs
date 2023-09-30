#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_imports)]
use std::cmp::{max, min, Reverse};
use std::collections::{HashMap, HashSet};
use std::io::{self, prelude::*};
use std::str;

// fn solve() {
//     input! {
//         n:usize,
//     }
//     println!("{}", n);
// }

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());
    input! {
        t: usize,
        n: usize,
    }

    let out = std::io::stdout();
    let mut w = std::io::BufWriter::new(out.lock());

    // for _ in 0..t {
    //     // solve()
    // }
    // for _ in 0..t {
    //     input! {
    //         n: usize,
    //     }
    //     let mut ans = vec![0; n];

    //     for i in 2..=n {
    //         ans[i - 2] = i;
    //     }

    //     let len = ans.len();
    //     ans[len - 1] = 1;

    //     println!("{:?}", ans);
    //     for i in 0..n {
    //         write!(w, "{}", ans[i]).ok();
    //     }
    // }
}

// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8

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

#[macro_export]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        println!("{:?}",s);
        let mut next = || { iter.next().unwrap() };
        input_inner!{next, $($r)*}
    };
    ($($r:tt)*)=>{
        println!("{}",$($r)*);
    }
    // ($($r:tt)*) => {
    //     // println!("{}",$($r)*);
    //     let stdin = std::io::stdin();
    //     let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));

    //     let mut next = move || -> String{
    //         bytes
    //             .by_ref()
    //             .map(|r|r.unwrap() as char)
    //             .skip_while(|c|c.is_whitespace())
    //             .take_while(|c|!c.is_whitespace())
    //             .collect()
    //     };
    //     println!("{:?}",next());
    //     // println!("{:?}",next());
    //     input_inner!{next, $($r)*}
    // };
}

#[macro_export]
macro_rules! input_inner {
    ($next:expr) => {};
    ($next:expr, ) => {};

    ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($next, $t);
        println!("{}",read_value!($next,$t));
        input_inner!{$next $($r)*}
    };
}

#[macro_export]
macro_rules! read_value {
    ($next:expr, ( $($t:tt),* )) => {
        ( $(read_value!($next, $t)),* )
    };

    ($next:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
    };

    ($next:expr, chars) => {
        read_value!($next, String).chars().collect::<Vec<char>>()
    };

    ($next:expr, usize1) => {
        read_value!($next, usize) - 1
    };

    ($next:expr, $t:ty) => {
        $next().parse::<$t>().expect("Parse error")
    };
}
