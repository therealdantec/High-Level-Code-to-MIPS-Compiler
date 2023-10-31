.text
main:
# -----------------------
lw T0, 12
lw T1, 2500
lw $a0, num1
li $v0, 1
syscall
lw $a1, num2
li $v0, 1
syscall
add T2, num1, 1000
add T3, 2, num1
add T4, num2, 2
add T5, 1, num2
add T6, num1, 1
lw T7, num1
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
