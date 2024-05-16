program Integral2

implicit none
common /parameters/x_sup
external Func 
real*8 x_sup,xint,xm,xmax,xmin

!-------------------------------------------------------

x_sup = 2 !limite superior da integral
xm = 0.3d0 !acho que tem haver com a precisão

Call integration(xm,x_sup,xint)

write(*,*)
write(*,*) 'Função Analisada: x**2.d0*dlog(x+1.d0) '
write(*,*)
write(*,*) 'Valores Pelo Método dos Trapézios:'
write(*,*)
write(*,*) 'M = ',xm,'Valor da Integração = ',xint
write(*,*)

RETURN
end program 

Real*8 FUNCTION func(x)
!Real*8 FUNCTION func(x,xm)
	implicit none 
	real*8 x,xm,pi
	pi = 4.d0*datan(1.d0)
!	func = x**2.d0*dlog(x+1.d0)
	func = x
	RETURN
END FUNCTION	

!##########################################################

SUBROUTINE integration(xm, x_sup,xint) 
	implicit none
	real*8 :: xmax, xmin, tempT, deltax, xm, x_sup,func,xint
	integer :: nn,j
!	integer nn,j
	external func
	nn = 10000
	
	xmax = x_sup
	xmin = 0.d0
	tempT = 0.d0
	deltax = (xmax - xmin)/nn
	
	do j = 2,(nn - 1)
		tempT = tempT + func(xmin + j*deltax)
	end do
	
	xint = deltax*(tempT + 0.5d0*(func(0.d0) + func(x_sup)))
	return	
END SUBROUTINE integration
	
