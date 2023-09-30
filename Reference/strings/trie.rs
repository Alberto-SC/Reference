struct Trie {
    next: HashMap<usize, Box<Trie>>,
}

impl Trie {
    fn new() -> Self {
        Self {
            next: HashMap::new(),
        }
    }

    fn add(&mut self, mut v: Vec<usize>) {
        if v.is_empty() {
            return;
        }
        let last = v.pop().unwrap();
        let entry = self.next.entry(last).or_insert(Box::new(Trie::new()));
        entry.add(v);
    }

    fn compute(&self, v: &Vec<usize>, curr: usize) -> usize {
        if curr == v.len() {
            return curr;
        }
        if self.next.contains_key(&v[curr]) {
            return self.next.get(&v[curr]).unwrap().compute(v, curr + 1);
        }
        curr
    }
}
