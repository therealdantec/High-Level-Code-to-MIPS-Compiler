.data
array: .word 5
array1: .word 3
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
    lw $t0, array($zero)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, 4(array)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, array($zero)
    addi $t0, $t0, 1000
    sw $t0, array($zero)
    li $t0, 2
    addi $t0, $t0, 0
    li $t1, 2
    lw $t2, array($zero)
    add $t0, $t0, $t2
    sw $t0, array($zero)
    li $t0, 1
    addi $t0, $t0, 0
    li $t1, 1
    lw $t2, 4(array)
    add $t0, $t0, $t2
    sw $t0, 4(array)
    addi $t0, $zero, 0
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, 4(array)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, array($zero)
    addi $t0, $t0, 1
    sw $t0, array($zero)
    addi $t0, $zero, 0
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, 4(array)
    subi $t0, $t0, 500
    sw $t0, 4(array)
    lw $t0, 4(array)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, 4(array)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, array($zero)
    move $a0, $t0
    li $v0, 1
    syscall

.globl main2
main2:
    li $t0, 12
    sw $t0, array1($zero)
    li $t0, 2500
    sw $t0, 4(array1)
    lw $t0, array1($zero)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, 4(array1)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, array1($zero)
    div $t0, $t0, 1000
    mflo $t0
    sw $t0, array1($zero)
    li $t0, 2
    addi $t0, $t0, 0
    lw $t2, array1($zero)
    add $t0, $t0, $t2
    sw $t0, array1($zero)
    li $t0, 1
    addi $t0, $t0, 0
    lw $t2, 4(array1)
    add $t0, $t0, $t2
    sw $t0, 4(array1)
    lw $t0, array1($zero)
    subi $t0, $t0, 1
    sw $t0, array1($zero)
    lw $t0, array1($zero)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, array1($zero)
    move $a0, $t0
    li $v0, 1
    syscall
    lw $t0, 4(array1)
    move $a0, $t0
    li $v0, 1
    syscall

.globl _start
_start:
    jal main
    jal main2
    li $v0, 10
    syscall
