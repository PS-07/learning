package main

import "fmt"

func main() {
	c := make(chan int, 2) // channel with capacity = 2, won't block sending until channel is full
	c <- 4
	c <- 9

	msg1 := <- c 
	fmt.Println(msg1)
	msg2 := <- c 
	fmt.Println(msg2)
}