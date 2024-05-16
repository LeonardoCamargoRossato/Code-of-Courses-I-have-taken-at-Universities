program SubRoutine_Integral.f90

implicit none
real:: esc
integer :: i, j

!Definição dos Valores das Matrizes
REAL :: A3(3,3) = RESHAPE((/2.0,4.0,3.0,2.0,4.0,3.0,2.0,4.0,3.0/),(/3,3/))
REAL :: B3(3,3) = RESHAPE((/2.0,1.0,1.0,3.0,2.0,2.0,4.0,3.0,3.0/),(/3,3/))
REAL :: A2(2,2) = RESHAPE((/2.0,4.0,3.0,2.0/),(/2,2/))
REAL :: B2(2,2) = RESHAPE((/2.0,1.0,1.0,3.0/),(/2,2/))

!-------------------------------------------------------

Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui chama a SubRoutine: Matriz_2(A2,B2)'
Write(*,*) '############################################'
Write(*,*)

Call Matriz_2(A2,B2)

Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui chama a SubRoutine: Matriz_n(A2,B2,2)'
Write(*,*) '############################################'
Write(*,*)

Call Matriz_n(A2,B2,2)

Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui chama a SubRoutine: Matriz_n(A2,B2,3)'
Write(*,*) '############################################'
Write(*,*)

Call Matriz_n(A3,B3,3)

	
END SUBROUTINE Matriz_2

!##########################################################

SUBROUTINE integrate(x, y) result(r)
	implicit none
	!! Calculates the integral of an array y with respect to x using the trapezoid
    !! approximation. Note that the mesh spacing of x does not have to be uniform.
    real(wp), intent(in)  :: x(:)         !! Variable x
    real(wp), intent(in)  :: y(size(x))   !! Function y(x)
    real(wp)              :: r            !! Integral ∫y(x)·dx

    ! Integrate using the trapezoidal rule
    associate(n => size(x))
      r = sum((y(1+1:n-0) + y(1+0:n-1))*(x(1+1:n-0) - x(1+0:n-1)))/2
    end associate
	
END SUBROUTINE Matriz_n
	
end program




