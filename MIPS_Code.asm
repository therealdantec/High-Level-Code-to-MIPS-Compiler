.data
        array: .space 20
        array1: .space 12
        newline: .asciiz "\n"
.text
main22:
        li $t0,12
        li $t1,2500
        li $v0,1
        move $a0,$t0
        syscall
        li $v0,1
        move $a0,$t1
        syscall
        add $t2,$t0,$t1
        addi $t2,$t2,3
        add $t2,$t2,$t0
        addi $t2,$t2,1000
        li $v0,1
        move $a0,$t2
        syscall
loop_main22:
        blt $t0,20,exit_loop
        li $v0,1
        move $a0,$t0
        syscall
        addi $t0,$t0,1
        j loop_main22
exit_loop:
        li $t4,0
loop_main22_1:
        bge $t1,$t4,exit_loop1
        li $v0,1
        move $a0,$t1
        syscall
        addi $t1,$t1,-500
        j loop_main22_1
exit_loop1:
        bge $t1,$t4,next_main22
write_num2:
        li $v0,1
        move $a0,$t1
        syscall
next_main22:
        li $t3,1000
        bge $t2,$t3,else_main22
write_num3:
        li $v0,1
        move $a0,$t2
        syscall
        j end_main22
else_main22:
        li $v0,1
        move $a0,$t0
        syscall
end_main22:
        jr $ra

main2:
        li $t5,12
        li $t6,2500
        li $v0,1
        move $a0,$t5
        syscall
        li $v0,1
        move $a0,$t6
        syscall
        sub $t7,$t5,1
        mul $t8,$t6,2
        add $t7,$t7,$t8
        div $t9,$t5,1000
        add $t7,$t7,$t9
        li $v0,1
        move $a0,$t7
        syscall 
        bne $t5,12,write_num6
        li $v0,1
        move $a0,$t5
        syscall
write_num6:
        li $v0,1
        move $a0,$t6
        syscall
        j end_main2
end_main2:
        jr $ra

.globl main
main:
        jal main22
        jal main2
        li $v0,10
        syscall
