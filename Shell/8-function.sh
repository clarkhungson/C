#write function

#!/bin/bash
function func_B {
	echo Func B.
}

function func_A {
	echo $1
}

function func_D {
	echo Func D.
}

function func_C {
	echo $1
}

func_A "Function A."
func_B
func_C "Function C."
func_D

echo A B