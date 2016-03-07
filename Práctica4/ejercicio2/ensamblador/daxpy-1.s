	.file	"daxpy.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Tiempo de inicializaci\303\263n: %f \n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"Tiempo de c\303\241lculo: %f \n"
.LC4:
	.string	"TIEMPO TOTAL: %f \n"
	.section	.rodata.str1.8
	.align 8
.LC5:
	.string	"vFinal[0]=%f /\nvFinal[%d]=%f  /\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB34:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$88, %rsp
	.cfi_def_cfa_offset 112
	movl	$1216000000, %edi
	call	malloc
	movq	%rax, %rbp
	movl	$1216000000, %edi
	call	malloc
	movq	%rax, %rbx
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	%rbp, %rdx
	movl	$0, %eax
.L2:
	cvtsi2sd	%eax, %xmm0
	movsd	%xmm0, (%rdx)
	leal	1(%rax), %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 8(%rdx)
	leal	2(%rax), %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 16(%rdx)
	addl	$3, %eax
	addq	$24, %rdx
	cmpl	$152000001, %eax
	jne	.L2
	movq	%rbx, %rdx
	movl	$0, %eax
.L3:
	cvtsi2sd	%eax, %xmm0
	movsd	%xmm0, (%rdx)
	leal	1(%rax), %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 8(%rdx)
	leal	2(%rax), %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 16(%rdx)
	addl	$3, %eax
	addq	$24, %rdx
	cmpl	$152000001, %eax
	jne	.L3
	leaq	32(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, (%rsp)
	leaq	48(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, %eax
	movsd	.LC1(%rip), %xmm0
.L4:
	movsd	0(%rbp,%rax), %xmm1
	mulsd	%xmm0, %xmm1
	addsd	(%rbx,%rax), %xmm1
	movsd	%xmm1, (%rbx,%rax)
	movsd	8(%rbp,%rax), %xmm1
	mulsd	%xmm0, %xmm1
	addsd	8(%rbx,%rax), %xmm1
	movsd	%xmm1, 8(%rbx,%rax)
	movsd	16(%rbp,%rax), %xmm1
	mulsd	%xmm0, %xmm1
	addsd	16(%rbx,%rax), %xmm1
	movsd	%xmm1, 16(%rbx,%rax)
	addq	$24, %rax
	cmpq	$1216000008, %rax
	jne	.L4
	leaq	64(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	64(%rsp), %rax
	subq	48(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	72(%rsp), %rax
	subq	56(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, 8(%rsp)
	movsd	(%rsp), %xmm0
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movsd	8(%rsp), %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movsd	(%rsp), %xmm0
	addsd	8(%rsp), %xmm0
	movl	$.LC4, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movsd	1215999992(%rbx), %xmm1
	movl	$151999999, %edx
	movsd	(%rbx), %xmm0
	movl	$.LC5, %esi
	movl	$1, %edi
	movl	$2, %eax
	call	__printf_chk
	movl	$0, %eax
	addq	$88, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.align 8
.LC1:
	.long	0
	.long	1082081280
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
