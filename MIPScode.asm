.text
main:
# -----------------------
lw $t0, 12
lw $t1, 2500
lw $a0, num1
li $v0, 1
syscall
lw $a1, num2
li $v0, 1
syscall
add $t2, num1, 1000
add $t3, 2, num1
add $t4, num2, 2
add $t5, 1, num2
add $t6, num1, 1
lw $t7, num1
