.text
main:
# -----------------------
lw $t0, num1
li $t0, 12
sw $t0, num1
lw $t1, num2
li $t1, 2500
sw $t1, num2
lw $a0, num1
li $v0, 1
syscall
lw $a1, num2
li $v0, 1
syscall
add $t2, num1, 1000
add $t3, 2, T0
add $t4, num2, T1
add $t5, 1, T2
add $t6, num1, T3
lw $t7, num3
li $t7, T4
sw $t7, num3
lw $a2, num3
li $v0, 1
syscall
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
