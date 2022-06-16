package main

import (
	"fmt"
	"time"
)

func main() {
	c := make(chan string) // create a channel, datatype is mandatory
	go count("apple", c)

	// will receive on channel until it is closed
	for msg := range c {
		fmt.Println(msg)
	}
}

func count(s string, c chan string) {
	for i := 0; i < 5; i++ {
		c <- s // send data on channel
		time.Sleep(time.Millisecond * 500)
	}
	close(c) // close the channel so main goroutine is not blocked
}
