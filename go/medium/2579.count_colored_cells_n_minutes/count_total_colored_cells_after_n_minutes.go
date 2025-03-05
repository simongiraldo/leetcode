package main

func coloredCells(n int) int64 {
	centerSquare := n * n
	edges := (n - 1) * (n - 1)
	return int64(centerSquare + edges)
}
