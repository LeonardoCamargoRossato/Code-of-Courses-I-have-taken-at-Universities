program Integral2

implicit none
common /parameters/xlambda
external Func, DerF,gap,dgapdm
!real:: xlambda,xint,xm,xmax,xmin
real*8 xlambda,xint,xm,xmax,xmin

!-------------------------------------------------------

xlambda = 0.5
xm = 0.3d0
Call integration(xm,xlambda,xint)
write(*,*) 'M = ',xm,'xint = ',xint
RETURN
end program 


Real*8 FUNCTION func(x,xm)
	implicit none 
!	real :: x,xm,pi
	real*8 x,xm,pi
	pi = 4.d0*datan(1.d0)
	func = x**2.d0*dlog(x+1.d0)
	RETURN
END FUNCTION	

!##########################################################

SUBROUTINE integration(xm, xlambda,xint) 
	implicit none
	real*8 :: xmax, xmin, tempT, deltax, xm, xlambda,func,xint
	integer :: nn,j
!	real*8 xmax, xmin, tempT, deltax, xm, xlambda,func,xint
!	integer nn,j
	external func
	nn = 10000
	
	xmax = xlambda
	xmin = 0.d0
	tempT = 0.d0
	deltax = (xmax - xmin)/nn
	
	do j = 2,(nn - 1)
		tempT = tempT + func(xmin + j*deltax,xm)
	end do
	
	xint = deltax*(tempT + 0.5d0*(func(0.d0,xm) + func(xlambda,xm)))
	return	
END SUBROUTINE integration
	
pure function integrate(x, y) result(r)
	!! Calculates the integral of an array y with respect to x using the trapezoid
	!! approximation. Note that the mesh spacing of x does not have to be uniform.
	real(wp), intent(in)  :: x(:)         !! Variable x
	real(wp), intent(in)  :: y(size(x))   !! Function y(x)
	real(wp)              :: r            !! Integral ∫y(x)·dx

	! Integrate using the trapezoidal rule
	associate(n => size(x))
	r = sum((y(1+1:n-0) + y(1+0:n-1))*(x(1+1:n-0) - x(1+0:n-1)))/2
	end associate
end function
