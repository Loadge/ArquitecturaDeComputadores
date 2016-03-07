	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Tiempo de inicializaci\303\263n: %f \n"
.LC3:
	.string	"Tiempo de c\303\241lculo: %f \n"
.LC4:
	.string	"TIEMPO TOTAL: %f \n"
.LC5:
	.string	"vFinal[0]=%f /\nvFinal[%d]=%f  /\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$1216000000, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$104, %rsp
	.cfi_def_cfa_offset 128
	call	malloc
	movl	$1216000000, %edi
	movq	%rax, %rbp
	call	malloc
	leaq	32(%rsp), %rsi
	xorl	%edi, %edi
	movq	%rax, %rbx
	call	clock_gettime
	movq	%rbp, %rdx
	xorl	%eax, %eax
.L2:
	cvtsi2sd	%eax, %xmm0
	leal	1(%rax), %ecx
	movsd	%xmm0, (%rdx)
	cvtsi2sd	%ecx, %xmm0
	leal	2(%rax), %ecx
	addl	$3, %eax
	movsd	%xmm0, 8(%rdx)
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 16(%rdx)
	addq	$24, %rdx
	cmpl	$152000001, %eax
	jne	.L2
	movq	%rbx, %rdx
	xorl	%eax, %eax
.L3:
	cvtsi2sd	%eax, %xmm0
	leal	1(%rax), %ecx
	movsd	%xmm0, (%rdx)
	cvtsi2sd	%ecx, %xmm0
	leal	2(%rax), %ecx
	addl	$3, %eax
	movsd	%xmm0, 8(%rdx)
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 16(%rdx)
	addq	$24, %rdx
	cmpl	$152000001, %eax
	jne	.L3
	leaq	48(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	48(%rsp), %rax
	subq	32(%rsp), %rax
	leaq	64(%rsp), %rsi
	xorl	%edi, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	56(%rsp), %rax
	subq	40(%rsp), %rax
	movsd	%xmm0, 24(%rsp)
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	24(%rsp), %xmm0
	movsd	%xmm0, 24(%rsp)
	call	clock_gettime
	movsd	.LC1(%rip), %xmm0
	xorl	%eax, %eax
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
	leaq	80(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	80(%rsp), %rax
	subq	64(%rsp), %rax
	movl	$.LC2, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm1
	movq	88(%rsp), %rax
	subq	72(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	movb	$1, %al
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	24(%rsp), %xmm0
	movsd	%xmm1, (%rsp)
	call	__printf_chk
	movsd	(%rsp), %xmm1
	movl	$.LC3, %esi
	movl	$1, %edi
	movb	$1, %al
	movaps	%xmm1, %xmm0
	call	__printf_chk
	movsd	(%rsp), %xmm1
	movl	$.LC4, %esi
	movsd	24(%rsp), %xmm0
	movl	$1, %edi
	movb	$1, %al
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movsd	1215999992(%rbx), %xmm1
	movl	$151999999, %edx
	movsd	(%rbx), %xmm0
	movl	$.LC5, %esi
	movl	$1, %edi
	movb	$2, %al
	call	__printf_chk
	addq	$104, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE17:
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
