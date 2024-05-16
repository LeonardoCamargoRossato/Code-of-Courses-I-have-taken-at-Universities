program SubRoutine_Integral2.f90

implicit none
common /parameters/xlambda
external Func, DerF,gap,dgapdm
real:: xlambda,xint,xm,xmax,xmin

!-------------------------------------------------------

xlambda = 0.5
xm = 0.3d0
Call integration(xm,xlabda,xint)
write(*,*) 'M = ',xm,"xint = ',xint
RETURN
end program 


Real FUNCTION func(x,xm)
	implicit none 
	real :: x,xm,pi
	pi = 4.d0*datan(1.d0)
	func = x**2.d0*dlog(x+1.d0)
	RETURN
END FUNCTION	

!##########################################################

SUBROUTINE integration(xm, xlambda,xint) 
	implicit none
	real :: xmax, xmin, tempT, deltax, xm, xlambda,func,xint
	integer :: nn,j
	external func
	nn = 10000
	
	xmax = xlambda
	xmin = 0.d0
	tempT = 0.d0
	deltax = (xmax - xmin)/nn
	
	do 2 j = 2,(nn - 1)
	tempT = tempT + func(xmin + j*deltax,xm)
	
	enddo
	
	xint = deltax*(tempT + 0.50*(func(0.d0,xm) + func(xlambda,xm)))
	return	
END SUBROUTINE integration
	
end program
