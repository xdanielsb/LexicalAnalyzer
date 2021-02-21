This is a small lexical analyser for Rust, it was done in a very short time, and as task of the university, then do not expect too much. Feel free to contribute there are lot of stuff to change/improve/tweak.

#### Input

```rust
fn main() {
    let n = 2;
    if n % 2 == 0 {
        println!("The number is even");
    }
}
```

#### Output
```sh
----LINE #1  keyword: fn
----LINE #1  identifier: main
----LINE #2  keyword: let
----LINE #2  identifier: n
----LINE #2  operator: =
----LINE #2  number: 2
----LINE #3  keyword: if
----LINE #3  identifier: n
----LINE #3  operator: %
----LINE #3  number: 2
----LINE #3  operator: ==
----LINE #3  number: 0
----LINE #4  keyword: println!
----LINE #4  string: "The number is even"
```

#### Run
```sh
$ make path="path_to_rust_file"
```

#### verbose
```sh
$ make verbose="path_to_rust_file"
```

#### test
```sh
$ make test
```
