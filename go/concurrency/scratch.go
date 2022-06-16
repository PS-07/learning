package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()
	res := make(chan string, 3)
	go func () { res <- req("a") }()
	go func () { res <- req("b") }()
	go func () { res <- req("c") }()
	fastest_res := <- res
	fmt.Printf("fastest response: %s", fastest_res)
	elapsed := time.Since(start)
	fmt.Printf("time taken: %s\n", elapsed)
}

func req(s string) string {
	res := ""
	switch s {
	case "a":
		time.Sleep(time.Second * 5)
		res = "done a\n"
	case "b":
		time.Sleep(time.Second * 2)
		res = "done b\n"
	case "c":
		time.Sleep(time.Second * 3)
		res = "done c\n"
	}
	return res
}