.text
main:
# -----------------------
Function main
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
jal
Function main2
lw $t8, 12
lw $t9, 2500
lw $a2, num1
li $v0, 1
syscall
lw $a3, num2
li $v0, 1
syscall
div $t10, num1, 1000
add $t11, 2, num1
mult $t12, num2, 2
add $t13, 1, num2
sub $t14, num1, 1
lw $t15, num1
jal
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
