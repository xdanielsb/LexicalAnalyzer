use std::fmt;


// this is  a point
struct Point2D {
    x : f64,
    y : f64,
}

fn main(){
    let message = "hey there !";
    /* 
     * Multi line Comment
     */
    for i in 1..=10{
        println!("Number i = {}", i);
    }

    let year = 2020;
    if year % 7 > 10{
        println!("Lucky year");
    }else{
        println!("Fizz!");
    }

    let mut num = 10;

    while num < 12 {
        num +=1 ;
    }
}
