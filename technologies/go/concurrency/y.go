package main

import (
	"fmt"
)

func main() {
	fmt.Println("a")
	defer fmt.Println("b")
	defer fmt.Println("c")
}
