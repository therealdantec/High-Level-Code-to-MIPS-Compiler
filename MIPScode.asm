.data
.text
main:
# -----------------------

Function main:
lw $t0, 12
lw $t1, 2500
lw $a0, num1
li $v0, 1
syscall
lw $a1, num2
li $v0, 1
syscall
add $t2, num1, 1000
add $t3, 2, $t2
add $t4, num2, 2
add $t5, 1, $t4
add $t6, num1, 1
lw $t7, $t6
lw $a2, num3
li $v0, 1
syscall
lw $a3, num1
li $v0, 1
syscall
add $t8, num1, 1
lw $t9, $t8
lw $a4, num2
li $v0, 1
syscall
sub $t10, num2, 500
lw $t11, num2
lw $a5, num2
li $v0, 1
syscall
lw $a6, num3
li $v0, 1
syscall
lw $a7, num1
li $v0, 1
syscall
jal

Function main2:
lw $t12, 12
lw $t13, 2500
lw $a8, num4
li $v0, 1
syscall
lw $a9, num5
li $v0, 1
syscall
div $t14, num4, 1000
add $t15, 2, num4
mult $t16, num5, 2
add $t17, 1, num5
sub $t18, num4, 1
lw $t19, num4
lw $a10, num6
li $v0, 1
syscall
jal

# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
