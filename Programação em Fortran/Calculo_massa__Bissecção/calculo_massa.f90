program calculo_massa
implicit none
common /parameters/x_sup
external Func 
real*8 x_sup,x_inf,xint,xint2,xmax,xmin,t1,t2,t3,t4
integer passos

!-------------------------------------------------------
real*8 xlambda, M, Mmax,Mmin, F
real*8 m0,L,g,pi,nf,nc,delM
integer iM,nM

pi = 4.d0*datan(1.d0)
nc = 3
nf = 2
m0 = 0.0056d0
L = 0.0056d0
xlambda = 0.5879d0
g = 2.44d0/(xlambda**2.d0)

x_sup = L !limite superior da integral
x_inf = 0 !limite inferior da integral
passos = 10000

Mmin = 0.001d0
Mmax = 0.5d0
nM = 25
delM = (Mmax - Mmin)/dfloat(nM - 1)

!Trecho que Printa na Tela os V
!-----------------------------------------------------------------------------------------------
open(unit=25, file='FXM')
do iM = 1,nM
	M = Mmin + dfloat(iM-1)*delM
	Call integration_aula(M,xlambda,passos,xint,t1,t2)  ! Argumentos Func = inputs + outputs
	F = M - m0 - ((2.d0*g*nc*nf*M)/(pi**2.d0)) * xint
	write(*,*) 'M=',M,'F(M)=', F
	write(25,*)M, F
end do
close(25)
!-----------------------------------------------------------------------------------------------

call system('gnuplot -p FXM.plt')

write(*,*) 'Valor Integral:' , xint

RETURN
end program 

!##########################################################

Real*8 FUNCTION func(x,M)
	implicit none 
	real*8, intent(in) :: x,M
	
	func = x**2.d0 / dsqrt(x**2.d0 + M**2.d0)
!	func = x
	RETURN
END FUNCTION	

!##########################################################

SUBROUTINE integration_aula(x_sup,x_inf,passos,xint,t1,t2) 
	implicit none
	real*8, intent(in) :: x_sup,x_inf
	integer, intent(in) :: passos 
	real*8, intent(inout) :: xint,t1,t2 
	real*8 :: xmax, xmin, integracao, h,func
	integer n,j
	external func
	
	CALL CPU_TIME(t1)
	
	n = passos !Numero de passos 
	xmax = x_sup !limite superior integral
	xmin = x_inf !limite inferior integral
	integracao = 0.d0
	h = (xmax - xmin)/n   !largura do passo de integracao
	
	do j = 2,(n - 1)
		integracao = integracao + func(xmin + j*h,x_sup)
	end do
	
	xint = h*(integracao + 0.5d0*(func(0.d0,x_sup) + func(x_sup, x_sup)))
	
	CALL CPU_TIME(t2)
	return	
END SUBROUTINE integration_aula

!##########################################################


