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

#### Verbose - steps
```sh
$ make verbose path="path_to_rust_file"
```

#### test
```sh
(base) daniel$ make test
[doctest] doctest version is "2.4.1"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases:  5 |  5 passed | 0 failed | 0 skipped
[doctest] assertions: 20 | 20 passed | 0 failed |
[doctest] Status: SUCCESS!
```
