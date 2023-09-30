package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	solve := func(curCase int) (_res bool) {
		var n int
		Fscan(in, &n)
		Fprintln(out, -1)
		return
	}

	cases := 1
	Fscan(in, &cases)
	for curCase := 1; curCase <= cases; curCase++ {
		ans := solve(curCase)
		_ = ans

	}

}

func main() { run(os.Stdin, os.Stdout) }
