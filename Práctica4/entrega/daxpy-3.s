	.file	"daxpy.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC3:
	.string	"Tiempo de inicializaci\303\263n: %f \n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC4:
	.string	"Tiempo de c\303\241lculo: %f \n"
.LC5:
	.string	"TIEMPO TOTAL: %f \n"
	.section	.rodata.str1.8
	.align 8
.LC6:
	.string	"vFinal[0]=%f /\nvFinal[%d]=%f  /\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB34:
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
	.p2align 4,,10
	.p2align 3
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
	.p2align 4,,10
	.p2align 3
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
	cvtsi2sdq	%rax, %xmm2
	movq	56(%rsp), %rax
	subq	40(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm2, %xmm0
	movsd	%xmm0, 24(%rsp)
	call	clock_gettime
	xorl	%eax, %eax
	movapd	.LC1(%rip), %xmm3
	.p2align 4,,10
	.p2align 3
.L4:
	movsd	16(%rbp,%rax), %xmm4
	movsd	16(%rbx,%rax), %xmm5
	movhpd	24(%rbp,%rax), %xmm4
	movsd	32(%rbp,%rax), %xmm2
	movhpd	24(%rbx,%rax), %xmm5
	movapd	%xmm4, %xmm1
	movhpd	40(%rbp,%rax), %xmm2
	movsd	32(%rbx,%rax), %xmm4
	mulpd	%xmm3, %xmm1
	movapd	%xmm2, %xmm0
	movhpd	40(%rbx,%rax), %xmm4
	mulpd	%xmm3, %xmm0
	addpd	%xmm5, %xmm1
	movsd	0(%rbp,%rax), %xmm5
	addpd	%xmm4, %xmm0
	movhpd	8(%rbp,%rax), %xmm5
	movapd	%xmm5, %xmm2
	movlpd	%xmm1, 16(%rbx,%rax)
	movsd	(%rbx,%rax), %xmm5
	mulpd	%xmm3, %xmm2
	movhpd	%xmm1, 24(%rbx,%rax)
	movhpd	8(%rbx,%rax), %xmm5
	movlpd	%xmm0, 32(%rbx,%rax)
	movhpd	%xmm0, 40(%rbx,%rax)
	addpd	%xmm5, %xmm2
	movlpd	%xmm2, (%rbx,%rax)
	movhpd	%xmm2, 8(%rbx,%rax)
	addq	$48, %rax
	cmpq	$1215999984, %rax
	jne	.L4
	movsd	.LC2(%rip), %xmm0
	leaq	80(%rsp), %rsi
	movsd	1215999984(%rbp), %xmm1
	xorl	%edi, %edi
	mulsd	%xmm0, %xmm1
	addsd	1215999984(%rbx), %xmm1
	movsd	%xmm1, 1215999984(%rbx)
	movsd	1215999992(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	1216000000(%rbp), %xmm0
	addsd	1215999992(%rbx), %xmm1
	addsd	1216000000(%rbx), %xmm0
	movsd	%xmm1, 1215999992(%rbx)
	movsd	%xmm0, 1216000000(%rbx)
	call	clock_gettime
	movq	80(%rsp), %rax
	movl	$.LC3, %esi
	movl	$1, %edi
	subq	64(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	88(%rsp), %rax
	subq	72(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$1, %eax
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	24(%rsp), %xmm0
	movsd	%xmm1, (%rsp)
	call	__printf_chk
	movsd	(%rsp), %xmm1
	movl	$.LC4, %esi
	movl	$1, %edi
	movl	$1, %eax
	movapd	%xmm1, %xmm0
	call	__printf_chk
	movsd	(%rsp), %xmm1
	movl	$.LC5, %esi
	movsd	24(%rsp), %xmm0
	movl	$1, %edi
	movl	$1, %eax
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movsd	1215999992(%rbx), %xmm1
	movl	$151999999, %edx
	movsd	(%rbx), %xmm0
	movl	$.LC6, %esi
	movl	$1, %edi
	movl	$2, %eax
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
.LFE34:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC1:
	.long	0
	.long	1082081280
	.long	0
	.long	1082081280
	.section	.rodata.cst8
	.align 8
.LC2:
	.long	0
	.long	1082081280
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
