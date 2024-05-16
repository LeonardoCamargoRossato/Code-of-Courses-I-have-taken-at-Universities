program Integral2

implicit none
common /parameters/x_sup
external Func 
real*8 x_sup,x_inf,xint,xint2,xmax,xmin,t1,t2,t3,t4
integer passos

!-------------------------------------------------------

x_sup = 2 !limite superior da integral
x_inf = 1 !limite inferior da integral
passos = 10000

Call integration_aula(x_sup,x_inf,passos,xint,t1,t2)  ! Argumentos Func = inputs + outputs

Call integration_simpson(x_sup,x_inf,passos,xint2,t3,t4)

write(*,*)
write(*,*) 'Função Analisada: x '
write(*,*)
write(*,*) 'Valores Pelo Método Visto na Aula de Fortran:'
write(*,*)
write(*,*) 'Valor Integração = ',xint , 'Passos:', passos, "time", (t2-t1) 
write(*,*)
write(*,*)
write(*,*) 'Valores Pelo Método de Simpson:'
write(*,*)
write(*,*) 'Valor Integração = ',xint2 , 'Passos:', passos, 'time', (t4-t3)
write(*,*)


RETURN
end program 

!##########################################################

Real*8 FUNCTION func(x)
	implicit none 
	real*8, intent(in) :: x    
	real*8 pi
	pi = 4.d0*datan(1.d0)
	func = x**2.d0*dlog(x+1.d0)
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
		integracao = integracao + func(xmin + j*h)
	end do
	
	xint = h*(integracao + 0.5d0*(func(0.d0) + func(x_sup)))
	
	CALL CPU_TIME(t2)
	return	
END SUBROUTINE integration_aula

!##########################################################

SUBROUTINE integration_simpson(x_sup,x_inf,passos,xint2,t3,t4)
	implicit none
	real*8, intent(in) :: x_sup,x_inf
	integer, intent(in) :: passos 
	real*8, intent(inout) :: xint2,t3,t4 
	real*8 :: xmax, xmin,func,h
	integer j,n,n1,n2
	external func
	real*8 sum1,sum2,step
	
	CALL CPU_TIME(t3)
	
	xmax = x_sup !limite superior integral
	xmin = x_inf !limite inferior integral
	n = passos !Numero de passos 
	
	h = (xmax - xmin) / n  !largura do passo de integracao
	n1 = n/2 - 1
	n2 = n/2 
	
	sum1 = 0.d0
	Do j =1,n1
	step = xmin + 2*j*h
	sum1 = sum1 + func(step)
	end do
	sum2 = 0.d0
	do j = 1,n2
	step = xmin + (2*j-1)*h
	sum2 = sum2 + func(step)
	end do
	
	xint2 = h*(func(xmin) + 2*sum1 + 4*sum2 + func(xmax))/3d0
	
	CALL CPU_TIME(t4)
END SUBROUTINE integration_simpson

!##########################################################

pure function integration_trapezoid(x, y) result(r)
    !! Calculates the integral of an array y with respect to x using the trapezoid
    !! approximation. Note that the mesh spacing of x does not have to be uniform.
    real*8, intent(in)  :: x(:)         !! Variable x
    real*8, intent(in)  :: y(size(x))   !! Function y(x)
    real*8              :: r            !! Integral ∫y(x)·dx

    ! Integrate using the trapezoidal rule
    associate(n => size(x))
      r = sum((y(1+1:n-0) + y(1+0:n-1))*(x(1+1:n-0) - x(1+0:n-1)))/2
    end associate
  end function	
