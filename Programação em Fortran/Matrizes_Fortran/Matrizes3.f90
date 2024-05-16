program matrizesf90

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

Write(*,*)

CONTAINS  !Só dá pra escrever Functions and SubRoutines dps do CONTAINS


!##########################################################
! F U N Ç O E S   E X T E R N A S  
!##########################################################

SUBROUTINE Matriz_2(A,B)
	implicit none
	real:: esc2
	integer :: i2, j2

	REAL, intent(out) :: A(2,2)
	REAL, intent(out) :: B(2,2)
	REAL :: C2(2,2) !Soma de Matrizes
	REAL :: D2(2,2) !Multiplicação de Matrizes
	REAL :: E2(2,2) !Multiplicação por um Escalar
	
	Write(*,*)'Matriz [A]:'
	do i2=1,2
		Write(*,*) (A(i2,j2),j2=1,2)
	end do

	Write(*,*)
	Write(*,*)'Matriz [B]'
	do i2=1,2
		Write(*,*) (B(i2,j2),j2=1,2)
	end do


	Write(*,*)
	Write(*,*)'Matriz [C2] = [A] + [B]'
	C2 = A + B
	do i2=1,2
		Write(*,*) (C2(i2,j2),j2=1,2)
	end do

	Write(*,*) 
	Write(*,*)'-> Para Calcular Matriz [A] x Escalar, digite o valor do Escalar: '
	Read(*,*) esc2

	Write(*,*) 
	print*,'Escalar Digitado:',esc2

	Write(*,*) 
	Write(*,*)'Matriz [A] x Escalar'
	E2 = esc2*A
	do i2=1,2
		Write(*,*) (E2(i2,j2),j2=1,2)
	end do

	Write(*,*) 
	Write(*,*)'Matriz [D2] = [A] x [B]'
	D2 = MATMUL(A,B)
	do i2=1,2
		Write(*,*) (D2(i2,j2),j2=1,2)
	end do

	Write(*,*)
	Write(*,*)'Matriz [A] Transposta'
	do i2=1,2
		Write(*,*) (A(j2,i2),j2=1,2)
	end do	
	
END SUBROUTINE Matriz_2

!##########################################################

SUBROUTINE Matriz_n(A,B,n)
	implicit none
	real:: esc
	integer :: n, i, j

	REAL, intent(out) :: A(n,n)
	REAL, intent(out) :: B(n,n)
	REAL :: C(n,n) !Soma de Matrizes
	REAL :: D(n,n) !Multiplicação de Matrizes
	REAL :: E(n,n) !Multiplicação por um Escalar
	
	Write(*,*)'Matriz [A]:'
	do i=1,n
		Write(*,*) (A(i,j),j=1,n)
	end do

	Write(*,*)
	Write(*,*)'Matriz [B]'
	do i=1,n
		Write(*,*) (B(i,j),j=1,n)
	end do


	Write(*,*)
	Write(*,*)'Matriz [C] = [A] + [B]'
	C = A + B
	do i=1,n
		Write(*,*) (C(i,j),j=1,n)
	end do

	Write(*,*) 
	Write(*,*)'-> Para Calcular Matriz [A] x Escalar, digite o valor do Escalar: '
	Read(*,*) esc

	Write(*,*) 
	print*,'Escalar Digitado:',esc

	Write(*,*) 
	Write(*,*)'Matriz [A] x Escalar'
	E = esc*A
	do i=1,n
		Write(*,*) (E(i,j),j=1,n)
	end do

	Write(*,*) 
	Write(*,*)'Matriz [D] = [A] x [B]'
	D = MATMUL(A,B)
	do i=1,n
		Write(*,*) (D(i,j),j=1,n)
	end do

	Write(*,*)
	Write(*,*)'Matriz [A] Transposta'
	do i=1,n
		Write(*,*) (A(j,i),j=1,n)
	end do	
	
END SUBROUTINE Matriz_n
	
end program




