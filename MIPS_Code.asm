##### MIPS Assembly #####

.data
array: .word 0:6    # Declare an array of 5 integers

main:
    li $t0, 12      # Store the value 12 in $t0
    sw $t0, array    # Store the value in $t0 to the first element of array
    li $t1, 2500    # Store the value 2500 in $t1
    sw $t1, 4($array)    # Store the value in $t1 to the second element of array
    
    la $a0, array    # Load the address of array into $a0
    lw $v0, 0($a0)    # Load the value at the first element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 4($a0)    # Load the value at the second element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $t2, 0($a0)    # Load the value at the first element of array into $t2
    li $t3, 1000    # Store the value 1000 in $t3
    add $t4, $t2, $t3    # Add $t2 and $t3 and store the result in $t4
    sw $t4, 0($a0)    # Store the value in $t4 to the first element of array
    
    li $t5, 2    # Store the value 2 in $t5
    lw $t6, 0($a0)    # Load the value at the first element of array into $t6
    add $t7, $t5, $t6    # Add $t5 and $t6 and store the result in $t7
    sw $t7, 4($a0)    # Store the value in $t7 to the second element of array
    
    lw $t8, 4($a0)    # Load the value at the second element of array into $t8
    li $t9, 2    # Store the value 2 in $t9
    add $t10, $t8, $t9    # Add $t8 and $t9 and store the result in $t10
    sw $t10, 8($a0)    # Store the value in $t10 to the third element of array
    
    li $t11, 1    # Store the value 1 in $t11
    lw $t12, 4($a0)    # Load the value at the second element of array into $t12
    add $t13, $t12, $t11    # Add $t12 and $t11 and store the result in $t13
    sw $t13, 12($a0)    # Store the value in $t13 to the fourth element of array
    
    lw $v0, 8($a0)    # Load the value at the third element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 0($a0)    # Load the value at the first element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $t14, 0($a0)    # Load the value at the first element of array into $t14
    li $t15, 1    # Store the value 1 in $t15
    add $t16, $t14, $t15    # Add $t14 and $t15 and store the result in $t16
    sw $t16, 16($a0)    # Store the value in $t16 to the fifth element of array
    
    lw $v0, 8($a0)    # Load the value at the third element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $t17, 12($a0)    # Load the value at the fourth element of array into $t17
    li $t18, 500    # Store the value 500 in $t18
    sub $t19, $t17, $t18    # Subtract $t18 from $t17 and store the result in $t19
    sw $t19, 12($a0)    # Store the value in $t19 to the fourth element of array
    
    lw $v0, 12($a0)    # Load the value at the fourth element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 12($a0)    # Load the value at the fourth element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 8($a0)    # Load the value at the third element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 0($a0)    # Load the value at the first element of array into $v0
    li $v0, 1     # Print an integer
    syscall
    
main2:
    li $t20, 12      # Store the value 12 in $t20
    sw $t20, array1    # Store the value in $t20 to the first element of array1
    li $t21, 2500    # Store the value 2500 in $t21
    sw $t21, 4($array1)    # Store the value in $t21 to the second element of array1
    
    la $a1, array1    # Load the address of array1 into $a1
    lw $v0, 0($a1)    # Load the value at the first element of array1 into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 4($a1)    # Load the value at the second element of array1 into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $t22, 0($a1)    # Load the value at the first element of array1 into $t22
    li $t23, 1000    # Store the value 1000 in $t23
    add $t24, $t22, $t23    # Add $t22 and $t23 and store the result in $t24
    sw $t24, 0($a1)    # Store the value in $t24 to the first element of array1
    
    li $t25, 2    # Store the value 2 in $t25
    lw $t26, 0($a1)    # Load the value at the first element of array1 into $t26
    add $t27, $t25, $t26    # Add $t25 and $t26 and store the result in $t27
    sw $t27, 4($a1)    # Store the value in $t27 to the second element of array1
    
    lw $t28, 4($a1)    # Load the value at the second element of array1 into $t28
    li $t29, 2    # Store the value 2 in $t29
    add $t30, $t28, $t29    # Add $t28 and $t29 and store the result in $t30
    sw $t30, 8($a1)    # Store the value in $t30 to the third element of array1
    
    li $t31, 1    # Store the value 1 in $t31
    lw $t32, 4($a1)    # Load the value at the second element of array1 into $t32
    add $t33, $t32, $t31    # Add $t32 and $t31 and store the result in $t33
    sw $t33, 12($a1)    # Store the value in $t33 to the fourth element of array1
    
    lw $v0, 8($a1)    # Load the value at the third element of array1 into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 0($a1)    # Load the value at the first element of array1 into $v0
    li $v0, 1     # Print an integer
    syscall
    
    lw $v0, 8($a1)    # Load the value at the third element of array1 into $v0
    li $v0, 1     # Print an integer
    syscall
    
    jr $ra    # Return to the caller
