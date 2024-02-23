use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        A: usize,
        B: usize,
        D: usize
    }

    let ans: Vec<String> = (A..=B)
        .step_by(D)
        .into_iter()
        .map(|x| x.to_string())
        .collect_vec();

    println!("{}", ans.join(" "));
}
