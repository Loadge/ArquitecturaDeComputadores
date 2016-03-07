	.file	"daxpy.c"
	.section	.rodata
	.align 8
.LC2:
	.string	"Tiempo de inicializaci\303\263n: %f \n"
.LC3:
	.string	"Tiempo de c\303\241lculo: %f \n"
.LC4:
	.string	"TIEMPO TOTAL: %f \n"
	.align 8
.LC5:
	.string	"vFinal[0]=%f /\nvFinal[%d]=%f  /\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	%edi, -116(%rbp)
	movq	%rsi, -128(%rbp)
	movl	$152000000, -4(%rbp)
	movabsq	$4647503709213818880, %rax
	movq	%rax, -48(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -40(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -32(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -8(%rbp)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-40(%rbp), %rax
	cvtsi2sd	-8(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cvtsi2sd	%edx, %xmm0
	movsd	%xmm0, (%rax)
	movl	-8(%rbp), %eax
	cltq
	addq	$2, %rax
	salq	$3, %rax
	addq	-40(%rbp), %rax
	movl	-8(%rbp), %edx
	addl	$2, %edx
	cvtsi2sd	%edx, %xmm0
	movsd	%xmm0, (%rax)
	addl	$3, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L3
	movl	$0, -8(%rbp)
	jmp	.L4
.L5:
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	cvtsi2sd	-8(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	addl	$1, %edx
	cvtsi2sd	%edx, %xmm0
	movsd	%xmm0, (%rax)
	movl	-8(%rbp), %eax
	cltq
	addq	$2, %rax
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	addl	$2, %edx
	cvtsi2sd	%edx, %xmm0
	movsd	%xmm0, (%rax)
	addl	$3, -8(%rbp)
.L4:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L5
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-96(%rbp), %rdx
	movq	-112(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-88(%rbp), %rdx
	movq	-104(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -8(%rbp)
	jmp	.L6
.L7:
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	-40(%rbp), %rdx
	movsd	(%rdx), %xmm0
	mulsd	-48(%rbp), %xmm0
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	-32(%rbp), %rdx
	movsd	(%rdx), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$3, %rdx
	addq	-40(%rbp), %rdx
	movsd	(%rdx), %xmm0
	mulsd	-48(%rbp), %xmm0
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$3, %rdx
	addq	-32(%rbp), %rdx
	movsd	(%rdx), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	movl	-8(%rbp), %eax
	cltq
	addq	$2, %rax
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	addq	$2, %rdx
	salq	$3, %rdx
	addq	-40(%rbp), %rdx
	movsd	(%rdx), %xmm0
	mulsd	-48(%rbp), %xmm0
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	addq	$2, %rdx
	salq	$3, %rdx
	addq	-32(%rbp), %rdx
	movsd	(%rdx), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	addl	$3, -8(%rbp)
.L6:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L7
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-64(%rbp), %rdx
	movq	-80(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-56(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	$.LC2, %eax
	movsd	-24(%rbp), %xmm0
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf
	movl	$.LC3, %eax
	movsd	-16(%rbp), %xmm0
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf
	movsd	-24(%rbp), %xmm0
	addsd	-16(%rbp), %xmm0
	movl	$.LC4, %eax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf
	movl	-4(%rbp), %eax
	cltq
	subq	$1, %rax
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movsd	(%rax), %xmm1
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-32(%rbp), %rax
	movsd	(%rax), %xmm0
	movl	$.LC5, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
