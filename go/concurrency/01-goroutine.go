package main

import (
	"fmt"
	"time"
)

func main() {
	// creates a goroutine that will run side-by-side with main goroutine
	go count("apple")
	count("orange")
}

func count(s string) {
	for i := 0; true; i++ {
		fmt.Println(i, s)
		time.Sleep(time.Millisecond * 500)
	}
}
