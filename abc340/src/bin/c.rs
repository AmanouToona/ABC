use proconio::input;
use std::collections::BTreeMap;

fn main() {
    input! {
        N: usize,
    };

    let mut ans: usize = 0;

    let mut nums: BTreeMap<usize, usize> = BTreeMap::new();

    nums.insert(N, 1);

    while !nums.is_empty() {
        let (n, cnt) = match nums.pop_last() {
            Some((n, cnt)) => (n, cnt),
            None => break,
        };

        // println!("{}, {}", n, cnt);

        if n == 1 {
            continue;
        }

        ans += n * cnt;

        if n / 2 > 1 {
            nums.entry(n / 2)
                .and_modify(|val| *val += cnt)
                .or_insert(cnt);
        }

        if (n + 1) / 2 > 1 {
            nums.entry((n + 1) / 2)
                .and_modify(|val| *val += cnt)
                .or_insert(cnt);
        }
    }

    println!("{}", ans);
}
