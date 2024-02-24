use proconio::input;
fn main() {
    input! {
        Q: usize,
        query: [(usize, usize); Q],
    };

    let mut A = Vec::new();

    for &(q, num) in query.iter() {
        if q == 1 {
            A.push(num);
        } else {
            let ans = A[A.len() - num];
            println!("{}", ans);
        }
    }
}
