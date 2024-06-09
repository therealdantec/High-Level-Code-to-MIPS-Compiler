#### Standard MIPS Assembly ####

.data
array: .word 0:5
array1: .word 0:3
num1: .word 0
num2: .word 0
num3: .word 0
num4: .word 0
num5: .word 0
num6: .word 0

.text
.globl main
main:
    li $t0, 12
    sw $t0, array($zero)
    
    li $t0, 2500
    sw $t0, 4(array)

    lw $t0, 0(array)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 4(array)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 0(array)
    li $t1, 1000
    add $t0, $t0, $t1
    sw $t0, 0(array)

    li $t0, 2
    add $t1, $t0, $zero
    lw $t0, 4(array)
    add $t0, $t0, $t1
    sw $t0, 4(array)

    lw $t0, 4(array)
    li $t1, 2
    add $t0, $t0, $t1
    sw $t0, 4(array)

    li $t0, 1
    add $t1, $t0, $zero
    lw $t0, 0(array)
    add $t0, $t0, $t1
    sw $t0, 0(array)

    lw $t0, 0(array)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 0(array)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 0(array)

    lw $t0, 0(array)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 4(array)
    li $t1, 500
    sub $t0, $t0, $t1
    sw $t0, 4(array)
    
    lw $t0, 4(array)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 4(array)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 0(array)
    li $v0, 1
    move $a0, $t0
    syscall

    jr $ra

.globl main2
main2:
    li $t0, 12
    sw $t0, array1($zero)
    
    li $t0, 2500
    sw $t0, 4(array1)

    lw $t0, 0(array1)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 4(array1)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 0(array1)
    li $t1, 1000
    div $t0, $t0, $t1

    li $t1, 2
    add $t2, $t1, $t0
    sw $t2, 4(array1)

    lw $t0, 4(array1)
    li $t1, 2
    mul $t0, $t0, $t1
    sw $t0, 4(array1)

    li $t0, 1
    li $t1, 1
    add $t2, $t1, $zero
    lw $t0, 4(array1)
    add $t0, $t0, $t2
    sw $t0, 4(array1)

    lw $t0, 0(array1)
    li $t1, 1
    sub $t0, $t0, $t1
    sw $t0, 0(array1)

    lw $t0, 0(array1)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 0(array1)
    li $v0, 1
    move $a0, $t0
    syscall

    lw $t0, 4(array1)
    li $v0, 1
    move $a0, $t0
    syscall

    jr $ra
