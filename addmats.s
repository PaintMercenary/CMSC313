	.file	"addmats.cpp"
	.text
	.section	.text$_ZN15MatrixFunctionsC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15MatrixFunctionsC1Ei
	.def	__ZN15MatrixFunctionsC1Ei;	.scl	2;	.type	32;	.endef
__ZN15MatrixFunctionsC1Ei:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	ret	$4
	.section	.text$_ZN15MatrixFunctions12addMatraciesEPiS0_S0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN15MatrixFunctions12addMatraciesEPiS0_S0_
	.def	__ZN15MatrixFunctions12addMatraciesEPiS0_S0_;	.scl	2;	.type	32;	.endef
__ZN15MatrixFunctions12addMatraciesEPiS0_S0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	%ecx, -24(%ebp)
	movl	$0, -8(%ebp)
	jmp	L3
L4:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %ecx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	8(%ebp), %eax
	addl	%ebx, %eax
	addl	%ecx, %edx
	movl	%edx, (%eax)
	addl	$1, -8(%ebp)
L3:
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, -8(%ebp)
	jl	L4
	nop
	nop
	movl	-4(%ebp), %ebx
	leave
	ret	$12
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$84, %esp
	call	___main
	pxor	%xmm0, %xmm0
	movups	%xmm0, -48(%ebp)
	movd	%xmm0, -32(%ebp)
	movl	$1, -48(%ebp)
	pxor	%xmm0, %xmm0
	movups	%xmm0, -68(%ebp)
	movd	%xmm0, -52(%ebp)
	movl	$2, -68(%ebp)
	leal	-72(%ebp), %eax
	movl	$5, (%esp)
	movl	%eax, %ecx
	call	__ZN15MatrixFunctionsC1Ei
	subl	$4, %esp
	leal	-72(%ebp), %eax
	leal	-68(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-48(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN15MatrixFunctions12addMatraciesEPiS0_S0_
	subl	$12, %esp
	movl	$1, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
